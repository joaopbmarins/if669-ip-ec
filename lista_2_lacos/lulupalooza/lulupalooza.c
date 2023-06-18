#include <stdio.h>

int main(){
    int num_recebido, n_canais, f1, f2;
    scanf("%d %d", &num_recebido, &n_canais);

    for(int i=0; i<n_canais; i++){//laço para cada canal 
        scanf("%d %d", &f1 ,&f2);
        while(! (num_recebido < f2 && num_recebido > f1)){
            f1 = f1 + f2;
        }
    }
    


    return 0;
}