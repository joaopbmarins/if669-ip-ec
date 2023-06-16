#include <stdio.h>

int main()
{
    int num, total=0, par=0, letra = 0, linhas_feitas = 0, c = 0, dinheiro = 0;
    scanf("%d", &num);
    if(num%2 == 0) {
        par = 1; 
    }
    for(int i=1; i<=num;i++){ 
        for(int j=0; j<num;j++){
            if(j<num-i){
                printf(".");
            } else {
                if(i==1){
                    printf("&");
                    dinheiro += 200;
                }
                else if(i>1 && linhas_feitas == 2){
                    linhas_feitas = 1;
                    letra = 1;
                    printf("&");
                    dinheiro += 200;
                }
                else if(i>1 && letra == 0 && linhas_feitas != 2){
                    printf("&");
                    letra = 1;
                    dinheiro += 200;
                }
                else if(i>1 && letra == 1 && linhas_feitas != 2){
                    printf("-");
                    dinheiro += 50;
                    letra = 0;
                }
            }
        }

        for(int j = 0; j<num;j++){
            if(j<i-1){
                if(i==1);
                else if(i>1 && linhas_feitas == 2){
                    linhas_feitas = 1;
                    letra = 1;
                    printf("&");
                    dinheiro += 200;
                }
                else if(i>1 && letra == 0 && linhas_feitas != 2){
                    printf("&");
                    dinheiro += 200;
                    letra = 1;
                    c++;
                }
                else if(i>1 && letra == 1 && linhas_feitas != 2){
                    printf("-");
                    dinheiro += 50;
                    letra = 0;
                    c++;
                }
            }
            else if(j-c<num-i){
                printf(".");
            }
        }
        linhas_feitas++;
        c = 0;
        printf("\n");
    }
    for(int i=0; i<(num*2)-1; i++) {
        printf("#");
        dinheiro += 100;
    }
    printf("\nO valor total foi: %d", dinheiro);
    return 0;
}
