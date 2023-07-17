#include <stdio.h>
#include <stdlib.h>

int main(){
    int **mat;
    mat = (int **) malloc(2 * sizeof(int *));
    if(mat != NULL){
        for(int i=0;i<2;i++){
            mat[i] = (int *) malloc(3 * sizeof(int));
            if(mat[i] == NULL) exit(1);
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                mat[i][j] = i + j;
            }
        }
        for(int i=0;i<2;i++) free(mat[i]);
    }
    free(mat);
    return 0;
}