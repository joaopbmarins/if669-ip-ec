#include <stdio.h>

int main(){
int n_testes;
int tamvetor;
int vetor[100];
int sequencia = 0, sequenciarecorde = 0, oversequencia = 0, overrecorde = 0,  j;
    scanf("%d", &n_testes);

    for(int i = 0;i<n_testes;i++){
        scanf("%d", &tamvetor);
        for(int k = 0;k<tamvetor;k++){
            scanf("%d", &vetor[k]);
        }
        for(j = 0;j<tamvetor-1;j++){
            if(vetor[j]>vetor[j+1]){
                sequencia++;
                if(sequencia>sequenciarecorde)
                    oversequencia = 0;
                else
                    oversequencia++;
            }
            else{
                if(sequencia>sequenciarecorde){
                    sequenciarecorde = sequencia;
                    overrecorde = oversequencia;
                    oversequencia = 0;
                }
                    
                sequencia = 0;
                oversequencia++;
            }
        }
        if(sequencia>=sequenciarecorde){
            sequenciarecorde = sequencia;
            overrecorde = oversequencia;
        }
        if(sequenciarecorde == 0)
            sequenciarecorde = sequencia;
        if(sequenciarecorde == 0)
            printf("%d", sequenciarecorde);
        else{
            printf("%d\n", sequenciarecorde+1);
            for(int k = j-sequenciarecorde-overrecorde;k<j-overrecorde+1;k++){
                printf("%d ", vetor[k]);
        }
        }
        overrecorde = 0;
        oversequencia = 0;
        sequencia = 0;
        sequenciarecorde = 0;
        j = 0;
        printf("\n");
    }

    return 0;
}