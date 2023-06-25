#include <stdio.h>

int main(){
    int m1, m2, n1, n2;
    scanf("%d %d %d %d", &m1,&n1,&m2,&n2);
    int matriz1[m1][n1];
    int matriz2[m2][n2];
    int matriz3[m1][n2];

    for(int i=0;i<m1;i++){
        for(int j=0;j<n1;j++)
            scanf("%d", &matriz1[i][j]);
    }

    for(int i=0;i<m2;i++){
        for(int j=0;j<n2;j++)
            scanf("%d", &matriz2[i][j]);
    }

    for(int i=0;i<m1;i++){
        for(int j=0;j<n2;j++){
            for(int k=1;k<m1;k++){
                if(k==1)
                    matriz3[i][j] = matriz1[i][j]*matriz2[i][j];
                else
                    matriz3[i][j] += matriz1[i][j+k]*matriz2[i+k][j];
            }
        }
    }

    for(int i=0;i<m1;i++){
        for(int j=0;j<n2;j++)
            printf("%d ", matriz3[i][j]);
        printf("\n");
    }

    return 0;
}