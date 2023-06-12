#include <stdio.h>

int main(){
    int dia, mes, ano, n;

    scanf("%d %d %d", &dia, &mes, &ano);

    if(ano >= 1900 && ano <= 2100){
        if(mes >= 1 && mes <= 12){
            if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
                n = 31;
            }
            else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
                n = 30;
            }
            else if((mes == 2 && (ano % 4 == 0) && (ano % 100 != 0) || ((ano % 100) == 0 && (ano % 400) == 0))){
                n = 29;
            }
            else if(mes == 2){
                n = 28;
            }
            else{
                printf("invalida\n");
            }
            if(dia >= 1 && dia <= n){
                printf("valida\n");
            }
            else{
                printf("invalida\n");
            }
        }
        else{
            printf("invalida\n");
        }
    }
    else{
        printf("invalida\n");
    }
    return 0;
}