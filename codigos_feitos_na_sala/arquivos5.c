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
    strcpy(umaInfo.nome, " Alexandre Mota");
    umaInfo.altura = 1.82;
    arq = fopen("teste1.bin", "wb");
    if(arq == NULL){printf("erro"); exit(1);}
    fwrite(&umaInfo, sizeof(Info), 1 , arq);
    fclose(arq);
    return 0;
}