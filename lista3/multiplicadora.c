#include <stdio.h>

int main()
{
    int m1, m2, n1, n2;
    scanf("%d %d %d %d", &m1, &n1, &m2, &n2);
    int matriz1[m1][n1];
    int matriz2[m2][n2];
    int m3 = m1, n3 = n2;
    int matriz3[m3][n3];

    if ((m1 == n2 && n1 == m2)&& m1 != 0 && n1 != 0 && m2 != 0 && n2 != 0)
    {
        for (int i = 0; i < m1; i++){
            for (int j = 0; j < n1; j++)
                scanf("%d", &matriz1[i][j]);
        }

        for (int i = 0; i < m2; i++){
            for (int j = 0; j < n2; j++)
                scanf("%d", &matriz2[i][j]);
        }

        for (int i = 0; i < m3; i++){
            for (int j = 0; j < n3; j++){
                int soma = 0;
                for (int k = 0; k < m3; k++){
                    soma += matriz1[i][k] * matriz2[k][j];
                }
                matriz3[i][j] = soma;
            }
        }

        for (int i = 0; i < m3; i++){
            for (int j = 0; j < n3; j++)
                printf("%d ", matriz3[i][j]);
            printf("\n");
        }
    }
    else
        printf("Nao e possivel multiplicar\n");

    return 0;
}
