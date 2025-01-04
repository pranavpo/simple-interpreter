#ifndef lexer_h
#define lexer_h
#include"interpreter.h"
#include"token.h"

double expr(char string[]);
// double parent_expr(Token * token,char * string[]);
int checkifexists(char * operations[],size_t size,char * target);
double term(char type[],Token * token,char string[]);

#endif