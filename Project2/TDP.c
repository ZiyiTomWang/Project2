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
    execute(this);
    return this;
}

int lookahead(TDP tdp_parser,char c){
    return *tdp_parser->input==c;
}

int lookahead2(TDP tdp){
    return *tdp->input;
}

int matchTerminal(TDP this, char c){
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
        /*E*/{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1,-1,-1,-1,1,-1,-1 },
        /*T*/{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, -1,-1, -1,-1,4,-1,-1},
        /*t*/{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1, 2, -1,-1,-1,-1,3},
        /*F*/{8, 8, 8, 8, 8, 8,8, 8, 8, 8, -1,-1,-1,-1,9,-1 , -1},
        /*f*/{-1,-1,-1, -1,-1,-1,-1,-1,-1,-1,-1,-1,5,6,-1,-1,7},
        /*N*/{10,10,10,10,10,10,10,10,10,10,-1,-1,-1,-1,-1,-1,-1},
        /*n*/{11,11,11,11,11,11,11,11,11,11,-1,-1,-1,-1,-1,-1,12},
        /*D*/{13,13,13,13,13,13,13,13,13,13,-1,-1,-1,-1,-1,-1,-1}
        
    };

int findNonTerminal(char c){
    for(int i=0;i<8;i++){
        if(nonTerminal[i]==c)return i;
    }
    return -1;
}

int findTerminal(char c){
    for(int i=0;i<17;i++){
        if(terminal[i]==c)return i;
    }
    return -1;
}

char* production(int r, int c){
    int id=table[r][c];
    if(id==-1){
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
        if(findTerminal(goal)!=-1){//is terminal, match and consume
            matchTerminal(tdp, goal);
        }else if(findNonTerminal(goal)!=-1){//is not a terminal
            char input=lookahead2(tdp);
            int r=findNonTerminal(goal);
            int c=findTerminal(input);
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


