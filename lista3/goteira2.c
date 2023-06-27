#include <stdio.h>

int main(){
    int altura, largura;
    scanf("%d %d", &altura, &largura);
    char parede[altura][largura];
    int teste =0;

    for(int i=0;i<altura;i++){
        for(int j=0;j<largura;j++){
            scanf(" %c", &parede[i][j]);
        }
    }//tudo certo dai pra cima
    printf("\n");

    inicio:
    for(int i =0;i<altura;i++){
        for(int j=0;j<largura;j++){
            if(parede[i][j] == 'o' && parede[i+1][j] != '#')
                parede[i+1][j] = 'o';
            else if(parede[i][j] == 'o' && parede [i+1][j] == '#'){
                for(int k=0;k<largura;k++){
                    if(parede[i+1][k] == '#' && parede[i+1][k-1] == '#' && parede[i+1][k+1] == '#')
                        parede[i][k] = 'o';
                    else if(parede[i+1][k] == '#' && (parede[i+1][k-1] != '#')){
                        parede[i][k] = 'o';
                        parede[i][k-1] = 'o';
                    }
                    else if(parede[i+1][k] == '#' && (parede[i+1][k+1] != '#')){
                        parede[i][k] = 'o';
                        parede[i][k+1] = 'o';
                    }
                }
            }
        }
    }

    
    for(int i=0;i<altura;i++){
        for(int j=0;j<largura;j++){
            printf("%c", parede[i][j]);
        }
        printf("\n");
    }
    printf("///////////////\n");
    goto inicio;


    return 0;
}
