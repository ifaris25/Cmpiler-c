#include "global.h"
#include"init.h"
#include"parse.h"
FILE * input;
FILE * output;
FILE * err;
int main(void){
    input = fopen("inputFile.exp" , "r");
	output = fopen("outputFile.obj" , "w");
	err = fopen("errorFileile.err" , "w");
    if (input == NULL){
		printf("the file doesn't exist");
	}

    init();
    parse();
    exit(0);

}
