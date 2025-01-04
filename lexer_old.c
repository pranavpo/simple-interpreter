#include"lexer.h"
#include"string.h"

char * token_type;

int checkifexists(char * operations[],size_t size,char * target){
    for(int i = 0; i<size;i++){
        if(strcmp(target,operations[i]) == 0){
            return 1;
        }
    }
    return 0;
}

double factor(char type[], Token * token, char string[]){
    char *string_number = token->value;
    char * stopstring;
    double value = strtod(string_number,&stopstring);
    eat(type,token,string);
    return value;
}

double term(char type[], Token *token,char string[]){
    double factor_result = factor(type, token, string);
    char * operations[] = {"MULTIPLY","DIVIDE"};
    token_type = token->type;
    size_t size = sizeof(operations)/sizeof(operations[0]);
    while(checkifexists(operations,size,token_type)){
        if(strcmp(token_type,"MULTIPLY") == 0){
            token = eat(token->type,token,string);
            token_type = token->type;
            double new_term = factor(token->type,token,string);
            factor_result = factor_result * new_term;
            token_type = token->type;
        }else if(strcmp(token_type,"DIVIDE") == 0){
            token = eat(token->type,token,string);
            token_type = token->type;
            double new_term = factor(token->type,token,string);
            factor_result = factor_result / new_term;
            token_type = token->type;
        }
    }
    return factor_result;
}

double expr(char string[]){
    Token* token = get_next_token(string);
    // printf("token->value is %s \n",token->value);
    token_type = token->type;
    double result = term(token->type,token,string);
    char * operations[] = {"PLUS","MINUS"};
    size_t size = sizeof(operations)/sizeof(operations[0]);
    while(checkifexists(operations,size,token_type)){
        if(strcmp(token_type,"PLUS") == 0){
            token = eat(token->type,token,string);
            token_type = token->type;
            double new_term = term(token->type,token,string);
            result = result + new_term;
        }
        if(strcmp(token_type,"MINUS") == 0){
            token = eat(token->type,token,string);
            token_type = token->type;
            double new_term = term(token->type,token,string);
            result = result - new_term;
        }
    }
    set_pos_zero();
    return result;
}