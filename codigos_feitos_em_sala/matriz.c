#include <stdio.h>

int main(){
    //int m[3][2] = {{0,0},
    //               {0,0},
    //               {0,0}};

    int m[3][3], i,j;
    for(i = 0;i<3;i++)
        for(j=0;j<3;j++){
            printf("Digite o elemento m[%d][%d]: ",i+1,j+1);
            scanf("%d", &m[i][j]);
        }
    printf("E a matriz na memoria fica:\n");
    for(i = 0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%4d",m[i][j]);
        }
        printf("\n");
    }

    return 0;
}