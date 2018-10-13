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

void Node_addChildren(Node this, Node* children, int numOfChildren){
    int start=this->childNum;
    for(int i=start;i<start+numOfChildren;i++){
        this->children[i]=children[i-start];
        this -> childNum ++;
    }
}

// 
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
