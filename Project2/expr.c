//
//  expr.c
//  Project2
//
//  Created by Junkang Gu on 10/9/18.
//  Copyright © 2018 Junkang Gu. All rights reserved.
//
//////
#include <stdio.h>
#include <string.h>
#include "RDP.h"
#include "TDP.h"
void removeNewLine(char* i);
void removeNewLine(char* i){
    long length=strlen(i);
    if(i[length-1]=='\n'){
        i[length-1]='\0';
    }
}
int main(int argc, const char * argv[]) {
    while(1){
        char str [256];
        printf("----------Enter an input (\"quit\" to quit): ");
        fgets(str,255,stdin);
        removeNewLine(str);
        if(strcmp(str,"quit")==0){
            return 0;
        }
        //input:str
        printf("\n-----Recursive-descent parser...\n");
        rdp RDP1 = new_rdp(str);
        if(RDP1->root==NULL){
            printf("Not a well-formed input\n");
        }
        else{

        printTree(RDP1->root);
        }
        printf("\n-----Table-driven parser...\n");
        TDP TDP1=new_TDP(str);
        if(TDP1->root==NULL){
            printf("Not a well-formed input\n");
        }
        else{
            printTree(TDP1->root);
        }
        printf("\n-----Evaluating the parse tree...\n");
        if(RDP1->root==NULL) printf("Not a well-formed input\n\n\n");
        else printf("%f\n\n\n",evaluate(RDP1->root));
    }
}
