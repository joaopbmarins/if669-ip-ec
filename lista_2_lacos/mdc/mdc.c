#include <stdio.h>


int main(){
    long int x,y, resto, nao_primo = 0, mdc = 1, a=0, b=0, divisores=0, max=0, min=0, intervalo;

    scanf("%ld %ld", &x, &y);
    resto = x % y;
    intervalo = (y>x)?y:x;

    for(int num = 0; num<=intervalo; num++){//calcula a e b
        for(int i = 2; i<num; i++){
            if(num % i == 0){
                nao_primo = 1;
                //printf("%d é divisivel por %d.\n", num, i);
                divisores++;
                }
            else if(num == i){
                divisores++;
            }
    } 
        if(max<divisores){
            min = max;
            max = divisores;
            b = a;
            a = num;}
        divisores = 0;
    }



    while(y>1){
        for(int num = 1; num <=y; num++){//for que dá os numeros
            nao_primo = 0;
            for(int k = 2; k<=num; k++){ // for que descobre se o numero é primos
                if(num % k == 0 && num != k){
                    nao_primo = 1;
                    //printf("%d é divisivel por %d\n", num, k);
                    }
                else if(num == k);
                else if(nao_primo == 1){
                    //printf("%d nao é divisivel por %d\n", num, k);
                    }}
            if(nao_primo == 0){
                //printf("%d é primo.\n", num);
                if(y%num == 0 && resto%num == 0){
                    y = y/num;
                    resto = resto/num;
                    mdc = num * mdc;
                    }
                else if(y%num == 0 && resto%num != 0){
                    y = y/num;
                    }
                    }
    }
    }
    printf("%ld %ld %ld\n", a, b, mdc);

    return 0;
}
