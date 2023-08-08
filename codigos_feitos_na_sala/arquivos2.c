#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *arq;
    arq = fopen("test.txt", "r+t");
    if(arq == NULL ){printf("Deu problema\n"); exit(1);}
    fseek(arq, 5, SEEK_SET);//Move o ponto de leitura do arquivo de uma determinada posição.
    //fseek(arq, quantas posições vai ser andadas, de onde vai contar essas posições); SEEK_SET do inicio SEEK_CUR de onde vc está atualmente SEEK_END do final do arquivo
    fprintf(arq, "--");
    //printf("Tam do arquivo: %ld bytes\n", ftell(arq));//ftell diz em qual byte está no arquivo
    fclose(arq);
    return 0;
}