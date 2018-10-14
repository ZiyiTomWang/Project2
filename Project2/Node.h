//
//  Node.h
//  Project2
//
//  Created by Junkang Gu on 10/10/18.
//  Copyright © 2018 Junkang Gu. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include <stdio.h>



typedef struct Node *Node;
struct Node{
    char element;
    Node* children;
    int childNum;
    Node parent;
    int depth;
    int nthChild;
};

void Node_addChildrenByString(Node this, char* children);

extern Node newNode(char c);

extern void Node_addChildren(Node node, Node* children, int numOfChildren);

extern void printTree(Node node);

extern Node findLeftMostNonterminalLeaf(Node node);

extern Node findNextSibling(Node node);

#endif /* Node_h */
