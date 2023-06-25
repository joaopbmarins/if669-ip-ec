#include <stdio.h>

int main(){
int n_testes;
int tamvetor;
int vetor[100];
int sequencia = 0, sequenciarecorde = 0, oversequencia = 0, overrecorde = 0, posicao = 0,  j;
    scanf("%d", &n_testes);

    for(int i = 0;i<n_testes;i++){
        scanf("%d", &tamvetor);
        for(int k = 0;k<tamvetor;k++){
            scanf("%d", &vetor[k]);
        }
        for(j = 0;j<tamvetor-1;j++){
            if(vetor[j]>vetor[j+1]){
                sequencia++;
                oversequencia = 0;
            }
            else{
                if(sequencia>sequenciarecorde){
                    sequenciarecorde = sequencia;
                    overrecorde = oversequencia;
                    posicao = j;
                    oversequencia = 0;
                }
                    
                sequencia = 0;
                oversequencia++;
            }
        }
        if(sequencia>sequenciarecorde){
            sequenciarecorde = sequencia;
            overrecorde = oversequencia;
            posicao = j;
        }
        if(sequenciarecorde == 0)
            sequenciarecorde = sequencia;
        if(sequenciarecorde == 0)
            printf("%d", sequenciarecorde);
        else{
            printf("%d\n", sequenciarecorde+1);
            for(int k = posicao-sequenciarecorde-overrecorde;k<posicao-overrecorde+1;k++){
                printf("%d ", vetor[k]);
        }
        }
        posicao = 0;
        overrecorde = 0;
        oversequencia = 0;
        sequencia = 0;
        sequenciarecorde = 0;
        printf("\n");
    }

    return 0;
}