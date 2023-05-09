#define _CRT_SECURE_NO_WARNINGS
#include "global.h"
#include"init.h"
#include"parse.h"
FILE * input;
FILE * output;
FILE * err;
int main(void){
    input = fopen("D:\\COC\\Level 9\\Compiler design\\Project\\Code\\Phase4\\inputFile.exp" , "r");
	output = fopen("D:\\COC\\Level 9\\Compiler design\\Project\\Code\\Phase4\\outputFile.obj" , "w");
	err = fopen("D:\\COC\\Level 9\\Compiler design\\Project\\Code\\Phase4\\errorFileile.err" , "w");
    if (input == NULL){
		printf("the file doesn't exist");
	}
    else{
    init();
    parse();
    exit(0);
    }

}

