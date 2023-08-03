#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int Coluna;
    float Valor;
}Coluna;

typedef struct{
    int Linha;
    int qtdCols;
    Coluna *p;
}Linha;

void printMatriz(Linha *matriz, int qtd_linhas);
int encontraLinha(int linha, Linha *lista, int tam_lista);
int encontraColuna(int coluna, Coluna *col_lista, int tam_col);
Linha *preencheMatriz(int *qtdLinhas);

int main(){
    Linha *Matriz;
    int qtd_linhas=0;
    
    Matriz = preencheMatriz(&qtd_linhas);
    printMatriz(Matriz, qtd_linhas);

    for(int i=0;i<qtd_linhas;i++){
        free(Matriz[i].p);
    }
    free(Matriz);

    return 0;
}

int encontraLinha(int linha, Linha *lista, int tam_lista){
    for(int i=0;i<tam_lista;i++){
        if(lista[i].Linha == linha){
            return i;
        }
    }
    return -1;
}

int encontraColuna(int coluna, Coluna *col_lista, int tam_col){
    for(int i=0;i<tam_col;i++){
        if(col_lista[i].Coluna == coluna){
            return i;
        }
    }
    return -1;
}

Linha *preencheMatriz(int *qtdLinhas){
    int linha, col;
    float valor;
    Linha *Matriz=NULL;
    Linha *aux;
    Coluna *aux1;
    printf("Qual é a linha, a coluna e o valor respectivo na matriz? ");
    while(scanf("%d %d %f", &linha, &col, &valor) != EOF){
        if(encontraLinha(linha, Matriz, *qtdLinhas) == -1){//não existe a linha ainda logo tbm nn existe coluna
            int qtd_colunas = 0;
            aux = Matriz;
            Matriz = (Linha *) realloc(Matriz, (*qtdLinhas + 1) * sizeof(Linha));
            if(Matriz == NULL){printf("problema de alocacao."); for(int i=0;i<*qtdLinhas;i++) free(aux[i].p); free(aux); exit(1);}
            Matriz[*qtdLinhas].Linha = linha;
            Matriz[*qtdLinhas].qtdCols = qtd_colunas+1;
            aux1 = Matriz[*qtdLinhas].p;
            Matriz[*qtdLinhas].p = (Coluna *) malloc((qtd_colunas+1) * sizeof(Coluna));
            if(Matriz[*qtdLinhas].p == NULL){printf("problema de alocacao."); for(int i=0;i<*qtdLinhas;i++) free(Matriz[i].p); free(Matriz); free(aux1); exit(1);}
            Matriz[*qtdLinhas].p[qtd_colunas].Coluna = col;
            Matriz[*qtdLinhas].p[qtd_colunas].Valor = valor;

            qtd_colunas++;
            (*qtdLinhas)++;
        }
        else{// existe linha, não sabe se existe coluna ainda
            int linha_matriz = encontraLinha(linha, Matriz, *qtdLinhas);
            if(encontraColuna(col, (Matriz[linha_matriz].p), (Matriz[linha_matriz].qtdCols)) == -1){//não achou a coluna, precisa criar ela.
                aux1 = Matriz[linha_matriz].p;
                Matriz[linha_matriz].p = (Coluna *) realloc(Matriz[linha_matriz].p, (Matriz[linha_matriz].qtdCols+1)* sizeof(Coluna));
                if(Matriz[*qtdLinhas].p == NULL){printf("problema de alocacao."); for(int i=0;i<*qtdLinhas;i++) free(Matriz[i].p); free(Matriz); free(aux1); exit(1);}
                Matriz[linha_matriz].p[Matriz[linha_matriz].qtdCols].Coluna = col;
                Matriz[linha_matriz].p[Matriz[linha_matriz].qtdCols].Valor = valor;
                Matriz[linha_matriz].qtdCols += 1;
            }
            else{//achou a coluna e a linha existe
                int coluna_matriz = encontraColuna(col, (Matriz[linha_matriz].p), (Matriz[linha_matriz].qtdCols));
                Matriz[linha_matriz].p[coluna_matriz].Valor = valor;
            }
        }
        
        printf("Qual é a linha, a coluna e o valor respectivo na matriz? ");
        printf("Caso queira encerrar a inserção CTRL+D. ");
    }
    return Matriz;
}

void printMatriz(Linha *matriz, int qtd_linhas){
    int max_colunas=0, max_linha=0;

    for(int i=0;i<qtd_linhas;i++){
        if(matriz[i].Linha > max_linha){//acha o maximo de linhas
            max_linha = matriz[i].Linha;
        }
        for(int j=0;j<matriz[i].qtdCols;j++){
            if(matriz[i].p[j].Coluna > max_colunas){//acha o maximo de colunas
                max_colunas = matriz[i].p[j].Coluna;
            }
        }
    }
    printf("\n");

    for(int i=1;i<=max_linha;i++){
        int a = encontraLinha(i, matriz, qtd_linhas);
        if(a != -1){//encontrei a linha
            for(int j=1;j<=max_colunas;j++){
                int b = encontraColuna(j, (matriz[a].p), matriz[a].qtdCols);
                if(b != -1){//encontrei a coluna
                    printf("%.1f ",matriz[a].p[b].Valor);
                }
                else{//nao encontrei a coluna
                    printf("0.0 ");
                }
            }
        }
        else{// nao encontrei a linha
            for(int j=1;j<=max_colunas;j++){
                printf("0.0 ");
            }
        }
        printf("\n");
    }

}
