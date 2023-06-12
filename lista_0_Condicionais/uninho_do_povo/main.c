#include <stdio.h>

int main()
{
    float x, y, dif;
    char dest;
    int n;

    scanf("%f %f %c %d", &x, &y, &dest, &n);

    dif = y - x;

    if (0 <= x < 24 && 0 <= y < 24 && x < y)
    {
        if (dest == 'A')
        {
            if (n > 5 && n < 9)
            {
                if (dif >= (1 + (1 * 0.5)))
                {
                    printf("O uninho faz a boa, obrigado querida mae line\n");
                }
                else if (dif >= 0 && dif < (1 + (1 * 0.5)))
                {
                    printf("Infelizmente o uninho nao tanka, rodamos!\n");
                }
                else
                {
                    printf("Entrada invalida\n");
                }
            }

            else if (n <= 5 && n > 0)
            {
                if (dif > 1)
                {
                    printf("O uninho faz a boa, obrigado querida mae line\n");
                }
                else if (dif <= 1 && dif >= 0)
                {
                    printf("Infelizmente o uninho nao tanka, rodamos!\n");
                }
                else
                {
                    printf("Entrada invalida\n");
                }
            }
            else
            {
                printf("Entrada invalida\n");
            }
        }
        else if (dest == 'B')
        {
            if (n > 5 && n < 9)
            {
                if (dif >= (0.75 + (0.75 * 0.5)))
                {
                    printf("O uninho faz a boa, obrigado querida mae line\n");
                }
                else if (dif >= 0 && dif < (0.75 + (0.75 * 0.5)))
                {
                    printf("Infelizmente o uninho nao tanka, rodamos!\n");
                }
                else
                {
                    printf("Entrada invalida\n");
                }
            }

            else if (n <= 5 && n > 0)
            {
                if (dif > 0.75)
                {
                    printf("O uninho faz a boa, obrigado querida mae line\n");
                }
                else if (dif <= 0.75 && dif >= 0)
                {
                    printf("Infelizmente o uninho nao tanka, rodamos!\n");
                }
                else
                {
                    printf("Entrada invalida\n");
                }
            }
            else
            {
                printf("Entrada invalida\n");
            }
        }
        else
        {
            printf("Entrada invalida\n");
        }
    }
    else
    {
        printf("Entrada invalida\n");
    }

    return 0;
}