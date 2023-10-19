#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    float altura;
} Info;


int main(){
    FILE *arq;
    Info umaInfo;
    arq = fopen("teste1.bin", "rb");
    if(arq == NULL){printf("erro"); exit(1);}
    fread(&umaInfo, sizeof(Info), 1 , arq);
    printf("Nome: %s, Altura: %.2f\n", umaInfo.nome, umaInfo.altura);
    fclose(arq);
    return 0;
}