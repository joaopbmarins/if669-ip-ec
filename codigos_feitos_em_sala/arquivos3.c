#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *arq;
    char nome[50] = "Alexandre Mota";
    char separador[4] = ", ";
    float altura = 1.82;
    arq = fopen("teste.bin", "wb");
    if(arq == NULL){printf("erro"); exit(1);}
    fwrite(nome, sizeof(char), strlen(nome), arq);
    fwrite(separador, sizeof(char), strlen(separador), arq);
    fwrite(&altura, sizeof(float), 1, arq);
    fclose(arq);
    return 0;
}