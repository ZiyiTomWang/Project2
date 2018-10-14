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
    this->nthChild=-1;
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
    if(nthChild>=node->parent->childNum){//no more siblings
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
        
        if(findNonTerminal(node->element)!=-1){//is nonterminal
            return node;
        }else{//is terminal
            Node sibling=findNextSibling(node);
            if(sibling!=NULL){//found a sibling
                return findLeftMostNonterminalLeaf(sibling);
            }else{//no more siblings
                Node parentSibling=findNextSibling(node->parent);
                if(parentSibling==NULL)return NULL;
                else{
                    return findLeftMostNonterminalLeaf(parentSibling);
                }
            }
        }
        
    }
    return NULL;
}
