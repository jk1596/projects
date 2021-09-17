#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char **argv){
    if(argc == 1){
        printf("...\n");
    }
    else {
        printf("(");
        for(int i = 1; i < argc; i++){
            char* string = argv[i];
            for(int i = 0; i < strlen(string); i++){
                if(isupper(string[i])){
                    printf("%c", tolower(string[i]));
                }
                else if(string[i] == '!'){
                    printf(".");
                }
                else {
                    printf("%c", string[i]);
                }
            }
            if(i + 1 != argc){
            printf(" ");
            }
        }
        printf(")\n");
    }
}