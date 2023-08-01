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

int encontraLinha(int linha, Linha **lista, int tam_lista){
    for(int i=0;i<tam_lista;i++){
        if((*lista)[i].Linha == linha){
            return i;
        }
    }
    return -1;
}

int encontraColuna(int coluna, Coluna **col_lista, int tam_col){
    for(int i=0;i<tam_col;i++){
        if((*col_lista)[i].Coluna == coluna){
            return i;
        }
    }
    return -1;
}

Linha *preencheMatriz(int *qtdLinhas){
    int linha, col, qtd_colunas;
    float valor;
    Linha *Matriz=NULL;
    printf("Qual é a linha, a coluna e o valor respectivo na matriz? ");
    while(scanf("%d %d %f", &linha, &col, &valor) != EOF){
        if(encontraLinha(linha, &Matriz, *qtdLinhas) == -1){//não existe a linha ainda logo tbm nn existe coluna
            qtd_colunas = 0;
            Matriz = (Linha *) realloc(Matriz, (*qtdLinhas + 1) * sizeof(Linha));
            Matriz[*qtdLinhas].Linha = linha;
            Matriz[*qtdLinhas].qtdCols = qtd_colunas+1;
            Matriz[*qtdLinhas].p = (Coluna *) malloc((qtd_colunas+1) * sizeof(Coluna));
            Matriz[*qtdLinhas].p[qtd_colunas].Coluna = qtd_colunas+1;
            Matriz[*qtdLinhas].p[qtd_colunas].Valor = valor;

            qtd_colunas++;
            (*qtdLinhas)++;
        }
        else{// existe linha, não sabe se existe coluna ainda
            int linha_matriz = encontraLinha(linha, &Matriz, *qtdLinhas);
            if(encontraColuna(col, &(Matriz[linha_matriz].p), (Matriz[linha_matriz].qtdCols)) == -1){//não achou a coluna, precisa criar ela.
                Matriz[linha_matriz].p = (Coluna *) realloc(Matriz[linha_matriz].p, (Matriz[linha_matriz].qtdCols+1)* sizeof(Coluna));
                Matriz[linha_matriz].p[Matriz[linha_matriz].qtdCols].Coluna = col;
                Matriz[linha_matriz].p[Matriz[linha_matriz].qtdCols].Valor = valor;
                Matriz[linha_matriz].qtdCols = Matriz[linha_matriz].qtdCols + 1;
            }
            else{//achou a coluna e a linha existe
                int coluna_matriz = encontraColuna(col, &(Matriz[linha_matriz].p), (Matriz[linha_matriz].qtdCols));
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
    Linha aux;
    Coluna aux1;

    // for(int i=0;i<qtd_linhas;i++){
    //     for(int j=0;j<qtd_linhas-i-1;j++){
    //         if(matriz[j].Linha > matriz[j+1].Linha){
    //             aux = matriz[j];
    //             matriz[j] = matriz[j+1];
    //             matriz[j+1] = aux;
    //         }
    //     }
    // }

    // for(int i=0;i<qtd_linhas;i++){
    //     for(int j=0;matriz[i].qtdCols;j++){
    //         for(int k=0;k<matriz[i].qtdCols-j-1;k++){
    //             if(matriz[i].p[k].Coluna > matriz[i].p[k+1].Coluna){
    //                 aux1 = matriz[i].p[k];
    //                 matriz[i].p[k] = matriz[i].p[k+1];
    //                 matriz[i].p[k+1] = aux1;
    //             }
    //         }
    //     }
    // }

    for(int i=0;i<qtd_linhas;i++){//inicio da impressao
        if(matriz[i].qtdCols > max_colunas){
            max_colunas = matriz[i].qtdCols;
        }
        if(matriz[i].Linha > max_linha){
            max_linha = matriz[i].Linha;
        }
    }
    printf("\n");

    for(int i=0;i<max_linha;i++){
        if(encontraLinha(i, &matriz, qtd_linhas) != -1){
            printf("%.1f", encontraLinha(i, &matriz, qtd_linhas));
        }
        else{
            printf("0.0");
        }
        for(int j=0;j<max_colunas;j++){
            
        }
        printf("\n");
    }

}

int main(){
    Linha *Matriz;
    int qtd_linhas=0;
    
    Matriz = preencheMatriz(&qtd_linhas);
    printMatriz(Matriz, qtd_linhas);

    return 0;
}