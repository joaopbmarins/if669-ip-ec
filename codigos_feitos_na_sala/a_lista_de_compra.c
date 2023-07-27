#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    float preco;    
    int qtd;
    char nome[50];
}Lista;

Lista **inserir(Lista **lista, int *tam){
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
    scanf(" %s %f %d", (lista[*tam]->nome), &(lista[*tam]->preco), &(lista[*tam]->qtd));
    *(tam) += 1;

    return lista;
}

Lista **remover(Lista **lista, int *tam){
    Lista **aux;
    char nome_deletado[50];
    int qtd_deletado;
    scanf(" %s %d", nome_deletado, &qtd_deletado);

    for(int i=0;i<*tam;i++){
        for(int j=0;j<*tam-i-1;j++){
            Lista aux1;
            if(strcmp(lista[j]->nome, nome_deletado)==0){
                aux1 = *(lista[j]);
                *(lista[j]) = *(lista[j+1]);
                *(lista[j+1]) = aux1;
            }
        }
    }

    if((lista[*(tam)-1]->qtd - qtd_deletado) <= 0){
        *(tam) -= 1;
        free(lista[*tam]);
        aux = lista;
        lista = (Lista **) realloc(lista, *(tam)*sizeof(Lista*));
        if(lista == NULL){// caso realloc retorne null
            printf("Problema de alocacao\n"); 
            for(int i=0;i<*tam;i++)
                free(aux[i]);
            free(aux);
            exit(1);
        }
    }
    else{
        lista[*(tam)-1]->qtd -= qtd_deletado;
    }
    
    
    return lista;
}

Lista **removergrupo(Lista **lista, int *tam){
    Lista **aux;
    float preco_deletado;
    scanf("%f", &preco_deletado);
    printf("%f\n", lista[2]->preco);
    
    for(int i=0;i<*tam;i++){
        for(int j=0;j<*tam-i-1;j++){
            Lista aux1;
            if(lista[j]->preco > preco_deletado){
                aux1 = *(lista[j]);
                *(lista[j]) = *(lista[j+1]);
                *(lista[j+1]) = aux1;
            }
        }
    }

    int qtd_deletado;
    for(int i=0;i<*tam;i++){
        if(lista[i]->preco > preco_deletado){
            qtd_deletado++;
        }
    }

    for(int i=0;i<qtd_deletado;i++){
        *(tam) -= 1;
        free(lista[*tam]);
        aux = lista;
        lista = (Lista **) realloc(lista,*(tam)*sizeof(Lista*));
        if(lista == NULL){// caso realloc retorne null
            printf("Problema de alocacao\n"); 
            for(int i=0;i<*tam;i++)
                free(aux[i]);
            free(aux);
            exit(1);
        }
    }

    return lista;
}

int main(){
    char comando[50];
    Lista **lista=NULL;
    int tam=0;
    while(scanf(" %s", comando)!= EOF){
        if(strcmp(comando,"INSERIR")==0){
            lista = inserir(lista, &tam);
        }
        else if(strcmp(comando,"REMOVER")==0){
            lista = remover(lista, &tam);
        }
        else if(strcmp(comando, "REMOVERGRUPO")==0){
            lista = removergrupo(lista, &tam);
        }
        else if(strcmp(comando,"END")==0){
            break;
        }
    }

    for(int i=0;i<tam;i++)
        printf("%s %.2f %d\n", lista[i]->nome, lista[i]->preco, lista[i]->qtd);
    
    return 0;
}