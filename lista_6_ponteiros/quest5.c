#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id_produto;
    int qtd;
    int preco;
}Lista;

Lista ** new(Lista **lista, int *tam){
    Lista **aux;
    aux = lista;
    lista = (Lista **) realloc(lista, (*(tam)+1)*sizeof(Lista*));

    if(lista == NULL){// caso realloc retorne null
        printf("Problema de alocacao\n"); 
        for(int i=0;i<*tam;i++)
            free(aux[i]);
        free(aux);
        exit(1);
    }

    lista[*tam] = (Lista *) malloc(sizeof(lista));
    scanf("%d %d %d", &(lista[*tam]->id_produto), &(lista[*tam]->qtd), &(lista[*tam]->preco));
    *(tam) += 1;
    
    for(int i=0;i<*tam;i++){
        for(int j=0;j<*tam-i-1;j++){
            Lista aux1;
            if(lista[j]->id_produto > lista[j+1]->id_produto){
                aux1 = *(lista[j]);
                *(lista[j]) = *(lista[j+1]);
                *(lista[j+1]) = aux1;
            }
        }
    }

    return lista;
}
Lista ** rm(Lista **lista, int *tam){
    Lista **aux;
    int id_deletado, posi;
    scanf("%d", &id_deletado);

    for(int i=0;i<*tam;i++){
        for(int j=0;j<*tam-i-1;j++){
            Lista aux1;
            if(lista[j]->id_produto == id_deletado){
                aux1 = *(lista[j]);
                *(lista[j]) = *(lista[j+1]);
                *(lista[j+1]) = aux1;
            }
        }
    }
    *(tam) -= 1;

    free(lista[*tam]);
    aux = lista;
    lista = (Lista **) realloc(lista, *(tam)*sizeof(Lista*));
    if(lista == NULL){
        printf("Problema de alocacao\n"); 
        for(int i=0;i<*tam;i++)
            free(aux[i]);
        free(aux);
        exit(1);
    }
    
    return lista;
}

int main(){
    char comando[50];
    Lista **lista=NULL;
    int tam=0;
    while(scanf(" %s", comando)!= EOF){
        if(strcmp(comando,"NEW")==0){
            lista = new(lista, &tam);
        }
        else if(strcmp(comando,"RM")==0){
            lista = rm(lista, &tam);
        }
        else if(strcmp(comando,"END")==0){
            break;
        }
    }

    for(int i=0;i<tam;i++)
        printf("%d %d %d\n", lista[i]->id_produto, lista[i]->qtd, lista[i]->preco);
    
    return 0;
}
