#ifndef PARSE_H_
#define PARSE_H_

#include "global.h"
#include"lexer.h"
#include"emitter.h"

void parse();
void expr();
void term();
void match(int);
void moreTerms();
void factor();
void moreFactor();
int lookahead;
void parse(){
    lookahead=lexan();
    while(lookahead!=DONE){
        expr();
        match(';');
    }
}
void expr(){
    term();
    moreTerms();
}
void moreTerms(){
    int t;
    switch(lookahead){
    
    case '+':
    case '-': t=lookahead; match(lookahead);term();emit(t,NONE);break;
    default: return;          

    }

}
void term(){
    factor();
    moreFactor();
}
void moreFactor(){
    int t;
    switch(lookahead){
        case'*':
        case'/': 
        case DIV: 
        case MOD:  t=lookahead; match(lookahead);factor();emit(t,NONE);moreFactor(); break;
        default: return;
    }
}
void factor(){
    switch(lookahead){
        case'(': match('(');expr();match(')');break;
        case ID: emit(ID,tokenval); match(ID);break;
        case NUM:emit(NUM,tokenval); match(NUM);break;
        default: return;
    }

}
void match(int t){
    if(lookahead==t)
        lookahead=lexan();
    else
        error("Sytnax error");
}
#endif