#include <stdio.h>
#include <string.h>

typedef struct{
    char pokemon[100];
    char tipo[1000];
    float ataque;
    float defesa;
    float vantagem;
} Pokemon;

int main(){
    Pokemon inimigo;
    scanf("%s %s %f %f", inimigo.pokemon, inimigo.tipo, &inimigo.ataque, &inimigo.defesa);
    int n;
    scanf("%d", &n);
    Pokemon ash[n];
    for(int i=0;i<n;i++){
        scanf("%s %s %f %f", ash[i].pokemon, ash[i].tipo, &ash[i].ataque, &ash[i].defesa);
        if(strcmp(inimigo.tipo,"agua") == 0){
            if(strcmp(ash[i].tipo, "grama") == 0){
                ash[i].ataque = ash[i].ataque * 1.5;
            }
        }
        else if(strcmp(inimigo.tipo,"fogo") == 0){
            if(strcmp(ash[i].tipo, "agua") == 0){
                ash[i].ataque = (float)ash[i].ataque * 1.5;
            }
        }
        else if(strcmp(inimigo.tipo,"grama") == 0){
            if(strcmp(ash[i].tipo, "fogo") == 0){
                ash[i].ataque = (float)ash[i].ataque * 1.5;
            }
        }
        ash[i].vantagem = (float)ash[i].ataque - (float)inimigo.defesa;
    }
    Pokemon aux;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(strcmp(ash[j].pokemon,ash[j+1].pokemon) > 0){
                aux = ash[j];
                ash[j] = ash[j+1];
                ash[j+1] = aux;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(ash[j].vantagem < ash[j+1].vantagem){
                aux = ash[j];
                ash[j] = ash[j+1];
                ash[j+1] = aux;
            }
        }
    }

    for(int i=0;i<n;i++){
        printf("%d. %s\n", i+1, ash[i].pokemon);
        //printf("%f\n", ash[i].vantagem);
    }

    return 0;
}