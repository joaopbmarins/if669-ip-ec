#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char nome[50];
    float valor;
    int quantidade;
}Compra;

void inserirCompra(Compra **lista, int *tamanhoLista);

void removerCompra(Compra **lista, int *tamanhoLista);

void removerGrupoCompra(Compra **lista, int *tamanhoLista);

void consultarLista(Compra *lista, int tamanhoLista);

void procurarCompra(Compra *lista, int tamanhoLista);

int main()
{
    Compra *lista = NULL;
    int tamanhoLista = 0;
    char funcao[20];

    while (scanf("%s", funcao) != EOF)
    {
        if (strcmp(funcao, "INSERIR") == 0)
        {
            inserirCompra(&lista, &tamanhoLista);
        }
        else if (strcmp(funcao, "REMOVER") == 0)
        {
            removerCompra(&lista, &tamanhoLista);
        }
        else if (strcmp(funcao, "REMOVERGRUPO") == 0)
        {
            removerGrupoCompra(&lista, &tamanhoLista);
        }
        else if (strcmp(funcao, "CONSULTAR") == 0)
        {
            consultarLista(lista, tamanhoLista);
        }
        else if (strcmp(funcao, "PROCURAR") == 0)
        {
            procurarCompra(lista, tamanhoLista);
        }
    }

    free(lista);
}


void inserirCompra(Compra **lista, int *tamanhoLista){
    *lista = (Compra *)realloc(*lista, (*tamanhoLista + 1) * sizeof(Compra));
    scanf("%s %f %d", (*lista)[*tamanhoLista].nome, &(*lista)[*tamanhoLista].valor, &(*lista)[*tamanhoLista].quantidade);
    (*tamanhoLista)++;
}

void removerCompra(Compra **lista, int *tamanhoLista){
    char produto[50];
    int qtd_remover;
    scanf("%s %d", produto, &qtd_remover);

    for (int i = 0; i < *tamanhoLista; i++)
    {
        if (strcmp((*lista)[i].nome, produto) == 0)
        {
            (*lista)[i].quantidade = (*lista)[i].quantidade - qtd_remover;

            if ((*lista)[i].quantidade <= 0)
            {
                (*lista)[i] = (*lista)[*tamanhoLista - 1];
                *lista = (Compra *)realloc(*lista, (*tamanhoLista - 1)* sizeof(Compra));
                (*tamanhoLista)--;
            }
        }
    }
}

void removerGrupoCompra(Compra **lista, int *tamanhoLista){
    float valor;
    scanf("%f", &valor);
    int i = 0;
    while (i < *tamanhoLista)
    {
        if ((*lista)[i].valor > valor)
        {
            (*lista)[i] = (*lista)[*tamanhoLista - 1];
            *lista = (Compra *)realloc(*lista, (*tamanhoLista - 1)* sizeof(Compra));
            (*tamanhoLista)--;
        }
        else
        {
            i++;
        }
    }
}

void consultarLista(Compra *lista, int tamanhoLista){
    float valor = 0;
    for (int i = 0; i < tamanhoLista; i++)
    {
        valor = valor + (lista[i].valor * lista[i].quantidade);
    }
    printf("Atualmente a lista esta em R$%.1f\n\n", valor);
}

void procurarCompra(Compra *lista, int tamanhoLista){
    char palavra[30];
    scanf("%s", palavra);

    if (tamanhoLista == 0)
    {
        printf("%s nao foi encontrado.\n\n", palavra);
        return;
    }

    for (int i = 0; i < tamanhoLista; i++)
    {
        if (strcmp(lista[i].nome, palavra) == 0)
        {
            printf("%s\n- %.1f\n- %d\n\n", lista[i].nome, lista[i].valor, lista[i].quantidade);
            return;
        }
    }

    printf("%s nao foi encontrado.\n\n", palavra);
}