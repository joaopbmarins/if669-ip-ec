#include <stdio.h>
#include <stdlib.h>

int main(){
    int mat[2][3] = {{2,3,-4},
                     {-2,0,3}};
    int *p;
    p = (int *) mat;

    for(int i=0;i<6;i++){
        printf("vet[%d]=%d\n", i+1,p[i]);
    }
    return 0;
}