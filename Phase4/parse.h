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
void CS();
int lookahead;
extern FILE *output;

void parse(){
		lookahead = lexan();
		stmt();
		match(DONE);
}


void stmt(){
	int temp = tokenval;
	switch (lookahead){
	
		case ID: match(ID);
				match('=');
				expr();
				fprintf(output,"pop %s\n",symbolTable[temp].lexptr);
				break;
		case IF:
				 match(IF); 
				 match('(');
				 expr();
				 match(')');
				 fprintf(output,"pop r2\ncmp r2,0\nbe else\n");
				 match(THEN);
				 stmt();
				 fprintf(output,"else:\n");
				 break;
		
		case WHILE:
					match(WHILE);
					fprintf(output,"while\n");
					match('(');
					expr();
					match(')');
					fprintf(output,"pop r2\ncmp r2,0\nbe endwhile\n");
					match(DO);
					stmt();
					fprintf(output,"b while\nendwhile\n");
					break;

		case BEGIN:
					match(BEGIN);
					CS();
					match(END);
					break;
		default:error("Syntax error\n");



	
	
	}
}

void CS(){
    while(lookahead != END){
        stmt();match(';');
    }

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
