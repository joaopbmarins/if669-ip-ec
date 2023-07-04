#include <stdio.h>
#include <string.h>
#define TAM_senha 100

int main(){
    char senha[TAM_senha] = {};
    char senha_final[TAM_senha] = {};
    int qtd_senhas, qtd_senha_final =0,valido = 1, i,j;

    scanf("%d", &qtd_senhas);
    for(i=0;i<qtd_senhas;i++){// i é qual senha estamos
       scanf(" %99[^\n]", senha);

        for(j=0;senha[j] != '\0';j++){// j é qual char estamos
            if((senha[j] >= 'A' && senha[j] <= 'Z') || (senha[j] >= '0' && senha[j] <= '9')){
                if(senha[j] == '0')
                    senha[j] = '6';
                else if(senha[j] == '1')
                    senha[j] = '7';
                else if(senha[j] == '2')
                    senha[j] = '9';
                else if(senha[j] == '3')
                    senha[j] = '8';
                else if(senha[j] == '4')
                    senha[j] = 'A';
                else if(senha[j] == '5')
                    senha[j] = '2';
                else if(senha[j] == '6')
                    senha[j] = 'B';
                else if(senha[j] == '7')
                    senha[j] = 'F';
                else if(senha[j] == '8')
                    senha[j] = '1';
                else if(senha[j] == '9')
                    senha[j] = 'C';
                else if(senha[j] == 'A')
                    senha[j] = '0';
                else if(senha[j] == 'B')
                    senha[j] = 'D';
                else if(senha[j] == 'C')
                    senha[j] = 'E';
                else if(senha[j] == 'D')
                    senha[j] = '3';
                else if(senha[j] == 'E')
                    senha[j] = '5';
                else if(senha[j] == 'F')
                    senha[j] = '4';
            }
            else{
                valido = 0;
            }
        }
        qtd_senha_final += strlen(senha);
        strcat(senha_final, "-");
        strcat(senha_final, senha);
    }
    if(valido == 1)
        printf("%s %d", senha_final, qtd_senha_final);
    else
        printf("Alguma senha eh invalida!\n");

    return 0;
}