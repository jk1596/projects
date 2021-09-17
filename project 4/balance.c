#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define EXIT_SUCCESS 0  
#define EXIT_FAILURE 1

struct node {
    int data;
    struct node *next;
}node;
struct node *top = NULL;

struct node* newNode(int data){
    struct node *ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}
int pop() {
    int data;
    struct node *temp;
    if(top == NULL){
        return -1;
    }
    data = top->data;
    temp = top;
    top = temp->next;
    free(temp);
    return data;
}


void push(int data){
    struct node *temp, *ptr = newNode(data);
    if(top == NULL){
        top = ptr;
        return;
    }
    temp = top;
    ptr->next = temp;
    top = ptr;
}

int main(int argc, char **argv){
    int data = 0;
    char* string = argv[1];
    for(int i = 0; i < strlen(string); i++){
        if((string[i] == '(') || (string[i] == '{') || (string[i] == '[')){
            push(string[i]);
        }
        else if((string[i] == ')') || (string[i] == '}') || (string[i] == ']')){
            if(top == NULL){
               printf("%d: %c\n", i, string[i]);
               exit(EXIT_FAILURE);
           }
            data = pop();
            if((data == '(' && string[i] != ')') || (data == '{' && string[i] != '}') || (data == '[' && string[i] != ']') || data == -1){
                printf("%d: %c\n", i, string[i]);
                exit(EXIT_FAILURE);
                }
            }
    }
    if(top != NULL){
        printf("open: ");
        while(top != NULL){
            int data = 0;
            data = pop();
            if(data == '('){
            printf(")");
            }
            if(data == '['){
                printf("]");
            }
            if(data == '{'){
                printf("}");
            }
        }
        printf("\n");
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
    return 0;
    }
    