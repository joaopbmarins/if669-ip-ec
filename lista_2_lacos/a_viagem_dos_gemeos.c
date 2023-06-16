#include <stdio.h>

int main()
{
    int num, total=0, par=0, letra = 0, linhas_feitas = 0;
    scanf("%d", &num);
    if(num%2 == 0) {
        par = 1; 
    }
    for(int i=1; i<=num;i++){ //esse laço ta certo
        for(int j=0; j<num;j++){
            if(j<num-i){
                printf(".");
            } else {
                if(i==1)
                    printf("&");
                else if(i>1 && linhas_feitas == 2){
                    linhas_feitas = 1;
                    letra = 1;
                    printf("&");
                }
                else if(i>1 && letra == 0 && linhas_feitas != 2){
                    printf("&");
                    letra = 1;
                }
                else if(i>1 && letra == 1 && linhas_feitas != 2){
                    printf("-");
                    letra = 0;
                }
            }
        }
        linhas_feitas++;
        printf("\n");
    }
    for(int i=0; i<num; i++) {
        printf("#");
    }
    return 0;
}
