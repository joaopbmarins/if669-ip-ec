#include <stdio.h>

int main(){
    long int n,k_q;
    int p, q;

    int p_calculado = 0, nao_primo = 0, i;

    scanf("%ld %ld %d", &n, &k_q, &p);

    for(int u=n; u<k_q;u++){
        i = u;
        while(i>1){
            for(int j = 2; j<i;j++){
                for(int k = 2; k<j; k++){//verifica se j é primo
                    if(j==2)
                        nao_primo = 0;
                    else if(j % k == 0)
                        nao_primo = 1;
                    else nao_primo = 0;
                    
                if(nao_primo == 0){//se j for primo 
                    i = i/j;    //divide i por j
                    if(j%2 != 0)//se j ainda for impar ele aumenta p_calculado
                        p_calculado++;
                
                }
            }
            }
            printf("%d\n",p_calculado);
        }

    }

    return 0;
}