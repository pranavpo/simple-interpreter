#ifndef interpreter_h
#define interpreter_h
#include "stdlib.h"
#include "token.h"
Token* get_next_token(char string[]);
Token* eat(char type[],Token* token,char string[]);
void set_pos_zero();
#endif