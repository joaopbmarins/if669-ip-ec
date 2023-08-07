#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *arq;
    char linha[100];
    arq = fopen("/home/CIN/jpbm/Documents/teste.txt", "rt");//o parametro tem q ser a mistura deles r = read;  w = write;  a = append /com/ t = tipo texto; b = tipo binario 
    if(arq==NULL){printf("erro na abertura do arquivo\n"); exit(1);}
    //fprintf(arq, "%s\n", "nova 5");
    fscanf(arq," %99[^\n]", linha);
    printf("Linha 1: %s\n",linha);
    fscanf(arq," %99[^\n]", linha);
    printf("Linha 2: %s\n",linha);
    //printf("Deu tudo certo\n");
    fclose(arq);
    return 0;
}