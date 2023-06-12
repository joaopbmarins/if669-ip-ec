#include <stdio.h>
#include <math.h>
#define euler 2.71

int main(){
    int x1,y1,k1;
    int x2,y2,k2;
    int x3,y3,k3;
    float media1, media2, media3;

    scanf("%d%d%d", &x1, &y1, &k1);
    scanf("%d%d%d", &x2, &y2, &k2);
    scanf("%d%d%d", &x3, &y3, &k3);

    media1 = fabs(((x1*x1)*euler)/y1);
    media2 = fabs(((x2*x2)*euler)/y2);
    media3 = fabs(((x3*x3)*euler)/y3);


    if(media1 < 32.5)
        printf("O aluno de índice %d possui o valor IAF igual a %.2f e a descrição de Calouro.\n", k1, media1);
    else if(media1 >= 32.5 && media1 < 64)
        printf("O aluno de índice %d possui o valor IAF igual a %.2f e a descrição de Iniciado.\n", k1, media1);
    else if(media1 >= 64 && media1 < 128)
        printf("O aluno de índice %d possui o valor IAF igual a %.2f e a descrição de Morador do Grad.\n", k1, media1);
    else if(media1 >= 128 && media1 < 256)
        printf("O aluno de índice %d possui o valor IAF igual a %.2f e a descrição de Matemático Discreto.\n", k1, media1);
    else if(media1 >= 256 && media1 <= 512)
        printf("O aluno de índice %d possui o valor IAF igual a %.2f e a descrição de Conserta Impressoras.\n", k1, media1);
    else if(media1 > 512)
        printf("O aluno de índice %d possui o valor IAF igual a %.2f e a descrição de Sem volta.\n", k1, media1);

    if(media2 < 32.5)
        printf("O aluno de índice %d possui o valor IAF igual a %.2f e a descrição de Calouro.\n", k2, media2);
    else if(media2 >= 32.5 && media2 < 64)
        printf("O aluno de índice %d possui o valor IAF igual a %.2f e a descrição de Iniciado.\n", k2, media2);
    else if(media2 >= 64 && media2 < 128)
        printf("O aluno de índice %d possui o valor IAF igual a %.2f e a descrição de Morador do Grad.\n", k2, media2);
    else if(media2 >= 128 && media2 < 256)
        printf("O aluno de índice %d possui o valor IAF igual a %.2f e a descrição de Matemático Discreto.\n", k2, media2);
    else if(media2 >= 256 && media2 <= 512)
        printf("O aluno de índice %d possui o valor IAF igual a %.2f e a descrição de Conserta Impressoras.\n", k2, media2);
    else if(media2 > 512)
        printf("O aluno de índice %d possui o valor IAF igual a %.2f e a descrição de Sem volta.\n", k2, media2);

    if(media3 < 32.5)
        printf("O aluno de índice %d possui o valor IAF igual a %.2f e a descrição de Calouro.\n", k3, media3);
    else if(media3 >= 32.5 && media3 < 64)
        printf("O aluno de índice %d possui o valor IAF igual a %.2f e a descrição de Iniciado.\n", k3, media3);
    else if(media3 >= 64 && media3 < 128)
        printf("O aluno de índice %d possui o valor IAF igual a %.2f e a descrição de Morador do Grad.\n", k3, media3);
    else if(media3 >= 128 && media3 < 256)
        printf("O aluno de índice %d possui o valor IAF igual a %.2f e a descrição de Matemático Discreto.\n", k3, media3);
    else if(media3 >= 256 && media3 <= 512)
        printf("O aluno de índice %d possui o valor IAF igual a %.2f e a descrição de Conserta Impressoras.\n", k3, media3);
    else if(media3 > 512)
        printf("O aluno de índice %d possui o valor IAF igual a %.2f e a descrição de Sem volta.\n", k3, media3);

    return 0;
}