#ifndef LEXER_H_
#define LEXER_H_

#include"global.h"
#include"symbol.h"
#include"error.h"
struct entry symbolTable[100];
char lexBuf[BSIZE];
 int lineno=1;
 int tokenval=NONE;

int lexan(){

    int t;

    while(1){
        t=getchar();
        if(t=='\t'||t=='\n');
        else if(t=='\n')
            lineno++;
        else if(isdigit(t)){
            ungetc(t,stdin);
            scanf("%d",&tokenval);
            return NUM;
        }
        else if (isalpha(t)){
            int p,b=0;
            while (isalnum(t)){
                lexBuf[b++]=t;
                t=getchar(); // for future
                if(b>=BSIZE){
                    error("Compiler error");
                }

            }
            lexBuf[b]=EOF;
            if(t!=EOF)
                ungetc(t,stdin);
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
