#include<stdio.h>
#include<ctype.h>
#define NUM 256 
int linenumber=0;
int lookahed;
int numval;
  
void expr();
void rest();
void match(int);
void error();
void term();
int lexan();

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
        

    }
    else if(lookahed=='-'){
        match('-');
        term();
        putchar('-');
        
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
    match(NUM);
    printf("%d",numval);

}
int lexan(){
     int toxen;
    
    while (1) {
        toxen = getchar();
        if ((toxen == ' ' )|| (toxen == '\t')); // Ignore whitespace
            
        else if (toxen == '\n') {
            linenumber++;
        }
           
        else if(isdigit(toxen))
          {
             ungetc(toxen,stdin);
             scanf("%d", &numval);
             return NUM;
           }

        else
        return toxen;
        

    }
}
