//
//  Stack.h
//  Project2
//
//  Created by Junkang Gu on 10/13/18.
//  Copyright © 2018 Junkang Gu. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <stdio.h>


typedef struct Stack *Stack;
struct Stack{
    char* arr;
    int size;
};

extern Stack newStack(void);

extern void pushChar(Stack stack,char c);

extern void pushString(Stack stack, char* s);

extern char pop(Stack stack);

extern void stack_Free(Stack this);
#endif /* Stack_h */
