#include <stdio.h>

int main (){
    long int n, k, num, num_parcial;
    int p;
    int primo = 1, divisores = 0;

    scanf("%ld %ld %d", &n, &k, &p);

    for(num = n;num<k;num++){
        printf("%ld=%d\n",num,divisores);
        divisores = 0;
        num_parcial = num;

        while(num_parcial>1){
            for(int b=2; b<num;b++){
                if(b == 2)// entrega os números primos
                    primo = 1;
                for(int j = 2; j<b; j++){
                    if(b == 1)
                        primo = 1;
                    else if(b == 2)
                        primo = 1;
                    else if(b % j == 0)
                        primo = 0;
                    else
                        primo = 1;}//fim da verificação dos números primos
                printf("a");
                if(num % b == 0 && primo == 1){
                    num_parcial = num_parcial/k;
                    if(b % 2 != 0)
                        divisores++;
                }
                
                }
        }
        
    }
    printf("%d\n",divisores);

    return 0;
}