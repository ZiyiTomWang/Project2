//
//  Stack.c
//  Project2
//
//  Created by Junkang Gu on 10/13/18.
//  Copyright © 2018 Junkang Gu. All rights reserved.
//

#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack newStack(void){
    Stack this=(Stack) malloc(sizeof(struct Stack));
    this->arr=(char*)malloc(sizeof(char));
    this->size=0;
    return this;
}

void pushChar(Stack stack,char c){
    stack->arr[stack->size]=c;
    stack->size++;
}

void pushString(Stack stack, char* s){
    char *i;
    Stack temp=newStack();
    for (i=s; *i; i++) {
        pushChar(temp, *i);
    }
    while(temp->size!=0){
        char tempChar=pop(temp);
        pushChar(stack,tempChar);
    }
}

char pop(Stack stack){
    stack->size--;
    return stack->arr[stack->size];
}
