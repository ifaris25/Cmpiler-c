#ifndef PARSE_H_
#define PARSE_H_

#include "global.h"
#include"lexer.h"
#include"emitter.h"

void parse();
void expr();
void term();
void match(int);
void factor();
void stmt();
int lookahead;
extern FILE *output;


void stmt(){
	int temp = tokenval;
	match(ID);
	match('=');
	expr();
	fprintf(output,"pop %s",symbolTable[temp].lexptr);
}

void parse(){
		lookahead = lexan();
		stmt();
}

void expr(){
	int t;
	term();

	while(1)
	   switch (lookahead) {
	     case '+': case '-':
	        t = lookahead;
	        match(lookahead); term(); emit(t, NONE);
	       continue;
	    default:
	       return;
	}
}
void term()
{
	int t;
	factor();
	while(1)
	     switch (lookahead) {
	        case '*': case '/': case DIV: case MOD:
		t = lookahead;
		match(lookahead); factor(); emit(t, NONE);
		continue;
	         default:
		return;
	}
}
void factor(){
	switch (lookahead) {
	case '(':
		match ('('); expr(); match(')'); break;
	case NUM:
		emit(NUM, tokenval);
		match(NUM); break;
	case ID:
		emit(ID, tokenval);
		match(ID);
		break;
	default:
		error("syntax error");
	}
}

void match(t){

	if (lookahead == t)
		lookahead = lexan();
	else error ("syntax error");
}
#endif
