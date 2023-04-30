#ifndef LEXER_H_
#define LEXER_H_

#include"global.h"
#include"symbol.h"
#include"error.h"
extern struct entry symbolTable[];
int insert(char s[], int tok);
int lookup(char s[]);
void error(char* m);
extern FILE *input;

char lexBuf[BSIZE];
 int lineno=1;
 int tokenval=NONE;

int lexan(){

    int t;

    while(1){
        t=getc(input);
        if(t=='\t'||t==' ');
        else if(t=='\n')
            lineno++;
        else if(isdigit(t)){
            ungetc(t,input);
            fscanf(input,"%d",&tokenval);
            return NUM;
        }
        else if (isalpha(t)){
            int p,b=0;
            while (isalnum(t)){
                lexBuf[b++]=t;
                t=getc(input);//for future
                if(b>=BSIZE){
                    error("Compiler error");
                }

            }
            lexBuf[b]=EOS;
            if(t!=EOF)
                ungetc(t,input);
            p=lookup(lexBuf);
            if(p==0)
                p=insert(lexBuf,ID); // p is now last entry
            tokenval=p;
            return symbolTable[p].token;

        }
        else if(t==EOF)
            return DONE;
        else{
            tokenval=NONE;
            return t;
        }


    }
}

#endif
