#include <stdio.h>

int main(){
    int altura, largura;
    scanf("%d %d", &altura, &largura);

    char parede[altura][largura];

    for(int i=0;i<altura;i++){
        for(int j=0;j<largura;j++){
            scanf(" %c", &parede[i][j]);
        }
    }//tudo certo dai pra cima
    printf("\n");

    for(int i=0;i<altura;i++){
        for(int j=0;j<largura;j++){
            if(parede[i][j] == 'o')
                for(int k=1;k<=(j-altura)){
                    if(parede[i][k] == '#')
                    
                }
        }
        printf("\n");
    }


    return 0;
}