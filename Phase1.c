#include<stdio.h>
#include<ctype.h>
void expr();
void rest();
void match(int);
void error();
void term();
int lexan();
int linenumber=0;
int lookahed;

int main(void){

  lookahed = lexan();
  expr();
  putchar('\n'); 
}

void error(){
    printf("Syntax error...line:  %d\n",linenumber);
}

void expr(){
    term();
    rest();
}

void rest(){
  while(1){
    if(lookahed=='+'){
        match('+');
        term();
        putchar('+');
        // rest();

    }
    else if(lookahed=='-'){
        match('-');
        term();
        putchar('-');
        // rest();
    }
    else
        break;
  }
}

void match(int look){
    if(lookahed==look){
        lookahed=lexan();
    }
    else{
        error();
    }
}
void term(){
    if(isdigit(lookahed)){
        int temp = lookahed;
        match(lookahed);
        putchar(temp); 
    }
    else{
        error();
    }

}
int lexan(){
    int toxen;
    while(1){
        toxen=getchar();
        if(toxen==' '||toxen=='\t');
        else
        return toxen;

    }
}
