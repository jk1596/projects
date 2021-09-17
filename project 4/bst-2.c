#include <stdio.h>
#include <stdlib.h>

struct nodeBST{
    int data;
    struct nodeBST *left;
    struct nodeBST *right;
};

struct nodeBST* newNode(int data);
struct nodeBST* insert(struct nodeBST *root, int data);
struct nodeBST* delete(struct nodeBST *root, int data);
struct nodeBST* search(struct nodeBST *root, int data);
void print(struct nodeBST *root);

struct nodeBST* newNode(int data){
    struct nodeBST *node = malloc(sizeof(struct nodeBST));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void print(struct nodeBST *root){
    if(root == NULL){
        printf(" \n");
    }
    else {
        // traverse through tree inorder
        printf("(");
        print(root->left);
        printf("%d", root->data);
        print(root->right);
        printf(")");
    }
    printf("\n");
}
struct nodeBST* search(struct nodeBST *root, int data){
    while(root->data != data){
        if(root != NULL){
            // if data is smaller than root, go to left branch
            if(root->data > data){
                root = root->left;
            }
            // goes to right branch
            else {
                root = root->right;
            }
        }
    }
    return root;
}

struct nodeBST* insert(struct nodeBST *root, int data){
    //if tree is empty
    if(root == NULL){
        return newNode(data);
    }
    // goes to left
    if(data < root->data){
        root->left = insert(root->left, data);
    }
    //goes to right
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

struct nodeBST* delete(struct nodeBST *root, int data){
    // 3 Cases: node has two children, no children, or one.
    if(root == NULL){
        return root;
    }
    // traverse until node is found
    // goes into left branch
    if(data < root->data){
        root->left = delete(root->left, data);
    }
    // goes into right branch
    else if(data > root->data){
        root->right = delete(root->right, data);
    }
    // if node is finally found
    else {
        // Case 1 and 2: No child or only one. No need to find successor
        if(root->left == NULL){
            struct nodeBST *result = root->right;
            free(root);
            return result;
        }
        else if(root->right == NULL){
            struct nodeBST *result = root->left;
            free(root);
            return result;
        }

        // Case 3: two children. must find the successor
        // finding the smallest by traversing all the way through left branch
        struct nodeBST *result = root->right;
        while(root && root->left != NULL){
            root = root->left;
        }
        // Storing data into root
        root->data = result->data;

        // recursively calling delete until node has one child or no child
        root->right = delete(root->right, result->data);
    }
    return root;
}
int main() {
    //FILE *fp = fopen("in", "r");
    
    char command;
    int element;
    struct nodeBST *root = NULL;

    while(scanf("%c", &command) != EOF){
        if(command == 'i'){
            // already in element
            if(search(root, element) != NULL){
                printf("duplicate\n");
            }
            else {
                root = insert(root, element);
            }
        }
        if(command == 'd'){
            // if element isnt in tree
            if(search(root, element) == NULL){
                printf("absent\n");
            }
            else {
                root = delete(root, element);
                printf("deleted\n");
            }
        }
        if(command == 's'){
            if((search(root, element)) == NULL){
                printf("absent\n");
            }
            else {
                printf("present\n");
            }
        }
        if(command == 'p'){
            print(root);
        }
    return 0;
}
}