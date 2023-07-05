#include <stdio.h>
#include <string.h>
#define MAX_SEQ_LED 61
#define MAX_CASOS_TESTE 1001

int main(){
    char leds[MAX_CASOS_TESTE][MAX_SEQ_LED] = {};
    char leds_final[60060] ={}; 
    int testes, flashs[MAX_CASOS_TESTE], tam_seq, atualizar_prox=0;
    int i,j,k;

    scanf("%d", &testes);

    for(i=0;i<testes;i++){
        scanf(" %s %d", leds[i],&flashs[i]);

        tam_seq = strlen(leds[i]);
        
        for(k=0;k<flashs[i];k++){// quantidade de vezes q vai testar os leds
            for(j=0;j<tam_seq;j++){//vai pecorrer o tamanho de led conferindo cada estado do led
                if(j==0){
                    if(leds[i][j] == 'X'){//ligou a led
                        leds[i][j] = 'O';
                    }
                    else if(leds[i][j] == 'O'){//desligou a led
                        leds[i][j] = 'X';
                        atualizar_prox = 1;
                    }
                }
                else if(j>0 && atualizar_prox==1){
                    atualizar_prox = 0;
                    if(leds[i][j] == 'X'){//ligou a led
                        leds[i][j] = 'O';
                    }
                    else if(leds[i][j] == 'O'){//desligou a led
                        leds[i][j] = 'X';
                        atualizar_prox = 1;
                    }
                }
            }
        }
        
    }// daqui pra cima tudo certo

    for(j=0;j<testes;j++){
        printf("%s\n", leds[j]);
        if(j==0)//caso seja o primeiro led só vai adicionar ele na sequencia final
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