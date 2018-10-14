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


typedef struct TDP *TDP;
struct TDP{
    char * input;
    Node root;
};

extern int tdp_lookahead(TDP tdp_parser,char c);

extern int tdp_matchTerminal(TDP this, char c);

extern TDP new_TDP(char * input);

extern Node execute(TDP tdp);

extern int tdp_findTerminal(char c);

extern int tdp_findNonTerminal(char c);

extern int tdp_lookahead2(TDP tdp);

extern char* production(int r, int c);

#endif /* TDP_h */
