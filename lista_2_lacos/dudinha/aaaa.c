#include <stdio.h>

int main(){
    long int x,y;
    long int divisores=0;
    long int primo = 1; 
    int ult_divisor = 0, num_parcial, p, k, primeiro_divisor = 0, q = 0;
    int naoconta = 0; 
    scanf("%ld %ld %d", &x, &y, &p);

    for(int num = x; num<y; num++){
        divisores = 0;
        num_parcial = num;
        do{
            int divide = 1;
            int k = 2;
            while(divide == 1) {
                if(num_parcial % k == 0){ 
                    num_parcial = num_parcial/k;
                    for(int i=k-1; i>1; i--) {
                        if(k%i == 0) {
                            primo = 0;
                        }
                    } 
                    if(k%2 != 0 && primo == 1 && ult_divisor == k) {
                        naoconta = 1; 
                    }
                    if(k%2 != 0 && ult_divisor != k){ 
                        if(primo == 1)
                            divisores++;
                        ult_divisor = k;
                    }
                    
                    divide = 0;
                    primo = 1;
                } else {
                    k++;
                }
                
            }
        
        } while(num_parcial>1);
        if(divisores == p && primeiro_divisor == 0 && naoconta == 0){
            primeiro_divisor = num;
        }
        else if(divisores == p && primeiro_divisor != 0 && naoconta == 0){
            q++;
        }       
        
        naoconta = 0;
    }//fim do primeiro for
    if(primeiro_divisor == 0){
        printf("Poxa dudinha, me desculpa, nao achei os numeros mas vou te mandar uma foto de um gatinho fofo.\n");
    }
    else{
        printf("%d %d\n", primeiro_divisor ,q);
    }
    

    return 0;
}