#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[100];
    int numero;
} Candidato;

typedef struct{
    Candidato *depFederal;
    Candidato *depEstadual;
    Candidato *Senador;
    Candidato *Governador;
    Candidato *Presidente;
    int qtdCandidatos[5];
} listaCandidatos;

typedef struct{
    Candidato *candidato;
    int votos_recebidos;
} TotalVoto;

typedef struct{
    char nome[100];
    char cpf[12];
} Eleitor;

listaCandidatos carregarCandidatos(char *nomeArq);//
Eleitor *carregarEleitores(char *nomeArq, int *qtdEleitores);//
int verificaCandidato(listaCandidatos listaC, Candidato candidatoAt);//
int verificaEleitor(Eleitor *listaE, Eleitor eleitorAt, int qtdEleitores);//
void apresentaResultado(TotalVoto *votos, int qtdCandidatos);
Candidato *localizaCandidato(listaCandidatos listaC, Candidato candidatoAt, char *cargo);//

int main(){
    Eleitor *listaE;
    listaCandidatos listaC;
    
    TotalVoto *votos;
    int qtdEleitores=0, menu=1, opcao=0, qtdCandidatos=0;

    while(menu==1){
        printf("\n---Carregando lista de eleitores e candidatos na urna---\n");
        listaC = carregarCandidatos("candidatos.txt");
        listaE = carregarEleitores("eleitores.txt", &qtdEleitores);
        printf("---Carregamento finalizado com sucesso---\n");
        /*
        for(int i=0;i<5;i++){
            qtdCandidatos += listaC.qtdCandidatos[i];
        }
        */
        printf("Digite o numero da funcao correspondente abaixo:\n");
        printf("1.Iniciar Votacao\n2.Apresentar parcial da votacao\n3.Finalizar o programa\n");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            int votacao = 1, voto;
            char cpf[12];
            Eleitor eleitorat;
            Candidato candidatoAt;
            while(votacao==1){
                printf("Digite o cpf do eleitor:\n");
                scanf(" %s", cpf);
                if(strcmp(cpf, "-1")==0){
                    printf("Retornando para o menu principal.\n");
                    votacao = 0;
                }
                else{
                    strcpy(eleitorat.cpf, cpf);
                    if(verificaEleitor(listaE, eleitorat, qtdEleitores) == 1){
                        printf("Digite o numero do seu candidato a Dep. Federal: ");
                        scanf("%d", &voto);
                        candidatoAt.numero = voto;
                        if(verificaCandidato(listaC, candidatoAt)==1){
                            TotalVoto *aux = votos;
                            votos = (TotalVoto *) realloc(votos, sizeof(TotalVoto) * (qtdCandidatos+1));
                            if(votos == NULL){
                                printf("Erro de alocacao");
                                free(aux);
                                free(listaE);
                                free(listaC.depFederal);
                                free(listaC.depEstadual);
                                free(listaC.Senador);
                                free(listaC.Governador);
                                free(listaC.Presidente);
                                exit(1);
                            }
                            votos[qtdCandidatos].candidato = localizaCandidato(listaC, candidatoAt, "deputada federal");
                            votos[qtdCandidatos].votos_recebidos = 1;
                            qtdCandidatos++;
                        }
                        else{
                            printf("Numero de candidado invalido. voto anulado\n");
                        }

                        printf("Digite o numero do seu candidato a Dep. Estadual: ");
                        scanf("%d", &voto);
                        candidatoAt.numero = voto;
                        if(verificaCandidato(listaC, candidatoAt)==1){
                            TotalVoto *aux = votos;
                            votos = (TotalVoto *) realloc(votos, sizeof(TotalVoto) * (qtdCandidatos+1));
                            if(votos == NULL){
                                printf("Erro de alocacao");
                                free(aux);
                                free(listaE);
                                free(listaC.depFederal);
                                free(listaC.depEstadual);
                                free(listaC.Senador);
                                free(listaC.Governador);
                                free(listaC.Presidente);
                                exit(1);
                            }
                            votos[qtdCandidatos].candidato = localizaCandidato(listaC, candidatoAt, "deputada estadual");
                            votos[qtdCandidatos].votos_recebidos = 1;
                            qtdCandidatos++;
                        }
                        else{
                            printf("Numero de candidado invalido. voto anulado\n");
                        }

                        printf("Digite o numero do seu candidato a Senador: ");
                        scanf("%d", &voto);
                        candidatoAt.numero = voto;
                        if(verificaCandidato(listaC, candidatoAt)==1){
                            TotalVoto *aux = votos;
                            votos = (TotalVoto *) realloc(votos, sizeof(TotalVoto) * (qtdCandidatos+1));
                            if(votos == NULL){
                                printf("Erro de alocacao");
                                free(aux);
                                free(listaE);
                                free(listaC.depFederal);
                                free(listaC.depEstadual);
                                free(listaC.Senador);
                                free(listaC.Governador);
                                free(listaC.Presidente);
                                exit(1);
                            }
                            votos[qtdCandidatos].candidato = localizaCandidato(listaC, candidatoAt, "senador");
                            votos[qtdCandidatos].votos_recebidos = 1;
                            qtdCandidatos++;
                        }
                        else{
                            printf("Numero de candidado invalido. voto anulado\n");
                        }

                        printf("Digite o numero do seu candidato a Governador: ");
                        scanf("%d", &voto);
                        candidatoAt.numero = voto;
                        if(verificaCandidato(listaC, candidatoAt)==1){
                            TotalVoto *aux = votos;
                            votos = (TotalVoto *) realloc(votos, sizeof(TotalVoto) * (qtdCandidatos+1));
                            if(votos == NULL){
                                printf("Erro de alocacao");
                                free(aux);
                                free(listaE);
                                free(listaC.depFederal);
                                free(listaC.depEstadual);
                                free(listaC.Senador);
                                free(listaC.Governador);
                                free(listaC.Presidente);
                                exit(1);
                            }
                            votos[qtdCandidatos].candidato = localizaCandidato(listaC, candidatoAt, "governador");
                            votos[qtdCandidatos].votos_recebidos = 1;
                            qtdCandidatos++;
                        }
                        else{
                            printf("Numero de candidado invalido. voto anulado\n");
                        }

                        printf("Digite o numero do seu candidato a Presidente: ");
                        scanf("%d", &voto);
                        candidatoAt.numero = voto;
                        if(verificaCandidato(listaC, candidatoAt)==1){
                            TotalVoto *aux = votos;
                            votos = (TotalVoto *) realloc(votos, sizeof(TotalVoto) * (qtdCandidatos+1));
                            if(votos == NULL){
                                printf("Erro de alocacao");
                                free(aux);
                                free(listaE);
                                free(listaC.depFederal);
                                free(listaC.depEstadual);
                                free(listaC.Senador);
                                free(listaC.Governador);
                                free(listaC.Presidente);
                                exit(1);
                            }
                            votos[qtdCandidatos].candidato = localizaCandidato(listaC, candidatoAt, "presidente");
                            votos[qtdCandidatos].votos_recebidos = 1;
                            qtdCandidatos++;
                        }
                        else{
                            printf("Numero de candidado invalido. voto anulado\n");
                        }
                    }
                    else{
                        printf("Eleitor nao localizado na lista de votantes da urna\n");
                    }
                }
            }
            break;

        case 2:
            apresentaResultado(votos, qtdCandidatos);
            break;

        case 3:
            printf("Finalizando o sistema de votacao...\n");
            menu = 0;
            break;
        
        default:
            printf("Opcao invalida tente novamente\n");
            break;
        }
    }
    free(votos);
    free(listaE);
    free(listaC.depFederal);
    free(listaC.depEstadual);
    free(listaC.Senador);
    free(listaC.Governador);
    free(listaC.Presidente);
    return 0;
}

