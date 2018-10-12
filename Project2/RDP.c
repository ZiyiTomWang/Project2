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



Node D(rdp this){
    if(matchTerminal(this, '0')){
        Node x=newNode('D');
        Node y[]={newNode('0')};
        Node_addChildren(x, y);
        return x;
    }else{
        if(matchTerminal(this, '1')){
            Node x=newNode('D');
            Node y[]={newNode('1')};
            Node_addChildren(x, y);
            return x;
        }else{
            if(matchTerminal(this, '2')){
                Node x=newNode('D');
                Node y[]={newNode('2')};
                Node_addChildren(x, y);
                return x;
            }else{
                if(matchTerminal(this, '3')){
                    Node x=newNode('D');
                    Node y[]={newNode('3')};
                    Node_addChildren(x, y);
                    return x;
                }else{
                    if(matchTerminal(this, '4')){
                        Node x=newNode('D');
                        Node y[]={newNode('4')};
                        Node_addChildren(x, y);
                        return x;
                    }else{
                        if(matchTerminal(this, '5')){
                            Node x=newNode('D');
                            Node y[]={newNode('5')};
                            Node_addChildren(x, y);
                            return x;
                        }else{
                            if(matchTerminal(this, '6')){
                                Node x=newNode('D');
                                Node y[]={newNode('6')};
                                Node_addChildren(x, y);
                                return x;
                            }else{
                                if(matchTerminal(this, '7')){
                                    Node x=newNode('D');
                                    Node y[]={newNode('7')};
                                    Node_addChildren(x, y);
                                    return x;
                                }else{
                                    if(matchTerminal(this, '8')){
                                        Node x=newNode('D');
                                        Node y[]={newNode('8')};
                                        Node_addChildren(x, y);
                                        return x;
                                    }else{
                                        if(matchTerminal(this, '9')){
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

Node NT(rdp this){
    if(!N(this)){
        Node x=newNode('n');
        Node y[]={newNode('e')};
        Node_addChildren(x, y);
        return x;
    }else{
        Node yy=N(this);
        if(yy==NULL)return NULL;
        Node x=newNode('n');
        Node y[]={yy};
        Node_addChildren(x, y);
        return x;
    }
}

Node N(rdp this){
    Node yy=D(this);
    if(yy==NULL)return NULL;
    Node yyy=NT(this);
    if(yyy==NULL)return NULL;
    Node x=newNode('N');
    Node y[]={yy,yyy};
    Node_addChildren(x, y);
    return x;
}

Node F(rdp this){
    if(matchTerminal(this, '(')){
        Node yy =E(this);
        if(yy==NULL)return NULL;
        if(!matchTerminal(this, ')'))return NULL;
        Node x=newNode('F');
        Node xx=newNode('(');
        Node xxx=newNode(')');
        Node y[]={xx,yy,xxx};
        Node_addChildren(x, y);
        return x;
    }else{
        Node yy=N(this);
        if(yy==NULL)return NULL;
        Node x=newNode('E');
        Node y[]={yy};
        Node_addChildren(x, y);
        return x;
    }
}


Node E(rdp this){
    
    Node yy = T(this);
    if(yy==NULL)return NULL;
    Node yyy = TT(this);
    if(yyy==NULL)return NULL;
    Node x=newNode('N');
    Node y[]={yy,yyy};
    Node_addChildren(x, y);
    return x;
}

Node T(rdp this){
    
    Node yy=F(this);
    if(yy==NULL)return NULL;
    Node yyy = FT(this);
    if(yyy==NULL)return NULL;
    Node x=newNode('N');
    Node y[]={yy,yyy};
    Node_addChildren(x, y);
    return x;
    
}

Node TT(rdp this){
    
    if (matchTerminal(this, '+')){
        Node yy = T(this);
        if(yy==NULL)return NULL;
        Node yyy=TT(this);
        if(yyy==NULL)return NULL;
        Node x=newNode('N');
        Node y[]={yy,yyy};
        Node_addChildren(x, y);
        return x;
        
        
    }else if (matchTerminal(this, '-')){
        
        Node yy = T(this);
        if(yy==NULL)return NULL;
        Node yyy=TT(this);
        if(yyy==NULL)return NULL;
        Node x=newNode('N');
        Node y[]={yy,yyy};
        Node_addChildren(x, y);
        return x;
        
    } else {
        
        
    }
    
}


Node FT(rdp parser){
    
    if (matchTerminal(this, '*')){
        Node yy = F(this);
        if(yy==NULL)return NULL;
        Node yyy=FT(this);
        if(yyy==NULL)return NULL;
        Node x=newNode('N');
        Node y[]={yy,yyy};
        Node_addChildren(x, y);
        return x;
        
        
    }else if (matchTerminal(this, '/')){
        
        Node yy = F(this);
        if(yy==NULL)return NULL;
        Node yyy=FT(this);
        if(yyy==NULL)return NULL;
        Node x=newNode('N');
        Node y[]={yy,yyy};
        Node_addChildren(x, y);
        return x;
        
    }
}

