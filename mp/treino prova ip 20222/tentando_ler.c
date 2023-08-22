#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *arq;

    arq = fopen("alunos.bin", "rb");
    char cpf[12], nome[100];
    //float *lista = NULL;
    int qtd;

    while(!feof(arq)){

        fread(cpf, sizeof(char) * 12, 1, arq);
        fread(nome, sizeof(char) * 100, 1, arq);
        fread(&qtd, sizeof(int), 1 , arq);
        float lista[qtd];
        //lista = (float *) realloc(lista, sizeof(float)*qtd);
        fread(&lista, sizeof(float) * qtd, 1, arq);

        printf("%s %s %d ", cpf, nome, qtd);

        for(int i=0;i<qtd;i++){
            printf("%.2f ", lista[i]);
        }
        printf("\n");

    }
    fclose(arq);


    return 0;
}