Eleitor *carregarEleitores(char *nomeArq, int *qtdEleitores){
    FILE *arq;
    char cpf[12], nome[100];
    Eleitor *eleitores=NULL;
    arq = fopen(nomeArq, "r");
    if(arq == NULL){
        printf("Erro na abertura do arquivo eleitores");
        exit(1);
    }

    while(!feof(arq)){
        fscanf(arq,"%11[^,], %99[^\n]\n", cpf, nome);
        Eleitor *aux= eleitores;
        eleitores = (Eleitor *) realloc(eleitores, sizeof(Eleitor) * (*qtdEleitores+1));
        if(eleitores == NULL){
            printf("Erro na alocacao\n");
            free(aux);
            exit(1);
        }
        strcpy(eleitores[*qtdEleitores].nome, nome);
        strcpy(eleitores[*qtdEleitores].cpf, cpf);
        *qtdEleitores += 1;
    }
    fclose(arq);
    return eleitores;
}

listaCandidatos carregarCandidatos(char *nomeArq){
    FILE *arq;
    int num_candidato;
    char tipo[20], nome[100];
    listaCandidatos listaC;

    listaC.depFederal = NULL;
    listaC.depEstadual = NULL;
    listaC.Senador = NULL;
    listaC.Governador = NULL;
    listaC.Presidente = NULL;
    
    for(int i=0;i<5;i++){
        listaC.qtdCandidatos[i] = 0;
    }

    arq = fopen(nomeArq, "r");
    if(arq == NULL){
        printf("Erro na abertura do arquivo candidatos");
        exit(1);
    }

    while(!feof(arq)){
        fscanf(arq, " %19[^,], %99[^,], %d", tipo, nome, &num_candidato);

        if(strcmp("deputada federal", tipo)==0){
            Candidato *aux = listaC.depFederal;
            listaC.depFederal = (Candidato *) realloc(listaC.depFederal, sizeof(Candidato) * (listaC.qtdCandidatos[0]+1));
            if(listaC.depFederal == NULL){
                printf("erro de alocacao");
                free(aux);
                exit(1);
            }
            strcpy(listaC.depFederal[listaC.qtdCandidatos[0]].nome, nome);
            listaC.depFederal[listaC.qtdCandidatos[0]].numero = num_candidato;
            listaC.qtdCandidatos[0] += 1;
        }
        else if((strcmp("deputada estadual", tipo)==0)){
            Candidato *aux = listaC.depEstadual;
            listaC.depEstadual = (Candidato *) realloc(listaC.depEstadual, sizeof(Candidato) * (listaC.qtdCandidatos[1]+1));
            if(listaC.depEstadual == NULL){
                printf("erro de alocacao");
                free(aux);
                exit(1);
            }
            strcpy(listaC.depEstadual[listaC.qtdCandidatos[1]].nome, nome);
            listaC.depEstadual[listaC.qtdCandidatos[1]].numero = num_candidato;
            listaC.qtdCandidatos[1] += 1;
        }
        else if((strcmp("senador", tipo)==0)){
            Candidato *aux = listaC.Senador;
            listaC.Senador = (Candidato *) realloc(listaC.Senador, sizeof(Candidato) * (listaC.qtdCandidatos[2]+1));
            if(listaC.Senador == NULL){
                printf("erro de alocacao");
                free(aux);
                exit(1);
            }
            strcpy(listaC.Senador[listaC.qtdCandidatos[2]].nome, nome);
            listaC.Senador[listaC.qtdCandidatos[2]].numero = num_candidato;
            listaC.qtdCandidatos[2] += 1;
        }
        else if((strcmp("governador", tipo)==0)){
            Candidato *aux = listaC.Governador;
            listaC.Governador = (Candidato *) realloc(listaC.Governador, sizeof(Candidato) * (listaC.qtdCandidatos[3]+1));
            if(listaC.Governador == NULL){
                printf("erro de alocacao");
                free(aux);
                exit(1);
            }
            strcpy(listaC.Governador[listaC.qtdCandidatos[3]].nome, nome);
            listaC.Governador[listaC.qtdCandidatos[3]].numero = num_candidato;
            listaC.qtdCandidatos[3] += 1;
        }
        else if((strcmp("presidente", tipo)==0)){
            Candidato *aux = listaC.Presidente;
            listaC.Presidente = (Candidato *) realloc(listaC.Presidente, sizeof(Candidato) * (listaC.qtdCandidatos[4]+1));
            if(listaC.Presidente == NULL){
                printf("erro de alocacao");
                free(aux);
                exit(1);
            }
            strcpy(listaC.Presidente[listaC.qtdCandidatos[4]].nome, nome);
            listaC.Presidente[listaC.qtdCandidatos[4]].numero = num_candidato;
            listaC.qtdCandidatos[4] += 1;
        }
        
    }
    fclose(arq);
    return listaC;
}

