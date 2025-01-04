#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"token.h"
#include"interpreter.h"

static int pos = 0;

void advance(){
    pos = pos + 1;
}

char* integer(char string[]){
    // make malloc dynamic; use another function
    char *character_arr = malloc (sizeof (char) * 50);
    int i = 0;
    while(isdigit(string[pos])){
        *(character_arr + i) = string[pos];
        ++i;
        advance();
    }
    *(character_arr + i) = '\0';
    return character_arr;
}

Token* get_next_token(char string[]){
    while(pos <= strlen(string)){
        int result = isspace(string[pos]);
        if(result != 0){
            advance(string);
            continue;
        }
        if(isdigit(string[pos]) != 0){
            char* character_arr = integer(string);
            // create a copy of character_arr using strdup; createToken does not depend on pointer created in char*integer
            Token* token = createToken(1,strdup(character_arr),"INTEGER");
            free(character_arr);
            return token;
        }else{
            char character_arr[2] = "\0";
            character_arr[0] = string[pos];
            Token * token;
            if(string[pos] == '+'){
                token = createToken(1,character_arr,"PLUS");
                // printf("token->type %s with value %s\n",token->type,token->value);
            }else if(string[pos] == '-'){
                token = createToken(1,character_arr,"MINUS");
            }else if(string[pos] == '*'){
                token = createToken(1,character_arr,"MULTIPLY");
            }else if(string[pos] == '/'){
                 token = createToken(1,character_arr,"DIVIDE");
            }else if(string[pos] == '('){
                token = createToken(1,character_arr,"LPAREN");
            }else if(string[pos] == ')'){
                token = createToken(1,character_arr,"RPAREN");
            }
            pos++;
            return token;
        }
    }
}

Token* eat(char type[],Token* token,char string[]){
    if(strcmp(token->type,type) == 0){
        printf("Consuming token->type: %s, token->value: %s\n", token->type, token->value);
        free(token);
        token = get_next_token(string);
        // printf("New token->type: %s, token->value: %s\n", token->type, token->value);
        return token;
    }
}

void set_pos_zero(){
    pos = 0;
}