#include <stdio.h>
#include <string.h>

typedef struct{
    char tipo[100];
    int valor;
    int performance;
}Peca;

typedef struct{
    char tipo[100];
    int valor;
    int performance;
}Lataria;

typedef struct{
    char tipo[100];
    int valor;
    int performance;
}Roda;

typedef struct{
    char tipo[100];
    int valor;
    int performance;
}Motor;

int main(){
    int dinheiro, n_pecas;
    int partes=0, dinheiro_gasto=0, perf_alcan=0;
    int qtd_motor=0, qtd_roda=0, qtd_lataria=0;
    scanf("%d %d", &dinheiro, &n_pecas);
    Peca pecas[n_pecas];
    Motor motor[n_pecas];
    Roda roda[n_pecas];
    Lataria lataria[n_pecas];

    for(int i=0;i<n_pecas;i++){ motor[i].performance = -1;motor[i].valor = -1;roda[i].performance = -1;roda[i].valor = -1;lataria[i].performance = -1;lataria[i].valor = -1;}

    for(int i=0;i<n_pecas;i++){
        scanf("%s %d %d", pecas[i].tipo, &pecas[i].valor, &pecas[i].performance);
        if(strcmp(pecas[i].tipo, "Motor")==0){
            strcpy(motor[i].tipo, pecas[i].tipo);
            motor[i].valor = pecas[i].valor;
            motor[i].performance = pecas[i].performance;
            qtd_motor++;
        }
        else if(strcmp(pecas[i].tipo, "Lataria")==0){
            strcpy(lataria[i].tipo, pecas[i].tipo);
            lataria[i].valor = pecas[i].valor;
            lataria[i].performance = pecas[i].performance;
            qtd_lataria++;
        }
        else if(strcmp(pecas[i].tipo, "Roda")==0){
            strcpy(roda[i].tipo, pecas[i].tipo);
            roda[i].valor = pecas[i].valor;
            roda[i].performance = pecas[i].performance;
            qtd_roda++;
        }
    }
    Motor aux;
    for(int i=0;i<n_pecas;i++){
        for(int j=0;j<n_pecas-i-1;j++){
            if(motor[j].performance < motor[j+1].performance){
                aux = motor[j];
                motor[j] = motor[j+1];
                motor[j+1] = aux;
            }
        }
    }
    Roda aux1;
    for(int i=0;i<n_pecas;i++){
        for(int j=0;j<n_pecas-i-1;j++){
            if(roda[j].performance < roda[j+1].performance){
                aux1 = roda[j];
                roda[j] = roda[j+1];
                roda[j+1] = aux1;
            }
        }
    }
    Lataria aux2;
    for(int i=0;i<n_pecas;i++){
        for(int j=0;j<n_pecas-i-1;j++){
            if(lataria[j].performance < lataria[j+1].performance){
                aux2 = lataria[j];
                lataria[j] = lataria[j+1];
                lataria[j+1] = aux2;
            }
        }
    }
    int recorde_perf=0, dinheiro_sobra_final=0;
    if(qtd_lataria != 0 && qtd_motor != 0 && qtd_roda != 0){
        for(int i=0;i<qtd_motor;i++){
            for(int j=0;j<qtd_roda;j++){
                for(int k=0;k<qtd_lataria;k++){
                    dinheiro_gasto = motor[i].valor + roda[j].valor + lataria[k].valor;
                    perf_alcan = motor[i].performance + roda[j].performance + lataria[k].performance;
                    if(dinheiro_gasto <= dinheiro){
                        if(perf_alcan > recorde_perf){
                            recorde_perf = perf_alcan;
                            dinheiro_sobra_final = dinheiro - dinheiro_gasto;
                        }
                    }
                }
            }
        }
        if(recorde_perf != 0){
            printf("Minha nave tem uma performance de %d pontos\n", recorde_perf);
            if(dinheiro_sobra_final > 0)
                printf("E ainda me sobraram %d mangos!\n", dinheiro_sobra_final);
        }
        else{
            printf("Nao foi possivel construir uma caranga...\n");
        }
        
    }
    else{
        printf("Nao foi possivel construir uma caranga...\n");
    }
    
    return 0;
}