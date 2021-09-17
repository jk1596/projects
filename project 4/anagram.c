#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char **argv){
    if(argc > 2){
        return 0;
    }
    else {
        char* string1 = argv[1];
        char t;

        char y;
        char string[128];
        int q = 0;
        // removing numbers first
        for(int i = 0; i < strlen(string1); i++){
            y = string1[i];
            if((y < '0') || (y > '9') || (y == ' ')){
                string[q++] = y;
            }
        }
        string[q] = '\0';

        // removing spaces now
        int i = 0;
        int j = 0;
        while(string[i]!='\0'){ 
            if(string[i] !=' '){
            string[j++] = string[i];
            }
        i++;
        }

        string[j]='\0';

        // Now sorting
        
        for(int i = 0; i < strlen(string) - 1; i++){
                for(int x = i + 1; x < strlen(string); x++){
                        if(isupper(string[i])){
                            string[i] = tolower(string[i]);
                        }
                        if(isupper(string[x])){
                            string[x] = tolower(string[x]);
                        }
                    if(string[i] > string[x]){
                        t = string[i];
                        string[i] = string[x];
                        string[x] = t;
                    }
                }
        }
        printf("%s\n", string);
    }
    return 0;
}
