#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
João Pedro Barbosa Marins
jpbm 
Lista Ponteiros
Questão 4
*/

int main(){
    char leitura[100];
    char **str=NULL;
    int tam_vetor_str=0;
    
    while(scanf(" %s", leitura) != EOF){
        int tam_leitura = strlen(leitura);
        char **aux;
        aux = str;
        str = (char**) realloc(str, (tam_vetor_str+1)*sizeof(char *));//realloc para aumentar str de acordo com a quantidade de palavras a serem guardas
        if(str == NULL){//caso o realloc falhe 
            printf("Problema de alocacao.\n");
            for(int i=0;i<tam_vetor_str;i++){//processo para limpar a memoria por meio do ponteiro auxiliar
                free(aux[i]);
            }
            free(aux);
            exit(1);
        }
        str[tam_vetor_str] = (char *) malloc(tam_leitura+1);//malloc no tamanho da palavra lida para alocar no str[tam_vetor_str] a palavra lida no scanf != eof
        if(str[tam_vetor_str] == NULL){//caso o malloc falhe 
            printf("Problema de alocacao.\n");
            for(int i=0;i<tam_vetor_str;i++){
                free(aux[i]);
            }
            free(aux);
            exit(1);
        }
        strcpy(str[tam_vetor_str++],leitura);//copia a palavra e aumenta tam_vetor_str
    }

    printf("\n");

    for(int i=0;i<tam_vetor_str;i++){//imprimindo todas as palavras lidas
        printf("%s\n", str[i]);
    }
    
    for(int i=0;i<tam_vetor_str;i++){//limpando os endereços de memorias alocados para finalizar o programa 
        free(str[i]);
    }
    free(str);

    return 0;
}