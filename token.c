#include "token.h"
Token* createToken(int count, char value[50], char type[50]){
    // printf("creating token with string %s \n",value);
    Token *token;
    token = (Token *)malloc(sizeof(Token));
    token->count = count;
    token->value = value;
    token->type = type;
    return token;
}