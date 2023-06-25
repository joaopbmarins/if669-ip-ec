#include <stdio.h>

int main(){
    int TAM;

    scanf("%d", &TAM);
    int quant_corretas = 0;
    int quant_erradas = 0; 
    char placas[TAM][7];
    char corretas[TAM][7];
    char erradas [TAM][7];
    int letras = 0;
    int numeros = 0;


    for(int i=0;i<TAM;i++){
        letras = 0;
        numeros = 0;
        for(int j=0;j<7;j++){
            scanf(" %c",&placas[i][j]);
            if((int)placas[i][j] >= 65 && (int)placas[i][j] <= 90)
                letras++;
            else if((int)placas[i][j] >= 48 && (int)placas[i][j] <= 57)
                numeros++;
        }
        if(letras == 3 && numeros == 4){
            for(int j=0;j<7;j++){
                corretas[quant_corretas][j] = placas[i][j];
            }
            quant_corretas++;
        }
        else{
            for(int j=0;j<7;j++){
                erradas[quant_erradas][j] = placas[i][j];
            }
            quant_erradas++;
        }
    }

    printf("%d placas:\n", quant_corretas);
    for(int i=0;i<quant_corretas;i++){
        for(int j=0;j<7;j++){
            if(j == 6)
                printf("%c\n", corretas[i][j]);
            else 
                printf("%c", corretas[i][j]);
        }
    }
    printf("%d erros:\n", quant_erradas);
    for(int i=0;i<quant_erradas;i++){
        for(int j=0;j<7;j++){
            if(j == 6)
                printf("%c\n", erradas[i][j]);
            else
                printf("%c", erradas[i][j]);
        }
    }
    return 0;
}