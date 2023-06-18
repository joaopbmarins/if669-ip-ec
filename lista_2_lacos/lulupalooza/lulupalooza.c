#include <stdio.h>

int main(){
    int num_recebido, n_canais, f1=0, f2=0, ftemp=0;
    scanf("%d %d", &num_recebido, &n_canais);

    for(int i=0; i<n_canais; i++){//laço para cada canal 
        scanf("%d %d", &f1 ,&f2);
        while(! (num_recebido <= f2 && num_recebido >= f1)){//laço para checar se o número está entre o quais f1 e f2
            printf("%d %d %d\n", f1, f2, ftemp);
            ftemp = f1 + f2;
            f1 = f2;
            f2 = ftemp;
        }
        
        printf("%d %d", f1, f2);
    }
    


    return 0;
}