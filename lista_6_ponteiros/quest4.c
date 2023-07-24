#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char leitura[100];
    char **str=NULL;
    int tam_leitura;
    int tam_vetor_str=0;
    
    while(scanf(" %s", leitura) != EOF){
        tam_leitura = strlen(leitura);
        char **aux;
        aux = str;
        str = (char**) realloc(str, (tam_vetor_str+1)*sizeof(char *));
        if(str == NULL){//caso o realloc falhe 
            printf("Problema de alocacao.\n");
            for(int i=0;i<tam_vetor_str;i++){
                free(aux[i]);
            }
            free(aux);
            exit(1);
        }
        str[tam_vetor_str] = (char *) malloc(tam_leitura+1);
        strcpy(str[tam_vetor_str++],leitura);
    }

    printf("\n");

    for(int i=0;i<tam_vetor_str;i++){
        printf("%s\n", str[i]);
    }
    
    for(int i=0;i<tam_vetor_str;i++){
        free(str[i]);
    }
    free(str);

    return 0;
}