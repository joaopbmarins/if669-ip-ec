#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    float preco;    
    int qtd;
    char nome[50];
}Lista;

void inserir(Lista **lista, int *tam){
    *lista = (Lista *) realloc(*lista, (*tam+1) * sizeof(Lista));
    scanf(" %s %f %d", (*lista)[*tam].nome, &(*lista)[*tam].preco, &(*lista)[*tam].qtd);
    (*tam)++;
}

void remover(Lista **lista, int *tam){
    char nome_deletado[50];
    int qtd_deletado;
    scanf(" %s %d", nome_deletado, &qtd_deletado);

    for(int i=0;i<*tam;i++){
        for(int j=0;j<*tam-i-1;j++){
            Lista aux;
            if(strcmp((*lista)[j].nome, nome_deletado)==0){
                aux = (*lista)[j];
                (*lista)[j] = (*lista)[j+1];
                (*lista)[j+1] = aux;
            }
        }
    }

    if( ((*lista)[*tam-1].qtd - qtd_deletado) <= 0){
        (*tam)--;
        *lista = (Lista *) realloc(*lista, *tam *sizeof(Lista));
    }
    else{
        (*lista)[*tam-1].qtd -= qtd_deletado;
    }
}

void removergrupo(Lista **lista, int *tam){
    float preco_deletado;
    scanf("%f", &preco_deletado);
    
    for(int i=0;i<*tam;i++){
        for(int j=0;j<*tam-i-1;j++){
            Lista aux;
            if((*lista)[j].preco > (*lista)[j+1].preco){
                aux = *(lista[j]);
                (*lista)[j] = (*lista)[j+1];
                (*lista)[j+1] = aux;
            }
        }
    }

    int posi_deletado;
    for(int i=0;i<*tam;i++){
        if((*lista)[i].preco > preco_deletado){
            posi_deletado = i;
            i = *tam +1;
        }
    }

    *tam -= (*tam-posi_deletado);

    *lista = (Lista *) realloc(*lista, *tam * sizeof(Lista));
}

void consultar(Lista *lista, int tam){
    float total=0;
    for(int i=0;i<tam;i++){
        total += (lista[i].preco * lista[i].qtd);
    }
    printf("\nAtualmente a lista esta em R$%.1f\n", total);
}

void procurar (Lista *lista, int tam){
    char procurado[100];
    int achou=0;
    scanf(" %s", procurado);

    for(int i=0;i<tam && achou==0;i++){
        if(strcmp(lista[i].nome, procurado)==0){
            achou = 1;
            printf("\n%s\n", lista[i].nome);
            printf("- %.1f\n", lista[i].preco);
            printf("- %i\n", lista[i].qtd);
        }
    }
    if(achou == 0){
        printf("\n%s nao foi encontrado.\n", procurado);
    }
}

int main(){
    char comando[20];
    Lista *lista=NULL;
    int tam=0;
    while(scanf(" %s", comando)!= EOF){
        if(strcmp(comando,"INSERIR")==0){
            inserir(&lista, &tam);
        }
        else if(strcmp(comando,"REMOVER")==0){
            remover(&lista, &tam);
        }
        else if(strcmp(comando, "REMOVERGRUPO")==0){
            removergrupo(&lista, &tam);
        }
        else if(strcmp(comando,"CONSULTAR")==0){
            consultar(lista, tam);
        }
        else if(strcmp(comando,"PROCURAR")==0){
            procurar(lista, tam);
        }
    }

    free(lista);

    return 0;
}