int verificaEleitor(Eleitor *listaE, Eleitor eleitorAt, int qtdEleitores){
    for(int i=0;i<qtdEleitores;i++){
        if(strcmp(eleitorAt.cpf, listaE[i].cpf)==0){
            return 1;
        }
    }
    return 0;
}

int verificaCandidato(listaCandidatos listaC, Candidato candidatoAt){
    for(int i=0;i<listaC.qtdCandidatos[0];i++){
        if(listaC.depFederal[i].numero == candidatoAt.numero){
            return 1;
        }
    }
    for(int i=0;i<listaC.qtdCandidatos[1];i++){
        if(listaC.depEstadual[i].numero == candidatoAt.numero){
            return 1;
        }
    }
    for(int i=0;i<listaC.qtdCandidatos[2];i++){
        if(listaC.Senador[i].numero == candidatoAt.numero){
            return 1;
        }
    }
    for(int i=0;i<listaC.qtdCandidatos[3];i++){
        if(listaC.Governador[i].numero == candidatoAt.numero){
            return 1;
        }
    }
    for(int i=0;i<listaC.qtdCandidatos[4];i++){
        if(listaC.Presidente[i].numero == candidatoAt.numero){
            return 1;
        }
    }
    return 0;
}

Candidato *localizaCandidato(listaCandidatos listaC, Candidato candidatoAt, char *cargo){
    if(strcmp(cargo, "deputada federal")==0){
        for(int i=0;i<listaC.qtdCandidatos[0];i++){
            if(listaC.depFederal[i].numero == candidatoAt.numero){
                return &(listaC.depFederal[i]);
            }
        }
    }
    else if(strcmp(cargo, "deputada estadual")==0){
        for(int i=0;i<listaC.qtdCandidatos[1];i++){
            if(listaC.depEstadual[i].numero == candidatoAt.numero){
                return &(listaC.depEstadual[i]);
            }
        }
    }
    else if(strcmp(cargo, "senador")==0){
        for(int i=0;i<listaC.qtdCandidatos[2];i++){
            if(listaC.Senador[i].numero == candidatoAt.numero){
                return &(listaC.Senador[i]);
            }
        }
    }
    else if(strcmp(cargo, "governador")==0){
        for(int i=0;i<listaC.qtdCandidatos[3];i++){
            if(listaC.Governador[i].numero == candidatoAt.numero){
                return &(listaC.Governador[i]);
            }
        }
    
    }
    else if(strcmp(cargo, "presidente")==0){
        for(int i=0;i<listaC.qtdCandidatos[4];i++){
            if(listaC.Presidente[i].numero == candidatoAt.numero){
                return &(listaC.Presidente[i]);
            }
        }
    }

    return NULL;
}

void apresentaResultado(TotalVoto *votos, int qtdCandidatos){
    for(int i=0;i<qtdCandidatos;i++){
        printf("\nNome do candidato:%s\nQtd de votos recebida:%d\n", votos[i].candidato->nome, votos[i].votos_recebidos);
    }
}