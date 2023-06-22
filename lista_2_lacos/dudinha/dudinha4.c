#include <stdio.h>

int main(){
    long int x,y;
    long int divisores=0;

    int ult_divisor = 0, num_parcial, p, k, primeiro_divisor = 0, q = 0;

    scanf("%ld %ld %d", &x, &y, &p);

    for(int num = x; num<y; num++){
        divisores = 0;
        ult_divisor = 0;
        num_parcial = num;
        do{
            int divide = 1;
            for(k=2; divide == 1;k++){        
                if(num_parcial % k == 0){
                    num_parcial = num_parcial/k;
                    if(k%2 != 0 && ult_divisor != k){
                        divisores++;
                        ult_divisor = k;
                        //printf("%d %d", num_parcial, k);
                        //if(num == 207)
                            //printf("-%d\n",k);
                    }
                    else if(k%2 != 0 && ult_divisor == k){
                        divisores=0;
                        ult_divisor = 0;
                        num_parcial = 1;
                    }
                    divide = 0;
                }
                }
        }
        while(num_parcial>1);
        if(divisores == p && primeiro_divisor == 0){
            primeiro_divisor = num;
        }
        else if(divisores == p && primeiro_divisor != 0){
            q++;
        }       

    }//fim do primeiro for
    if(primeiro_divisor == 0){
        printf("Poxa dudinha, me desculpa, nao achei os numeros mas vou te mandar uma foto de um gatinho fofo.\n");
    }
    else{
        printf("%d %d\n", primeiro_divisor ,q);
    }
    

    return 0;
}
