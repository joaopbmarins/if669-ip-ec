#include <stdio.h>
#include <string.h>

typedef struct{
    char pokemon[100];
    char tipo[1000];
    int ataque;
    int defesa;
    int efetivo; // 1 super efetivo; 0 normal; -1 não efetivo;
} Pokemon;

int main(){
    Pokemon inimigo;
    scanf("%s %s %d %d", inimigo.pokemon, inimigo.tipo, &inimigo.ataque, &inimigo.defesa);
    int n;
    scanf("%d", &n);
    Pokemon ash[n];
    for(int i=0;i<n;i++){
        scanf("%s %s %d %d", ash[i].pokemon, ash[i].tipo, &ash[i].ataque, &ash[i].defesa);
        if()
    }


    return 0;
}