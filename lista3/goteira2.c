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

    while(teste<altura){
        for(int i =0;i<altura;i++){
        for(int j=0;j<largura;j++){
            if(parede[i][j] == 'o' && parede[i+1][j] != '#'){
                if(i != (altura-1))
                    parede[i+1][j] = 'o';
            }
            else if(parede[i][j] == 'o' && parede [i+1][j] == '#'){
                for(int k=0;k<largura;k++){
                    if(parede[i+1][k] == '#' && parede[i+1][k-1] == '#' && parede[i+1][k+1] == '#'){
                        parede[i][k] = 'o';
                    }
                    else if(parede[i+1][k] == '#' && parede[i+1][k+1] != '#' && parede[i+1][k-1] != '#'){
                        parede[i][k] = 'o';
                        if(k != (largura-1))
                            parede[i][k+1] = 'o';
                        if(k !=0)
                            parede[i][k-1] = 'o';
                    }   
                    else if(parede[i+1][k] == '#' && (parede[i+1][k-1] != '#')){
                        parede[i][k] = 'o';
                        if(k !=0)
                            parede[i][k-1] = 'o';
                    }
                    else if(parede[i+1][k] == '#' && (parede[i+1][k+1] != '#')){
                        parede[i][k] = 'o';
                        if(k != (largura-1))
                            parede[i][k+1] = 'o';
                    }
                }
            }
        }
    }
    teste++;
    }
    

    
    for(int i=0;i<altura;i++){
        for(int j=0;j<largura;j++){
            printf("%c", parede[i][j]);
        }
        printf("\n");
    }


    return 0;
}
