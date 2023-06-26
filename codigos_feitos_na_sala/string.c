#include <stdio.h>
#include <string.h>

int main(){
    char nome[50]; // '\0'
    printf("Digite um nome: ");
    //scanf(" %49[^\n]", nome);
    fgets(nome, 49, stdin);
    printf("Nome: %s\n", nome);

    return 0;
}
