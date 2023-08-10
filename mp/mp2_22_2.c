#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    char Placa[6];
}Caminhao;

typedef struct{
    int codigo;
    float loc_x, loc_y;
    Caminhao *caminhao;
    int n_caminhao;
}Filial;

typedef struct{
    float origem_x, origem_y;
    float destino_x, destino_y;
}Produto;

Caminhao remover_caminhao(Filial *filiais, int codigo_filial){
    Caminhao ultimo_caminhao, *aux;
    ultimo_caminhao = filiais[codigo_filial].caminhao[filiais[codigo_filial].n_caminhao-1];
    filiais[codigo_filial].caminhao = (Caminhao *) realloc(filiais[codigo_filial].caminhao, (filiais[codigo_filial].n_caminhao-1) * sizeof(Caminhao));
    //if(filiais[codigo_filial].caminhao == NULL){printf("Problema de alocacao."); free(aux); exit(1);}
    filiais[codigo_filial].n_caminhao -= 1;
    printf("Caminhao removido com sucesso.\n");
    return ultimo_caminhao;
}
Filial *cadastrar_filial(Filial *filiais, int *n_filiais){
    Filial *aux;
    aux = filiais;
    filiais = (Filial *) realloc(filiais, (*n_filiais+1) * sizeof(Filial));
    if(filiais==NULL){printf("Erro na alocacao."); free(aux); exit(1);}
    filiais[*n_filiais].codigo = *n_filiais;
    printf("Qual é a posicao x e y da filial respectiviamente: ");
    scanf("%f %f", &(filiais[*n_filiais].loc_x),&(filiais[*n_filiais].loc_y));
    filiais[*n_filiais].caminhao = NULL;
    filiais[*n_filiais].n_caminhao = 0;
    printf("Filial cadastrada com sucesso.\nCodigo da Filial: %d\n", *n_filiais);
    (*n_filiais)++;
    return filiais;
}
void cadastrar_caminhao(Filial *filiais, Caminhao caminhao, int codigo_filial){
    Caminhao *aux;
    aux = filiais[codigo_filial].caminhao;
    filiais[codigo_filial].caminhao = (Caminhao *) realloc(filiais[codigo_filial].caminhao, (filiais[codigo_filial].n_caminhao+1) *sizeof(caminhao));
    if(filiais[codigo_filial].caminhao == NULL){printf("Erro na alocacao."); free(aux); free(filiais); exit(1);}
    filiais[codigo_filial].caminhao[filiais[codigo_filial].n_caminhao] = caminhao;
    filiais[codigo_filial].n_caminhao += 1;
    printf("Caminhão cadastrado com sucesso.\n");
}
void realizar_entrega(Filial *filiais, Produto produto, int n_filiais){
    float delta, delta_recorde=-1;
    int filial_proxima_origem, filial_proxima_destino;
    for(int i=0;i<n_filiais;i++){
        delta = fabs(filiais[i].loc_x - produto.origem_x) + fabs(filiais[i].loc_y - produto.origem_y);
        if(delta < delta_recorde && i!=0){
            filial_proxima_origem = i;
            delta_recorde = delta;
        }
        else if(i==0){
            filial_proxima_origem = i;
            delta_recorde = delta;
        }
    }
    delta_recorde=-1;
    for(int i=0;i<n_filiais;i++){
        delta = fabs(filiais[i].loc_x-produto.destino_x) + fabs(filiais[i].loc_y-produto.destino_y);
        if(delta < delta_recorde && i!=0){
            filial_proxima_destino = i;
            delta_recorde = delta;
        }
        else if(i==0){
            filial_proxima_destino = i;
            delta_recorde = delta;
        }
    }

    Caminhao caminhao;
    caminhao = remover_caminhao(filiais, filial_proxima_origem);//removendo caminhao
    cadastrar_caminhao(filiais, caminhao, filial_proxima_destino);//cadastrando na outra filial

}

void imprimir_filiais(Filial *filiais, int n_filiais){
    for(int i=0;i<n_filiais;i++){
        printf("Filial: %d ", filiais[i].codigo);
        printf("Caminhões:\n");
        for(int j=0;j<filiais[i].n_caminhao;j++){
            printf("\tPlaca: %s\n", filiais[i].caminhao[j].Placa);
        }
        printf("\n");
    }
}

int main(){
    int n_filiais=0;
    Filial *filiais=NULL;
    int menu=1;

    while (menu != 0){
        printf("\nSelecione o número ao lado da função desejada.\n");
        printf("1-Cadastrar filial\n2-Cadastrar caminhao\n3-Realizar entrega\n4-Imprimir filiais\n5-Sair\n");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            filiais = cadastrar_filial(filiais, &n_filiais);
            break;
        
        case 2:
            Caminhao caminhao;
            int filial_caminhao;
            printf("Por favor, digite a placa do caminhão: ");
            scanf(" %s", caminhao.Placa);
            printf("Agora digite o número da filial que terá o caminhão registrado: ");
            scanf("%d", &filial_caminhao);
            cadastrar_caminhao(filiais, caminhao, filial_caminhao);
            break;

        case 3:
            Produto produto;
            printf("Digite os valores de x e y para a origem do produto: ");
            scanf("%f %f", &produto.origem_x, &produto.origem_y);
            printf("Digite os valores de x e y para o destino do produto: ");
            scanf("%f %f", &produto.destino_x, &produto.destino_y);
            realizar_entrega(filiais, produto, n_filiais);
            break;

        case 4:
            imprimir_filiais(filiais, n_filiais);
            break;

        case 5:
            menu = 0;
            break;
        
        default:
            printf("Opção invalida. Por favor escolha outra opção.\n\n");
            menu = 6;
            break;
        }
    }

    for(int i=0;i<n_filiais;i++){
        free(filiais[i].caminhao);
    }
    free(filiais);

    return 0;
}