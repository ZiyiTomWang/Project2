//
//  rdp.h
//  Project2
//
//  Created by Junkang Gu on 10/10/18.
//  Copyright © 2018 Junkang Gu. All rights reserved.
//

#ifndef RDH_h
#define RDH_h

#include <stdio.h>
#include "Node.h"
typedef struct rdp *rdp;
struct rdp{
    char * input;
    Node root;
};

extern rdp new_rdp(char * input);

extern int lookahead(rdp this, char c);

extern char lookahead2(rdp rdp_parser);

extern int matchTerminal(rdp this, char c);

extern int matchTerminals(rdp this, char* c);

extern Node E (rdp rdp_parser);

extern Node T (rdp rdp_parser);

extern Node TT (rdp rdp_parser);

extern Node D(rdp rdp_parser);

extern Node NT(rdp rdp_parser);

extern Node N(rdp rdp_parser);

extern Node F(rdp rdp_parser);

extern Node FT(rdp rdp_parser);


#endif /* rdp_h */
