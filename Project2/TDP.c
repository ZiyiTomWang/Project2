//
//  TDP.c
//  Project2
//
//  Created by Junkang Gu on 10/13/18.
//  Copyright © 2018 Junkang Gu. All rights reserved.
//

#include "TDP.h"
#include <stdlib.h>
#include "Node.h"
#include "Stack.h"
TDP new_TDP(char * input){
    TDP this=(TDP)malloc(sizeof(struct TDP));
    this->input=input;
    this->root=newNode('E');
    this->root=execute(this);
    return this;
}

int tdp_lookahead(TDP tdp_parser,char c){
    return *tdp_parser->input==c;
}

int tdp_lookahead2(TDP tdp){
    return *tdp->input;
}

int tdp_matchTerminal(TDP this, char c){
    if( *this->input==c){
        this->input++;
        return 1;
    }else{
        return 0;
    }
}

char nonTerminal[]={'E','T','t','F','f','N','n','D'};
char terminal[]={'0','1','2','3','4','5','6','7','8','9','+','-','*','/','(',')','e'};
char productionLeft[]={'E','t','t','t','T','f','f','f','F','F','N','n','n','D','D','D','D','D','D','D','D','D','D'};
char* productionRight[]={"Tt","+Tt","-Tt","e","Ff","*Ff","/Ff","e","N","(E)","Dn","N","e","0","1","2","3","4","5","6","7","8","9"};
int table[8][17] = {
            //0, 1, 2, 3, 4, 5, 6, 7, 8, 9, +, -, *, /, (, ), e
        /*E*/{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1,-1,-1,-1,0,0,0},
        /*T*/{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, -1,-1, -1,-1,4,-1,-1},
        /*t*/{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1, 2, -1,-1,-1,-1,3},
        /*F*/{8, 8, 8, 8, 8, 8,8, 8, 8, 8, -1,-1,-1,-1,9,-1,-1},
        /*f*/{-1,-1,-1, -1,-1,-1,-1,-1,-1,-1,-1,-1,5,6,-1,-1,7},
        /*N*/{10,10,10,10,10,10,10,10,10,10,-1,-1,-1,-1,-1,-1,-1},
        /*n*/{11,11,11,11,11,11,11,11,11,11,-1,-1,-1,-1,-1,-1,12 },
        /*D*/{13,14,15,16,17,18,19,20,21,22,-1,-1,-1,-1,-1,-1,-1}
        
    };

int tdp_findNonTerminal(char c){
    for(int i=0;i<8;i++){
        if(nonTerminal[i]==c)return i;
    }
    return -1;
}

int tdp_findTerminal(char c){
    for(int i=0;i<17;i++){
        if(terminal[i]==c)return i;
    }
    return -1;
}

char* production(int r, int c){
    int id=table[r][c];
    if(id==-1){
        id=table[r][16];
        if(id==-1)
        return NULL;
    }
    return productionRight[id];
}

Node execute(TDP tdp){
    Stack stack=newStack();
    pushChar(stack, 'E');
    tdp->root=newNode('E');
    
    while(stack->size!=0){
        char goal=pop(stack);
        if(tdp_findTerminal(goal)!=-1){//is terminal, match and consume
            
            tdp_matchTerminal(tdp, goal);
            
        }else if(tdp_findNonTerminal(goal)!=-1){//is not a terminal
            
            char input=tdp_lookahead2(tdp);//lookahead
            int r=tdp_findNonTerminal(goal);//
            int c=tdp_findTerminal(input);
            if(c==-1) c=16;//e
            char* produc=production(r, c);
            if(produc==NULL)return NULL;
            pushString(stack, produc);
            Node leaf=findLeftMostNonterminalLeaf(tdp->root);
            Node_addChildrenByString(leaf, produc);
            
        }else{
            return NULL;
        }
    }
    return tdp->root;
}

void free_TDP(TDP this){
    free(this);
}

