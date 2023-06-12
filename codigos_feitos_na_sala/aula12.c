#include <stdio.h>

int main(){
    
    char letra;

    printf("Digite uma letra: ");
    scanf(" %c", &letra);


    switch (letra){  //se variavel for igual ao valor ele vai entrar no case desse valor 

        case 'a':
            printf("Caso 1\n");
            break;

        case 'b':
            printf("Caso 2\n");
            break;

        default:    // e se nn tiver nenhuma correspondencia ele vai entrar no default
            printf("vc está no default\n");
    }

    return 0;
}