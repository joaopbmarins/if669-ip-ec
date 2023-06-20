#include <stdio.h>

int main(){
    int x,y;
    int resto;

    int a=0, b=0;
    int divisores=0, max=0, min=0, primo = 0, div_max = 0, div_min=0;

    scanf("%d %d", &x, &y);

    for(int num = x; num<=y; num++){
        divisores = 0;
        for(int k = 2; k<=num;k++){
            if(k == 2)
                primo = 1;
            for(int j = 2; j<k; j++){
                if(k == 1)
                    primo = 1;
                else if(k == 2)
                    primo = 1;
                else if(k % j == 0)
                    primo = 0;
                else
                    primo = 1;}
            if(num % k == 0 && primo == 1){
                divisores++;
                }
    }
    //printf("%d-%d\n", x, num);

    if(num == x && divisores != 1){
        div_max = divisores;
        max = num;}
    else if(div_max == 0 && divisores >1){
        max = num;
        div_max = divisores;}
    else if(divisores>=div_max){
        min = max;
        max = num;
        div_min = div_max;
        div_max = divisores;}
    else if(divisores<=div_max){
        if(divisores<=div_min){
            min = num;
            div_min = divisores;}
        }

    //printf("%d %d\n", max, min);
    }




    while (y != 0) {
        resto = x % y;
        x = y;
        y = resto;
    }
    
    printf("%d %d %d\n", max, min, x);

    return 0;
}