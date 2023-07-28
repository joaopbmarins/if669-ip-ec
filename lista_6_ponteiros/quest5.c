#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
João Pedro Barbosa Marins
jpbm 
Lista Ponteiros
Questão 5
*/

typedef struct{
    int id_produto;
    int qtd;
    int preco;
}Lista;

int main(){
    char comando[20];
    Lista *lista=NULL;
    int tam=0;
    while(scanf(" %s", comando)!= EOF){
        Lista *aux;
        aux = lista;
        if(strcmp(comando,"NEW")==0){
            lista = (Lista *) realloc(lista, (tam+1) * sizeof(Lista));

            if(lista == NULL){// caso realloc retorne null
                printf("Problema de alocacao\n"); 
                free(aux);
                exit(1);
            }

            scanf("%d %d %d", &(lista[tam].id_produto), &(lista[tam].qtd), &(lista[tam].preco));
            tam++;
            
            for(int i=0;i<tam;i++){
                for(int j=0;j<tam-i-1;j++){
                    Lista aux1;
                    if(lista[j].id_produto > lista[j+1].id_produto){
                        aux1 = lista[j];
                        lista[j] = lista[j+1];
                        lista[j+1] = aux1;
                    }
                }
            }
        }
        else if(strcmp(comando,"RM")==0){
            int id_deletado;
            scanf("%d", &id_deletado);

            for(int i=0;i<tam;i++){
                for(int j=0;j<tam-i-1;j++){
                    Lista aux1;
                    if(lista[j].id_produto == id_deletado){
                        aux1 = lista[j];
                        lista[j] = lista[j+1];
                        lista[j+1] = aux1;
                    }
                }
            }
            tam--;

            aux = lista;
            lista = (Lista *) realloc(lista, tam *sizeof(Lista));
            if(lista == NULL){// caso realloc retorne null
                printf("Problema de alocacao\n"); 
                free(aux);
                exit(1);
            }
        }
        else if(strcmp(comando,"END")==0){
            for(int i=0;i<tam;i++)
                printf("%d %d %d\n", lista[i].id_produto, lista[i].preco, lista[i].qtd);
            break;
        }
    }

    free(lista);
    return 0;
}
