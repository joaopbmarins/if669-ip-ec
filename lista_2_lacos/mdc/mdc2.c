#include <stdio.h>

int main(){
    long int x,y;
    long int resto;

    long int a=0, b=0;
    long int divisores=0, max=0, min=0, primo = 0, div_max = 0, div_min=0;

    scanf("%ld %ld", &x, &y);

    for(int num = x; num<=y; num++){
        divisores = 0;
            if(num == 2)
                primo = 1;
            for(int j = 2; j<num; j++){
                if(num == 1)
                    primo = 1;
                else if(num == 2)
                    primo = 1;
                else if(num % j == 0)
                    primo = 0;
                else
                    primo = 1;}
            for(int k=2; k<num;k++){         
                if(num % k == 0 && primo == 1){
                    divisores++;
                }}
    
    //printf("%d-%d\n", x, num);
    if(num==4)
        printf("%d-%d\n", num, divisores);


    if(divisores==0)
        continue;
    else if(num == x && divisores != 1){
        div_max = divisores;
        max = num;}
    else if(div_max == 0 && divisores >1){
        max = num;
        div_max = divisores;}
    else if(div_max == divisores && max<num){
        continue;
    }
    else if(divisores>=div_max){
        min = max;
        max = num;
        div_min = div_max;
        div_max = divisores;}
    else if(divisores<div_max){
        if(divisores<div_min){
            min = num;
            div_min = divisores;}
        }
        else if(divisores<= div_min && min <= num){
            div_min = divisores;
            min = num;
    }
    //printf("%d %d\n", max, min);
    }


    long int mdc = max;
    long int mdc2 = min;

    while (mdc2 != 0) {
        resto = mdc % mdc2;
        mdc = mdc2;
        mdc2 = resto;
    }
    
    printf("%ld %ld %ld\n", max, min, mdc);

    return 0;
}
