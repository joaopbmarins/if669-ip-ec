#include <stdio.h>
#include <stdlib.h>

void salvaVetor(float *vet, int tam){
    FILE *arq;
    if((arq = fopen("test.bin", "w")) != NULL){
        fwrite(&tam, sizeof(int), 1, arq);
        fwrite(vet, sizeof(float), tam, arq);
        fclose(arq);
    }
}

float *carregaVetor(int *tam){
    FILE *arq;
    float *uai;
    if((arq = fopen("test.bin", "r")) != NULL){
        fread(tam, sizeof(int),1,arq);
        uai = (float *) malloc(sizeof(float) * (*tam));
        if(uai == NULL){printf("Uai, me lasquei\n"); exit(1);}
        fread(uai, sizeof(float), *tam, arq);
        fclose(arq);
    }
    return uai;
}

float *inserirVetor(float *dVet, int *tamDV, float *vet, int tamV){
    float *vTmp = dVet;
    dVet = (float *) realloc(dVet, sizeof(float) * ((*tamDV)+tamV));
    if(dVet==NULL){free(vTmp); exit(1);}
    for(int i =0;i<tamV;i++){
        dVet[(*tamDV)+i] = vet[i];
    }
    *tamDV += tamV;
    return dVet;
}

void printVetor(float *dVet, int tam){
    for(int i=0;i<tam;i++){
        printf("vet[%d]=%.2f\n", i+1, dVet[i]);
    }
}

int main(){
    float vet[] = {10,20,30,40,50}, *dVet;
    int tamV;
    //salvaVetor(vet, 5);
    dVet = carregaVetor(&tamV);
    printVetor(dVet, tamV);
    if(dVet != NULL){
        dVet = inserirVetor(dVet, &tamV, vet, 5);
        printf("Apos a insersão\n");
        printVetor(dVet, tamV);
        salvaVetor(dVet, tamV);
    }
    free(dVet);
    return 0;
}