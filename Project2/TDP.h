//
//  TDP.h
//  Project2
//
//  Created by Junkang Gu on 10/13/18.
//  Copyright © 2018 Junkang Gu. All rights reserved.
//

#ifndef TDP_h
#define TDP_h

#include <stdio.h>
#include "Node.h"
#endif /* TDP_h */

typedef struct TDP *TDP;
struct TDP{
    char * input;
    Node root;
};

extern int lookahead(TDP tdp_parser,char c);

extern int matchTerminal(TDP this, char c);

extern TDP new_TDP(char * input);

extern Node execute(TDP tdp);

extern int findTerminal(char c);

extern int findNonTerminal(char c);
