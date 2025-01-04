#ifndef token_h
#define token_h

#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int count;
    char* value;
    char* type;
} Token;

Token* createToken(int count, char* value, char* type);
void freeToken();

#endif