#include <stdio.h>
#include <string.h>
#define TAM_PALAVRA 101
#define MAX_PALAVRA 50
#define MAX_CHAR_FRASE 5050

int main(){
    char frase1[MAX_PALAVRA][TAM_PALAVRA] = {};
    char frase2[MAX_PALAVRA][TAM_PALAVRA] = {};
    char text1[MAX_CHAR_FRASE], text2[MAX_CHAR_FRASE];
    char aux[MAX_CHAR_FRASE] = {};
    int i_antigo=0, qtd_iguais =0, qtd_frase1=0, qtd_frase2=0, qtd_total;
    int i=0,j=0,k=0;
    float plagio;
    
    scanf("%[^\n]%*c%[^\n]%*c", text1, text2);
  

    for(j=0;j<MAX_PALAVRA && i_antigo<MAX_CHAR_FRASE;j++){
        i=0;
        for(;text1[i_antigo] != ' ' && i_antigo<MAX_CHAR_FRASE && i<TAM_PALAVRA;){
            aux[i] = text1[i_antigo];
            i++; 
            i_antigo++;
        }
        i_antigo++;
        aux[i] = '\0';
        strcpy(frase1[j],aux);
        //printf("%s\n",frase1[j]);
    }
    i_antigo = 0;
    i=0;
    for(j=0;j<MAX_PALAVRA && i_antigo<MAX_CHAR_FRASE;j++){
        i=0;
        for(;text2[i_antigo] != ' ' && i_antigo<MAX_CHAR_FRASE && i<TAM_PALAVRA;){
            aux[i] = text2[i_antigo];
            i++; 
            i_antigo++;
        }
        i_antigo++;
        aux[i] = '\0';
        strcpy(frase2[j],aux);
        //printf("%s\n",frase2[j]);
    }

    for(i=0;i<MAX_PALAVRA;i++){
        if(strcmp(frase1[i],"\0") != 0){
            qtd_frase1++;
            for(j=0;j<MAX_PALAVRA;j++){
                if(strcmp(frase1[i],frase2[j]) == 0){
                    qtd_iguais++;
                }
            }
        }
        if(strcmp(frase2[i],"\0") != 0){
            qtd_frase2++;
        }
    }
    qtd_total = qtd_frase1+qtd_frase2;
    plagio = ((float)qtd_iguais/(float)qtd_total) * 100.0;

    printf("%.1f\n", plagio);

    return 0;
}
