#include <stdio.h>

int main(){
    int TAM;
    scanf("%d", &TAM);
    int matriz[TAM][TAM];
    int primoscorretos[TAM];
    int primo = 1;
    int quantprimos = 0;

    for(int i=0;i<TAM;i++){
        for(int j=0;j<TAM;j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    for(int i=0;i<TAM;i++){
        for(int j=0;j<TAM;j++){
            primo = 1; 
            for(int k=matriz[i][j]-1; k>1; k--) {
                        if(matriz[i][j]%k == 0) {
                            primo = 0;
                        }
                    } 
            if(primo == 1){
                primoscorretos[quantprimos] = matriz[i][j];
                quantprimos++;
            }
        }
    }

    for(int j = 0;j<quantprimos;j++){
        for(int i = 0; i<quantprimos-j-1;i++){
            if(primoscorretos[i]>primoscorretos[i+1]){
                int tmp;
                tmp = primoscorretos[i+1];
                primoscorretos[i+1] = primoscorretos[i];
                primoscorretos[i] = tmp;
            }
        }
    }

    for(int i=0;i<quantprimos;i++){
            printf("%d ",primoscorretos[i]);
    }


    return 0;
}