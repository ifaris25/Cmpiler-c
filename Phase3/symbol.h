#ifndef SYMBOL_H_
#define SYMBOL_H_

#include"global.h"
#include"error.h"

#define STRMAX 999
#define SYMAX 100
char lexems[STRMAX];
int lastChar= -1;

extern struct entry symbolTable[100];
int lastEntry=0;


int lookup(char s[]){
    int p;
    for(p=lastEntry;p>0;p--){
        if(strcmp(symbolTable[p].lexptr,s)==0)
            return p;
    }
    return 0;
}

int insert(char s[], int tok){
    int length;
    length=strlen(s);

    if(lastEntry+1>=SYMAX){
        error("symbol table full");
    }
    if((lastChar+length+1)>=STRMAX){
        error("lexemes array full");
    }
    
    lastEntry++;
    symbolTable[lastEntry].token=tok;
    symbolTable[lastEntry].lexptr=&lexems[lastChar+1];

    strcpy(symbolTable[lastEntry].lexptr,s);

    return lastEntry;



}
#endif