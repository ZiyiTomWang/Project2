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

#endif /* Node_h */

typedef struct Node *Node;
struct Node{
    char element;
    Node* children;
    Node parent;
    int depth;
};

extern Node newNode(char c);

extern void Node_addChildren(Node this, Node* children);
