#include <stdio.h>
#include <stdlib.h>

/*void multiply(int** result, int** M, int** duplicate, dim){
    for(int i = 0; i < dim; i++){
                for(int j = 0; j < dim; j++){
                    for(int c = 0; c < dim; c++){
                        result[i][j] += M[i][c] * duplicate[c][j];
                    }
                }
            }
}
*/
int main(int argc, char** argv) {
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) return 0;
    if(argc != 2) return 0;
    int dim, power;
    fscanf(fp, "%d\n", &dim);

    // creating matrices
    int **M = malloc(sizeof(int*) * dim);
    for(int i = 0; i < dim; i++){
        M[i] = malloc(sizeof(double) * dim);
    }
    int **result = malloc(sizeof(int*) * dim);
    for(int i = 0; i < dim; i++){
        result[i] = malloc(sizeof(double) * dim);
    }
    int **duplicate = malloc(sizeof(int*) * dim);
    for(int i = 0; i < dim; i++){
        duplicate[i] = malloc(sizeof(double) * dim);
    }

    // entering values into matrix
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            fscanf(fp, "%d", &M[i][j]);
            result[i][j] = M[i][j];
        }
    }
    
    fscanf(fp, "%d", &power);

    if(power == 1){
        for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            printf("%d", M[i][j]);
        }
        printf("\n");
        }
        }
    // Identity matrix
    else if(power == 0){
        for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            if(i == j){
                M[i][j] = 1;
            }
            else{
                M[i][j] = 0;
            }
        }
        }
    }
    // multiply one element in M1 row by one element in M2 column and add to the sum and keep going
    else {
        int sum = 0;
        for(int t = 0; t < power - 1; t++){
            for(int i = 0; i < dim; i++){
                for(int j = 0; j < dim; j++){
                    for(int c = 0; c < dim; c++){
                        sum += result[i][c] * M[c][j];
                    }
                duplicate[i][j] = sum;
                sum = 0;
                }
            }
            // updating the result matrix so it can be multiplied by the original 
            for(int i = 0; i < dim; i++){
                for(int j = 0; j < dim; j++){
                    result[i][j] = duplicate[i][j];
                }
            }
        }
    }

    //printing result
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            if(j == dim - 1) {
                printf("%d", result[i][j]);
            }
            else {
                printf("%d ", result[i][j]);
        }
        }
        printf("\n");
    }
    // freeing
    for(int i = 0; i < dim; i++){
        free(M[i]);
        free(duplicate[i]);
        free(result[i]);
    }
    free(M);
    free(duplicate);
    free(result);

    return 0;
}