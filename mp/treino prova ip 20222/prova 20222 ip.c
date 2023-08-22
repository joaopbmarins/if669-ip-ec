#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[100];
    char cpf[12];
    int qtd_notas;
    float *notas;
} Aluno;

Aluno *carregaAlunos(int *qtdAlunos);
float *leNotas(int *qtdNotas);
float media(float *notas, int qtdNotas);
void ordena(Aluno *alunos, int qtdAlunos);
void salvaAlunos(Aluno *alunos, int qtdAlunos);

int main(){
    Aluno *alunos;
    int qtdAlunos=0, ainda_tem_notas=1;

    alunos = carregaAlunos(&qtdAlunos);

    for(int i=0;i<qtdAlunos;i++){
        printf("Comece a digitar as notas do aluno %s: \n", alunos[i].nome);
        alunos[i].notas = leNotas(&(alunos[i].qtd_notas));
        printf("Indo para o proximo aluno\n");
    }
    ordena(alunos, qtdAlunos);
    salvaAlunos(alunos, qtdAlunos);
    
    for(int i=0;i<qtdAlunos;i++)
        free(alunos[i].notas);
    free(alunos);

    return 0;
}

Aluno *carregaAlunos(int *qtdAlunos){
    FILE *arq;
    Aluno *alunos=NULL;
    char cpf[12], nome[100];

    arq = fopen("alunos.txt", "r");
    if(arq == NULL){
        printf("Erro na abertura do arquivo");
        exit(1);
    }
    while(!feof(arq)){
        fscanf(arq,"%11[^,], %99[^\n]\n", cpf, nome);
        Aluno *aux = alunos;
        alunos = (Aluno *) realloc(alunos, sizeof(Aluno) * (*qtdAlunos + 1));
        if(alunos == NULL){
            printf("Erro na alocacao");
            free(aux);
            exit(1);
        }
        strcpy(alunos[*qtdAlunos].cpf, cpf);
        strcpy(alunos[*qtdAlunos].nome, nome);
        alunos[*qtdAlunos].notas = NULL;
        alunos[*qtdAlunos].qtd_notas = 0;
        (*qtdAlunos) += 1;
    }
    fclose(arq);
    return alunos;
}

float *leNotas(int *qtdNotas){
    int ainda_tem_notas=1;
    float nota, *vetorNotas = NULL;

    while(ainda_tem_notas == 1){
            printf("Digite as notas do aluno e só para quando for digitada uma nota negativa: ");
            scanf("%f", &nota);
            if(nota < 0){
                printf("\nfinalizando a inserção das notas do aluno \n");
                ainda_tem_notas = 0;
            }
            else{
                float *aux = vetorNotas;
                vetorNotas = (float *) realloc(vetorNotas, sizeof(float) * (*qtdNotas+1));
                if(vetorNotas == NULL){
                    printf("erro na alocacao de memoria.\n");
                    free(aux);
                    exit(1);
                }
                vetorNotas[*qtdNotas] = nota;
                *qtdNotas += 1;
            }
        }
    return vetorNotas;
}

float media(float *notas, int qtdNotas){
    float media = 0;
    for(int i=0;i<qtdNotas;i++)
        media += notas[i];
    
    return (media/qtdNotas);
}

void ordena(Aluno *alunos, int qtdAlunos){
    Aluno swap;
    for(int i=0;i<qtdAlunos;i++){
        for(int j=0;j<qtdAlunos-i-1;j++){
            if(media(alunos[i].notas, alunos[i].qtd_notas) < media(alunos[i+1].notas, alunos[i+1].qtd_notas)){
                swap = alunos[i];
                alunos[i] = alunos[i+1];
                alunos[i+1] = swap;
            }
        }
    }
}

void salvaAlunos(Aluno *alunos, int qtdAlunos){
    FILE *bin;

    bin = fopen("alunos.bin", "wb");
    if(bin == NULL){
        printf("Erro na criacao do arquivo binario");
        exit(1);
    }

    for(int i=0;i<qtdAlunos;i++){
        fwrite(alunos[i].cpf, sizeof(char) * 12, 1, bin);
        fwrite(alunos[i].nome, sizeof(char) * 100, 1, bin);
        fwrite(&(alunos[i].qtd_notas), sizeof(int), 1, bin);
        fwrite(alunos[i].notas, sizeof(float), alunos[i].qtd_notas, bin);
    }


    //fwrite(alunos, sizeof(Aluno), qtdAlunos, bin);

    /*
    fwrite(alunos->cpf, sizeof(char) * 12, qtdAlunos, bin);
    fwrite(alunos->nome, sizeof(char) * 100, qtdAlunos, bin);
    fwrite(alunos->qtd_notas, sizeof(int), qtdAlunos, bin);
    fwrite(alunos->notas, sizeof(float) * alunos->qtd_notas, qtdAlunos, bin);
    */
    
    fclose(bin);
}
