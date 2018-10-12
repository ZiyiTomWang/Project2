//
//  rdp.c
//  Project2
//
//  Created by Junkang Gu on 10/10/18.
//  Copyright © 2018 Junkang Gu. All rights reserved.
//

#include "rdp.h"
#include <stdlib.h>


rdp new_rdp(char * input){
    rdp this=(rdp)malloc(sizeof(struct rdp));
    this->input=input;
    
    return this;
}

int lookahead(rdp this,char c){
    return *this->input==c;
}


int matchTerminal(rdp this, char c){
    if( *this->input==c){
        this->input++;
        return 1;
    }else{
        return 0;
    }
}



Node D(rdp rdp_parser){
    if(matchTerminal(rdp_parser, '0')){
        Node x=newNode('D');
        Node y[]={newNode('0')};
        Node_addChildren(x, y);
        return x;
    }else{
        if(matchTerminal(rdp_parser, '1')){
            Node x=newNode('D');
            Node y[]={newNode('1')};
            Node_addChildren(x, y);
            return x;
        }else{
            if(matchTerminal(rdp_parser, '2')){
                Node x=newNode('D');
                Node y[]={newNode('2')};
                Node_addChildren(x, y);
                return x;
            }else{
                if(matchTerminal(rdp_parser, '3')){
                    Node x=newNode('D');
                    Node y[]={newNode('3')};
                    Node_addChildren(x, y);
                    return x;
                }else{
                    if(matchTerminal(rdp_parser, '4')){
                        Node x=newNode('D');
                        Node y[]={newNode('4')};
                        Node_addChildren(x, y);
                        return x;
                    }else{
                        if(matchTerminal(rdp_parser, '5')){
                            Node x=newNode('D');
                            Node y[]={newNode('5')};
                            Node_addChildren(x, y);
                            return x;
                        }else{
                            if(matchTerminal(rdp_parser, '6')){
                                Node x=newNode('D');
                                Node y[]={newNode('6')};
                                Node_addChildren(x, y);
                                return x;
                            }else{
                                if(matchTerminal(rdp_parser, '7')){
                                    Node x=newNode('D');
                                    Node y[]={newNode('7')};
                                    Node_addChildren(x, y);
                                    return x;
                                }else{
                                    if(matchTerminal(rdp_parser, '8')){
                                        Node x=newNode('D');
                                        Node y[]={newNode('8')};
                                        Node_addChildren(x, y);
                                        return x;
                                    }else{
                                        if(matchTerminal(rdp_parser, '9')){
                                            Node x=newNode('D');
                                            Node y[]={newNode('9')};
                                            Node_addChildren(x, y);
                                            return x;
                                        }else return NULL;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

Node NT(rdp rdp_parser){
    if(!N(rdp_parser)){
        Node x=newNode('n');
        Node y[]={newNode('e')};
        Node_addChildren(x, y);
        return x;
    }else{
        Node yy=N(rdp_parser);
        if(yy==NULL)return NULL;
        Node x=newNode('n');
        Node y[]={yy};
        Node_addChildren(x, y);
        return x;
    }
}

Node N(rdp rdp_parser){
    Node yy=D(rdp_parser);
    if(yy==NULL)return NULL;
    Node yyy=NT(rdp_parser);
    if(yyy==NULL)return NULL;
    Node x=newNode('N');
    Node y[]={yy,yyy};
    Node_addChildren(x, y);
    return x;
}

Node F(rdp rdp_parser){
    if(matchTerminal(rdp_parser, '(')){
        Node yy =E(rdp_parser);
        if(yy==NULL)return NULL;
        if(!matchTerminal(rdp_parser, ')'))return NULL;
        Node x=newNode('F');
        Node xx=newNode('(');
        Node xxx=newNode(')');
        Node y[]={xx,yy,xxx};
        Node_addChildren(x, y);
        return x;
    }else{
        Node yy=N(rdp_parser);
        if(yy==NULL)return NULL;
        Node x=newNode('E');
        Node y[]={yy};
        Node_addChildren(x, y);
        return x;
    }
}


Node E(rdp rdp_parser){
    
    Node yy = T(rdp_parser);
    if(yy==NULL)return NULL;
    Node yyy = TT(rdp_parser);
    if(yyy==NULL)return NULL;
    Node x=newNode('N');
    Node y[]={yy,yyy};
    Node_addChildren(x, y);
    return x;
}

Node T(rdp rdp_parser){
    
    Node yy=F(rdp_parser);
    if(yy==NULL)return NULL;
    Node yyy = FT(rdp_parser);
    if(yyy==NULL)return NULL;
    Node x=newNode('N');
    Node y[]={yy,yyy};
    Node_addChildren(x, y);
    return x;
    
}

Node TT(rdp rdp_parser){
    
    if (matchTerminal(rdp_parser, '+')){
        Node yy = T(rdp_parser);
        if(yy==NULL)return NULL;
        Node yyy=TT(rdp_parser);
        if(yyy==NULL)return NULL;
        Node x=newNode('N');
        Node y[]={yy,yyy};
        Node_addChildren(x, y);
        return x;
        
        
    }else if (matchTerminal(rdp_parser, '-')){
        
        Node yy = T(rdp_parser);
        if(yy==NULL)return NULL;
        Node yyy=TT(rdp_parser);
        if(yyy==NULL)return NULL;
        Node x=newNode('N');
        Node y[]={yy,yyy};
        Node_addChildren(x, y);
        return x;
        
    } else {
        
        
    }
    
}


Node FT(rdp rdp_parser){
    
    if (matchTerminal(rdp_parser, '*')){
        Node yy = F(rdp_parser);
        if(yy==NULL)return NULL;
        Node yyy=FT(rdp_parser);
        if(yyy==NULL)return NULL;
        Node x=newNode('N');
        Node y[]={yy,yyy};
        Node_addChildren(x, y);
        return x;
        
        
    }else if (matchTerminal(rdp_parser, '/')){
        
        Node yy = F(rdp_parser);
        if(yy==NULL)return NULL;
        Node yyy=FT(rdp_parser);
        if(yyy==NULL)return NULL;
        Node x=newNode('N');
        Node y[]={yy,yyy};
        Node_addChildren(x, y);
        return x;
        
    }
}

