#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Aluno: João Pedro Barbosa Marins
jpbm
Prova IP 2023.1 EC
22/08/23
*/

typedef struct{
    int linha, coluna; 
    char medic[50];
} localM;

typedef struct{
    char medic[50];
    int qtdM;
}TMed;

typedef struct{
    int qtd;
    TMed *medicamento;
} pedido;

/*  finado struct coliseu que marcela disse para nao usar e sim o tmed no lugar
typedef struct{
    int qtd_medicamentos;
} coliseu;
*/

/*
Marcela falou que o estoque é para ter o valor zero e só mudar para 20 caso o medicamento exista no arquivo config.txt
Para facilitar isso fiz uma funcao extra que recebe o vetor config e o estoque e já preenche com o valor 20 caso exista 
*/


localM *carregaConfig(int *tamC);
pedido *carregaPedidos(int *tamP);
TMed **inicializa();
void processaPedido(pedido meuPedido, TMed **estoque, localM *config, int tamC);
void processaPedidos(pedido *todosPedidos, int tamP, TMed **estoque, localM *config, int tamC);

void atualizaEstoque(TMed **estoque, localM *config, int tamC);//funcao extra que colocar o valor 20 em uma celula do estoque se essa celula existir no config.txt

int main(){
    localM *config;
    TMed **estoque;
    pedido *pedidos;
    int tamC = 0, tamP = 0;

    config = carregaConfig(&tamC);   
    pedidos = carregaPedidos(&tamP);
    estoque = inicializa();
    atualizaEstoque(estoque, config, tamC);
    processaPedidos(pedidos, tamP, estoque, config, tamC);

    free(config);
    for(int i=0;i<tamP;i++) free(pedidos[i].medicamento);
    free(pedidos);
    for(int i=0;i<20;i++) free(estoque[i]);
    free(estoque);

    return 0;
}

localM *carregaConfig(int *tamC){
    FILE *arq;
    int linha, coluna;
    char medic[50];
    localM *linhamatriz = NULL;

    arq = fopen("config.txt", "r");
    if(arq == NULL){
        printf("erro na abertura do arquivo");
        exit(1);
    }
    //ler o arquivo e preenche o ponteiro linhamatriz dinamicamente ate o eof do arquivo
    while(!feof(arq)){
        fscanf(arq, "%d %d %49[^\n]\n", &linha, &coluna, medic);
        localM *aux = linhamatriz; 
        linhamatriz = (localM *) realloc(linhamatriz, sizeof(localM) * (*tamC + 1));
        if(linhamatriz == NULL){
            printf("Erro na alocacao de memoria");
            free(aux);
            exit(1);
        }
        //preenchendo
        linhamatriz[*tamC].linha = linha;
        linhamatriz[*tamC].coluna = coluna;
        strcpy(linhamatriz[*tamC].medic, medic);
        *tamC += 1;
    }
    fclose(arq);
    return linhamatriz;
}

pedido *carregaPedidos(int *tamP){
    FILE *bin;
    int tam_vetor_bin;// quantidade de medicamentos dentro de um unico pedido
    pedido *pedidos = NULL;

    bin = fopen("naoseionome.bin", "rb");
    if(bin == NULL){
        printf("Erro na abertura do arquivo binario");
        exit(1);
    }
    //ler o arquivo binario guardando seus valores no ponteiro dinamico pedidos até o eof 
    while(!feof(bin)){
        fread(&tam_vetor_bin, sizeof(int),1,bin);        
        pedido *aux = pedidos;
        pedidos = (pedido *) realloc(pedidos, sizeof(pedido)* (*tamP + 1));
        if(pedidos == NULL){
            printf("erro na alocacao");
            free(aux);
            exit(1);
        }
        pedidos[*tamP].qtd = tam_vetor_bin;
        pedidos[*tamP].medicamento = (TMed *) malloc(sizeof(TMed)*tam_vetor_bin);
        if(pedidos[*tamP].medicamento == NULL){
            printf("erro de alocacao");
            free(pedidos);
        }
        for(int i=0;i<tam_vetor_bin;i++){
            char nome_med[50];
            int qtd_m;
            fseek(bin, 16, SEEK_CUR);//corrige o ponto de leitura para ficar nas variaveis do struct
            fread(nome_med, sizeof(char), 50, bin);
            fread(&qtd_m, sizeof(int), 1, bin);
            pedidos[*tamP].medicamento[i].qtdM = qtd_m;
            strcpy(pedidos[*tamP].medicamento[i].medic, nome_med);
        }
        *tamP += 1;
    }
    fclose(bin);
    return pedidos;
}

TMed **inicializa(){
    TMed **Coliseu = NULL;
    TMed **aux = Coliseu;
    Coliseu = (TMed **) malloc(sizeof(TMed *) * 20);//aloca 20 linhas dinamicamente
    if(Coliseu == NULL){
        printf("erro na alocacao");
        free(aux);
        exit(1);
    }
    int qtd_coluna = 20;//contador para ir incrementando a qtd de colunas de 2 em 2
    for(int i=0;i<20;i++){
        Coliseu[i] = (TMed *) malloc(sizeof(TMed) * qtd_coluna);//pecorre cada coluna alocando um TMed
        for(int j=0;j<qtd_coluna;j++){
            Coliseu[i][j].qtdM = 0; //guarda o valor zero no qtd de medicamentos da coluna
        }
        qtd_coluna += 2;
    }

    return Coliseu;
}

void processaPedido(pedido meuPedido, TMed **estoque, localM *config, int tamC){
    //config vai dizer onde está cada medicamento
    //pedido vai dizer qual medicamento ele quer e quantos ele vai querer
    //TMed também é o estoque de medicamentos
    int coluna, linha;
    FILE *arq;

    arq = fopen("pedidos.txt", "a");//append para sempre colocar no final do arquivo 
    if(arq == NULL){
        printf("erro na abertura do arquivo");
        exit(1);
    }
    for(int i=0;i<meuPedido.qtd;i++){
        for(int j=0;j<tamC;j++){
            if(strcmp(meuPedido.medicamento[i].medic, config[j].medic)==0){//pecorrer dentro de um pedido todos os medicamentos solicitados procurando seu valor correspondente dentro do config para achar sua linha e coluna dentro do estoque 
                linha = config[j].linha;
                coluna = config[j].coluna;
                fprintf(arq,"separei %d unidades do medicamento %d\n", meuPedido.qtd, estoque[linha][coluna].qtdM);
                estoque[linha][coluna].qtdM -= meuPedido.qtd;
            }
        }
    }
    
    fclose(arq);
}

void processaPedidos(pedido *todosPedidos, int tamP, TMed **estoque, localM *config, int tamC){
    FILE *arq;

    for(int i=0;i<tamP;i++){
        arq = fopen("pedidos.txt", "a");//append para sempre colocar no final do arquivo 
        if(arq == NULL){
            printf("erro na abertura do arquivo");
            exit(1);
        }
        for(int j=0;j<70;j++){
            fprintf(arq, "+");
        }
        fprintf(arq, "\n");
        fclose(arq);//fechando o arquivo para nao dar conflito quando ele for aberto na funcao processaPedido
        processaPedido(todosPedidos[i], estoque, config, tamC);
    }

}

void atualizaEstoque(TMed **estoque, localM *config, int tamC){// funcao extra para preencher o estoque com a qtd 20 caso o medicamento exista no arquivo config.txt
    for(int i=0;i<tamC;i++){
        estoque[config[i].linha][config[i].coluna].qtdM = 20;
        strcpy(estoque[config[i].linha][config[i].coluna].medic, config[i].medic);
    }
}