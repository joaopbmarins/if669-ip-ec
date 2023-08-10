#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[30];
    int ataque, defesa;
}Pokemon;

typedef struct{
    char nome[30];
    Pokemon *pokebola;
    int nPokemons, pontuacao;
}Treinador;

Treinador *addTreinador(Treinador *treinadores, int *qtdCompetidores){
    char nome[30];
    printf("Qual vai ser o nome do treinador? ");
    scanf(" %29[^\n]", nome);
    Treinador *aux = treinadores;
    treinadores = (Treinador *) realloc(treinadores, (*qtdCompetidores+1)*sizeof(Treinador));
    if(treinadores==NULL){printf("problema de alocacao.\n"); free(aux); exit(1);}
    strcpy(treinadores[*qtdCompetidores].nome, nome);
    treinadores[*qtdCompetidores].pokebola = NULL;
    treinadores[*qtdCompetidores].nPokemons = 0;
    treinadores[*qtdCompetidores].pontuacao = 0;
    (*qtdCompetidores)++;
    return treinadores;
}
Treinador *addPokemon(Treinador *treinadores, char *nomeTreinador, Pokemon pokemon, int qtdCompetidores){
    for(int i=0;i<qtdCompetidores;i++){
        if(strcmp(treinadores[i].nome, nomeTreinador) == 0){
            Pokemon *aux = treinadores[i].pokebola;
            treinadores[i].pokebola = (Pokemon *) realloc(treinadores[i].pokebola, (treinadores[i].nPokemons+1)*sizeof(Pokemon));
            if(treinadores[i].pokebola == NULL){printf("Problema de alocacao\n"); free(aux); free(treinadores); exit(1);}
            treinadores[i].pokebola[treinadores[i].nPokemons] = pokemon;
            treinadores[i].nPokemons += 1;
            return treinadores;
        }
    }
}
Treinador *removeTreinador(Treinador *treinadores, int *qtdCompetidores, int indexTreinador){
    Treinador aux, *aux1=treinadores;
    if(indexTreinador != *qtdCompetidores-1){
        aux = treinadores[indexTreinador];
        treinadores[indexTreinador] = treinadores[*qtdCompetidores-1];
        treinadores[*qtdCompetidores-1] = aux;
    }
    treinadores = (Treinador *) realloc(treinadores, (*qtdCompetidores-1)*sizeof(Treinador));
    if(treinadores == NULL){printf("problema de alocacao.\n");free(aux1); exit(1);}
    (*qtdCompetidores)--;
    return treinadores;
}
char *batalha(Treinador **treinadores, char *nomeCompetidor1, char *nomeCompetidor2, int indexPokemon1, int indexPokemon2, int *qtdCompetidores){
    int indexTreinador1, indexTreinador2;
    for(int i=0;i<*qtdCompetidores;i++){
        if(strcmp((*treinadores)[i].nome, nomeCompetidor1)==0){
            indexTreinador1 = i;
        }
        if(strcmp((*treinadores)[i].nome, nomeCompetidor2)==0){
            indexTreinador2 = i;
        }
    }
    int delta1 = (*treinadores)[indexTreinador1].pokebola[indexPokemon1].ataque - (*treinadores)[indexTreinador2].pokebola[indexPokemon2].defesa;
    int delta2 = (*treinadores)[indexTreinador2].pokebola[indexPokemon2].ataque - (*treinadores)[indexTreinador1].pokebola[indexPokemon1].defesa;
    
    int indexVencedor;

    if(delta1 > delta2){
        (*treinadores)[indexTreinador2].pontuacao -= 1;//treinador 1 ganhou
        indexVencedor = indexTreinador1;
    }
    else{
        (*treinadores)[indexTreinador1].pontuacao -= 1;//treinador 2 ganhou
        indexVencedor = indexTreinador2;
    }

    if((*treinadores)[indexTreinador2].pontuacao == -5){
        (*treinadores) = removeTreinador(*treinadores, qtdCompetidores, indexTreinador2);
    }
    if((*treinadores)[indexTreinador1].pontuacao == -5){
        (*treinadores) = removeTreinador(*treinadores, qtdCompetidores, indexTreinador1);
    }
    return (*treinadores)[indexVencedor].nome;
}

int main(){
    Treinador *treinadores=NULL;
    int menu=1, qtdCompetidores=0;

    do
    {
        printf("\nDigite o número correspondente a função desejada das opções abaixo:\n");
        printf("\t1)Adicionar Competidor\n\t2)Adicionar Pokemon\n\t3)Batalhar\n\t4)Sair do programa\n");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            /* code */
            break;
        
        case 2:
            /* code */
            break;

        case 3:
            /* code */
            break;

        case 4:
            printf("Encerrando programa.\n");
            menu = 10;
            break;
   
        default:
            printf("Opção invalida.");
            menu = 1;
            break;
        }
    } while (menu != 10);
    
    for(int i=0;i<qtdCompetidores;i++){
        free(treinadores[i].pokebola);
    }
    free(treinadores);

    return 0;
}