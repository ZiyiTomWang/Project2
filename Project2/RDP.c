//
//  rdp.c
//  Project2
//
//  Created by Junkang Gu on 10/10/18.
//  Copyright © 2018 Junkang Gu. All rights reserved.
//
/////
#include "RDP.h"
#include <stdlib.h>


rdp new_rdp(char * input){
    rdp this=(rdp)malloc(sizeof(struct rdp));
    this->input=input;
    this->root=E(this);
    return this;
}

int lookahead(rdp rdp_parser,char c){
    return *rdp_parser->input==c;
}

int lookahead2(rdp rdp_parser){
    return *rdp_parser -> input;
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
    
    

    switch (lookahead2(rdp_parser)) {
        case '0':
            matchTerminal(rdp_parser, '0');
            Node x=newNode('D');
            Node y[]={newNode('0')};
            Node_addChildren(x, y,1);
            return x;
            
        case '1':
            matchTerminal(rdp_parser, '1');
            Node x1=newNode('D');
            Node y1[]={newNode('1')};
            Node_addChildren(x1, y1,1);
            return x1;
        case '2':
            matchTerminal(rdp_parser, '2');
            Node x2=newNode('D');
            Node y2[]={newNode('2')};
            Node_addChildren(x2, y2,1);
            return x2;
            
        case '3':
            matchTerminal(rdp_parser, '3');
            Node x3=newNode('D');
            Node y3[]={newNode('3')};
            Node_addChildren(x3, y3,1);
            return x3;
            
        case '4':
            matchTerminal(rdp_parser, '4');
            Node x4=newNode('D');
            Node y4[]={newNode('4')};
            Node_addChildren(x4, y4,1);
            return x4;
            
            
        case '5':
            matchTerminal(rdp_parser, '5');
            Node x5=newNode('D');
            Node y5[]={newNode('5')};
            Node_addChildren(x5, y5,1);
            return x5;
            
            
        case '6':
            matchTerminal(rdp_parser, '6');
            Node x6=newNode('D');
            Node y6[]={newNode('6')};
            Node_addChildren(x6, y6,1);
            return x6;
            
        case '7':
            matchTerminal(rdp_parser, '7');
            Node x7=newNode('D');
            Node y7[]={newNode('7')};
            Node_addChildren(x7, y7,1);
            return x7;
            
        case '8':
            matchTerminal(rdp_parser, '8');
            Node x8=newNode('D');
            Node y8[]={newNode('8')};
            Node_addChildren(x8, y8,1);
            return x8;
            
        case '9':
            matchTerminal(rdp_parser, '9');
            Node x9=newNode('D');
            Node y9[]={newNode('9')};
            Node_addChildren(x9, y9,1);
            return x9;
            
            break;
            
        default:
            return NULL;
            break;
    }
    
//    if(matchTerminal(rdp_parser, '0')){
//        Node x=newNode('D');
//        Node y[]={newNode('0')};
//        Node_addChildren(x, y);
//        return x;
//    }else{
//        if(matchTerminal(rdp_parser, '1')){
//            Node x=newNode('D');
//            Node y[]={newNode('1')};
//            Node_addChildren(x, y);
//            return x;
//        }else{
//            if(matchTerminal(rdp_parser, '2')){
//                Node x=newNode('D');
//                Node y[]={newNode('2')};
//                Node_addChildren(x, y);
//                return x;
//            }else{
//                if(matchTerminal(rdp_parser, '3')){
//                    Node x=newNode('D');
//                    Node y[]={newNode('3')};
//                    Node_addChildren(x, y);
//                    return x;
//                }else{
//                    if(matchTerminal(rdp_parser, '4')){
//                        Node x=newNode('D');
//                        Node y[]={newNode('4')};
//                        Node_addChildren(x, y);
//                        return x;
//                    }else{
//                        if(matchTerminal(rdp_parser, '5')){
//                            Node x=newNode('D');
//                            Node y[]={newNode('5')};
//                            Node_addChildren(x, y);
//                            return x;
//                        }else{
//                            if(matchTerminal(rdp_parser, '6')){
//                                Node x=newNode('D');
//                                Node y[]={newNode('6')};
//                                Node_addChildren(x, y);
//                                return x;
//                            }else{
//                                if(matchTerminal(rdp_parser, '7')){
//                                    Node x=newNode('D');
//                                    Node y[]={newNode('7')};
//                                    Node_addChildren(x, y);
//                                    return x;
//                                }else{
//                                    if(matchTerminal(rdp_parser, '8')){
//                                        Node x=newNode('D');
//                                        Node y[]={newNode('8')};
//                                        Node_addChildren(x, y);
//                                        return x;
//                                    }else{
//                                        if(matchTerminal(rdp_parser, '9')){
//                                            Node x=newNode('D');
//                                            Node y[]={newNode('9')};
//                                            Node_addChildren(x, y);
//                                            return x;
//                                        }else return NULL;
//                                    }
//                                }
//                            }
//                        }
//                    }
//                }
//            }
//        }
//    }
}

