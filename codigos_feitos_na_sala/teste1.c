#include <stdio.h>
#include <math.h>

int main(){
    float resp, n , x, prec;

    n = 2; x = 0.89;

    do{
        resp = (pow(-1,n)/n+1)*pow(x,n+1);
        x = resp
    }
    while((x * x < C - prec) || (x * x > C + prec));
    printf("%f\n", resp);

    return 0;
}