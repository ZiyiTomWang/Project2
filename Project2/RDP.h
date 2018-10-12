//
//  rdp.h
//  Project2
//
//  Created by Junkang Gu on 10/10/18.
//  Copyright © 2018 Junkang Gu. All rights reserved.
//

#ifndef rdp_h
#define rdp_h

#include <stdio.h>
#include "Node.h"
typedef struct rdp *rdp;
struct rdp{
    char * input;
    Node root;
};

extern rdp new_rdp(char * input);

extern int lookahead(rdp this, char c);

extern int lookaheads(rdp this, char* c);

extern int matchTerminal(rdp this, char c);

extern int matchTerminals(rdp this, char* c);

extern Node E (rdp this);

extern Node T (rdp this);

extern Node TT (rdp this);

extern Node D(rdp this);

extern Node NT(rdp this);

extern Node N(rdp this);

extern Node F(rdp this);

extern Node FT(rdp this);


#endif /* rdp_h */
