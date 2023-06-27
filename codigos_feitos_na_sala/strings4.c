#include <stdio.h>

int main(){
    char nome[100];
    scanf("%99[^\n]", nome);

    for(int i=100;i>=1;i--){
        if(nome[i] == ' ')
            for(int j=i;j<100;j++){
                printf("%c",nome[j]);
            }
            printf(",");
            for(int j=0;j<i;j++){
                printf("%c", nome[j]);
            }
        
    }


    return 0;
}
