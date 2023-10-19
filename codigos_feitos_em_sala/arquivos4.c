#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *arq;
    char nome[50];
    char separador[4];
    float altura;
    arq = fopen("teste.bin", "rb");
    if(arq == NULL){printf("erro"); exit(1);}
    fread(nome, sizeof(char), 16, arq);
    fread(&altura, sizeof(float), 1, arq);
    printf("nome: %saltura: %.2f\n", nome, altura);
    fclose(arq);
    return 0;
}