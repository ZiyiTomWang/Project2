//
//  Node.c
//  Project2
//
//  Created by Junkang Gu on 10/10/18.
//  Copyright © 2018 Junkang Gu. All rights reserved.
//

#include "Node.h"
#include <stdlib.h>
#include "TDP.h"
#include "Stack.h"

Node newNode(char c){
    Node this=(Node) malloc(sizeof(struct Node));
    this->element=c;
    this -> childNum = 0;
    this->children=(Node*)malloc(sizeof(Node));
    for(int i=0; i<20;i++){
        this->children[i]=(Node)malloc(sizeof(Node));
    }
    this->depth=0;
    this->parent=NULL;
    this->nthChild=0;
    return this;
}

void Node_addChildren(Node this, Node* children, int numOfChildren){
    int start=this->childNum;
    for(int i=start;i<start+numOfChildren;i++){
        this->children[i]=children[i-start];
        this->children[i]->parent=this;
        this->children[i]->nthChild=i;
        this -> childNum ++;
    }
}

void Node_addChildrenByString(Node this, char* children){
    char *i;
    for (i=children; *i; i++) {
        Node child=newNode(*i);
        Node array[]={child};
        Node_addChildren(this, array, 1);
    }
}
void printTree(Node node){
    int name=(int)node->element;
    if(name>=0||name<=256){
        
    for(int i=0; i<node->depth;i++){
        printf("  ");
    }
    printf("%c\n", node -> element);
    
    if ( node -> childNum == 0){
        //
    }else {
        for (int i = 0; i < node -> childNum; i++){
            node->children[i]->depth=node->depth+1;
            printTree(node -> children[i]);
        }
    }
        
    }
}

Node findNextSibling(Node node){

    int nthChild=node->nthChild;
    if(nthChild>=node->parent->childNum-1){//no more siblings
        return NULL;
    }else{
        return node->parent->children[nthChild+1];
    }
}

Node findLeftMostNonterminalLeaf(Node node){
    if(node==NULL)return NULL;
    
    if(node->childNum!=0)//is not a leaf
        return findLeftMostNonterminalLeaf(node->children[0]);
    
    if(node->childNum==0){//is leaf
        
        if(tdp_findNonTerminal(node->element)!=-1){//is nonterminal
            return node;
        }else{//is terminal
            Node sibling=findNextSibling(node);
            
            if(sibling!=NULL){//found a sibling
                return findLeftMostNonterminalLeaf(sibling);
                
            }else{//no more siblings
                Node pointer=node->parent;
                    while(findNextSibling(pointer)==NULL){
                        pointer=pointer->parent;
                    }
                    return findLeftMostNonterminalLeaf(findNextSibling(pointer));
            }
        }
        
    }
    return NULL;
}

char beginWith(Node node){
    if(node->childNum==0)return 'X';
    else
    return node->children[0]->element;
}

double evaluate(Node node){
    
    Stack calcStack = newStack();

    switch(node->element){
        
        case 'E':{// T TT
            Node T=node->children[0];
            Node TT=node->children[1];
            char c=beginWith(TT);
            switch(c){
                case '+': pushChar(calcStack, '+');
                    return evaluate(T)+evaluate(TT);
                    
                    break;
                case '-': pushChar(calcStack, '-');
                    return evaluate(T)-evaluate(TT);
                    
                    break;
                default: return evaluate(T);break;
            }
        }
        break;
        case 't':{//+-T TT
            Node T=node->children[1];
            Node TT=node->children[2];
            char c=beginWith(TT);
            switch(c){
                case '+':
                    pushChar(calcStack, '+');
                    return evaluate(T)+evaluate(TT);break;
                case '-':
                    pushChar(calcStack, '-');
                    return evaluate(T)-evaluate(TT);break;
                default: return evaluate(T);break;
            }
        }
        break;
        case 'T':{//F FT
            Node F=node->children[0];
            Node FT=node->children[1];
            char c=beginWith(FT);
            switch(c){
                case '*':
                    pushChar(calcStack, '*');
                    return evaluate(F)*evaluate(FT);break;
                case '/':
                    pushChar(calcStack, '/');
                    return evaluate(F)/evaluate(FT);break;
                default: return evaluate(F);break;
            }
        }
        break;
        case 'f':{//*/F FT
            Node F=node->children[1];
            Node FT=node->children[2];
            char c=beginWith(FT);
            switch(c){
                case '*':
                    pushChar(calcStack, '*');
                    return evaluate(F)*evaluate(FT);break;
                case '/':
                    pushChar(calcStack, '/');
                    return evaluate(F)/evaluate(FT);break;
                default: return evaluate(F);break;
            }
        }
        break;
        case 'F':{// N | (E)
            char c=beginWith(node);
            if(c=='('){
                return evaluate(node->children[1]);
            }else{
                return evaluate(node->children[0]);
            }
        }
        break;
        case 'N':{// D NT
            Node D=node->children[0];
            Node NT=node->children[1];
            
           
            
            if(beginWith(NT)=='e'){
                return evaluate(D);
            }else{
                int compare=1;
                double nt=evaluate(NT);
                // printf("%s%c", "nt:", nt);
                while(compare<=nt){
                    
                    compare*=10;
                    
                    
                }
                return compare*evaluate(D)+evaluate(NT);
            }
        }
        break;
        case 'n':{// N|e
            return evaluate(node->children[0]);
        }
        break;
        case 'D':{
            char x=node->children[0]->element;
            switch (x) {
                case '0':
                    pushChar(calcStack, '0');
                    return 0;break;
                case '1':
                    pushChar(calcStack, '1');
                    return 1;break;
                case '2':
                    pushChar(calcStack, '2');
                    return 2;break;
                case '3':
                    pushChar(calcStack, '3');
                    return 3;break;
                case '4':
                    pushChar(calcStack, '4');
                    return 4;break;
                case '5':
                    pushChar(calcStack, '5');
                    return 5;break;
                case '6':
                    pushChar(calcStack, '6');
                    return 6;break;
                case '7':
                    pushChar(calcStack, '7');
                    return 7;break;
                case '8':
                    pushChar(calcStack, '8');
                    return 8;break;
                case '9':
                    pushChar(calcStack, '9');
                    return 9;break;
                
                default:
                break;
            }
        }
        default:
        break;
    }
    
    
    // Stack stack2 = newStack();
    
    
    while (calcStack -> size != 1){
        
        char *storeVal =  " ";
        
        char k = pop(calcStack);
        if ( k!= '+' && k != '-' && k != '*' && k != '/'){
            
            storeVal += k;
        } else {
            // pushChar(stack2, storeVal);
            
            // storeVal == NULL;
        }
        
        
        
    }
    
    
    
    return 0;
}


