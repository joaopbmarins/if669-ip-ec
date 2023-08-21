#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *arq;

    arq = fopen("alunos.bin", "rb");
    char cpf[12], nome[100];
    float *lista;
    int qtd;

    while(!feof(arq)){

        fread(cpf, sizeof(char) * 12, 1, arq);
        fread(nome, sizeof(char) * 100, 1, arq);
        fread(&qtd, sizeof(int), 1 , arq);
        fread(&lista, sizeof(float) * qtd, 1, arq);

        printf("%s %s %d\n", cpf, nome, qtd);

    }
    fclose(arq);


    return 0;
}