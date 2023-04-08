#include "global.h"
#include"init.h"
#include"parse.h"
FILE * input;
FILE * output;
FILE * err;
int main(void){
    input = fopen("file.exp" , "r");
	output = fopen("file.obj" , "w");
    if (input == NULL){
		printf("the file doesn't exist");
	}
    
    init();
    parse();
    exit(0);

}
