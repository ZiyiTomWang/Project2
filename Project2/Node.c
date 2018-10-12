//
//  Node.c
//  Project2
//
//  Created by Junkang Gu on 10/10/18.
//  Copyright © 2018 Junkang Gu. All rights reserved.
//

#include "Node.h"
#include <stdlib.h>

Node newNode(char c){
    Node this=(Node) malloc(sizeof(struct Node));
    this->element=c;
    this -> childNum = 0;
    this->children=(Node*)malloc(sizeof(Node));
    for(int i=0; i<20;i++){
        this->children[i]=(Node)malloc(sizeof(Node));
    }
    this->depth=0;
    
    return this;
}

void Node_addChildren(Node this, Node* children){
    Node *i;
    int k=0;
    for(i=children;*i;i++){
        this->children[k]=*i;
        this -> childNum ++;
        k++;
    }
}

// 
void printTree(Node node){
    
    printf(" %c", node -> element);
    
    if ( node -> childNum == 0){
        //
    }else {
        for (int i = 0; i < node -> childNum; i++){
            printTree(node -> children[i]);
        }
    }
    
}
