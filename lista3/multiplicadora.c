#include <stdio.h>

int main(){
    int m1, m2, n1, n2;
    scanf("%d %d %d %d", &m1,&n1,&m2,&n2);
    int matriz1[m1][n1];
    int matriz2[m2][n2];
    int m3 = m1,n3 = n2;
    int matriz3[m3][n3];
    

    for(int i=0;i<m1;i++){
        for(int j=0;j<n1;j++)
            scanf("%d", &matriz1[i][j]);
    }

    for(int i=0;i<m2;i++){
        for(int j=0;j<n2;j++)
            scanf("%d", &matriz2[i][j]);
    }

    for(int i=0;i<m3;i++){
        for(int j=0;j<n3;j++){
            //int k = 0;
            int soma1 = 1, soma2 =1;
            for(int k1=0;k1<m3;k1++){
                soma1 *= matriz1[i][j+k1];
            }
            for(int k2=0;k2<n3;k2++){
                soma2 *= matriz2[i+k2][j];
            }
            int soma = soma1 + soma2;
            matriz3[i][j] = soma;
            
            
        }
    }

    for(int i=0;i<m3;i++){
        for(int j=0;j<n3;j++)
            printf("%d ", matriz3[i][j]);
        printf("\n");
    }

    return 0;
}
