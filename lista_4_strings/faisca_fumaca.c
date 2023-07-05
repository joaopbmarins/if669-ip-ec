#include <stdio.h>
#include <string.h>

int main(){
    char leds[1001][61] = {};
    char leds_final[60060] ={}; 
    int testes, flashs[1001], tam_seq, atualizar_prox=0;
    int i,j,k;

    scanf("%d", &testes);

    for(i=0;i<testes;i++){
        scanf("%s %d", leds[i],&flashs[i]);

        tam_seq = strlen(leds[i]);
        
        for(k=0;k<flashs[i];k++){
            for(j=0;j<tam_seq;j++){
                if(j==0){
                    if(leds[i][j] == 'X'){
                        leds[i][j] = 'O';
                    }
                    else if(leds[i][j] == 'O'){
                        leds[i][j] = 'X';
                        atualizar_prox = 1;
                    }
                }
                else if(j>0 && atualizar_prox==1){
                    atualizar_prox = 0;
                    if(leds[i][j] == 'X'){
                        leds[i][j] = 'O';
                    }
                    else if(leds[i][j] == 'O'){
                        leds[i][j] = 'X';
                        atualizar_prox = 1;
                    }
                }
            }
        }
        
    }// daqui pra cima tudo certo

    for(j=0;j<testes;j++){
        printf("%s\n", leds[j]);
        if(j==0)
            strcat(leds_final,leds[j]);
        else{
            if(strlen(leds_final)% 2 == 0){// se for par
                if(leds[j-1][strlen(leds[j-1])-1] == leds[j][0]){// mesmo estado
                    strcat(leds_final, "@");
                    strcat(leds_final,leds[j]);
                }
                else{//estado diferente
                    strcat(leds_final, "$");
                    strcat(leds_final,leds[j]);
                }
            }
            else{// se for impar
                if(leds[j-1][strlen(leds[j-1])-1] == leds[j][0]){// mesmo estado
                    strcat(leds_final, "#");
                    strcat(leds_final,leds[j]);
                }
                else{//estado diferente
                    strcat(leds_final, "%");
                    strcat(leds_final,leds[j]);
                }
            }
        }
    }
    printf("%s\n", leds_final);

    return 0;
}