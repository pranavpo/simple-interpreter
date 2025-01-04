#include<stdio.h>
#include "lexer.h"
#include<string.h>

double main(){
    while(1){
        char string[50];
        printf(">");
        fgets(string,50,stdin);
        double result = expr(string);
        printf("%f\n",result);
    }
}