Node NT(rdp rdp_parser){
    if(!N(rdp_parser)){
        Node x=newNode('n');
        Node y[]={newNode('e')};
        Node_addChildren(x, y,1);
        return x;
    }else{
        Node yy=N(rdp_parser);
        if(yy==NULL)return NULL;
        Node x=newNode('n');
        Node y[]={yy};
        Node_addChildren(x, y,1);
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
    Node_addChildren(x, y,2);
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
        Node_addChildren(x, y,3);
        return x;
    }else{
        Node yy=N(rdp_parser);
        if(yy==NULL)return NULL;
        Node x=newNode('F');
        Node y[]={yy};
        Node_addChildren(x, y,1);
        return x;
    }
}


Node E(rdp rdp_parser){
    
    Node yy = T(rdp_parser);
    if(yy==NULL)return NULL;
    Node yyy = TT(rdp_parser);
    if(yyy==NULL)return NULL;
    Node x=newNode('E');
    Node y[]={yy,yyy};
    Node_addChildren(x, y,2);
    return x;
}

Node T(rdp rdp_parser){
    
    Node yy=F(rdp_parser);
    if(yy==NULL)return NULL;
    Node yyy = FT(rdp_parser);
    if(yyy==NULL)return NULL;
    Node x=newNode('T');
    Node y[]={yy,yyy};
    Node_addChildren(x, y,2);
    return x;
    
}

Node TT(rdp rdp_parser){
    
    if (matchTerminal(rdp_parser, '+')){
        Node yy = T(rdp_parser);
        if(yy==NULL)return NULL;
        Node yyy=TT(rdp_parser);
        if(yyy==NULL)return NULL;
        Node x=newNode('t');
        Node y[]={yy,yyy};
        Node_addChildren(x, y,2);
        return x;
        
        
    }else if (matchTerminal(rdp_parser, '-')){
        
        Node yy = T(rdp_parser);
        if(yy==NULL)return NULL;
        Node yyy=TT(rdp_parser);
        if(yyy==NULL)return NULL;
        Node x=newNode('t');
        Node y[]={yy,yyy};
        Node_addChildren(x, y,2);
        return x;
        
    } else {
     
        Node e = newNode('e');
        
        
        return e;
    }
    
}


Node FT(rdp rdp_parser){
    
    if (matchTerminal(rdp_parser, '*')){
        Node yy = F(rdp_parser);
        if(yy==NULL)return NULL;
        Node yyy=FT(rdp_parser);
        if(yyy==NULL)return NULL;
        Node x=newNode('f');
        Node y[]={yy,yyy};
        Node_addChildren(x, y,2);
        return x;
        
        
    }else if (matchTerminal(rdp_parser, '/')){
        
        Node yy = F(rdp_parser);
        if(yy==NULL)return NULL;
        Node yyy=FT(rdp_parser);
        if(yyy==NULL)return NULL;
        Node x=newNode('f');
        Node y[]={yy,yyy};
        Node_addChildren(x, y,2);
        return x;
        
    }else {
        
        Node e = newNode('e');
        return e;
        
    }
}

