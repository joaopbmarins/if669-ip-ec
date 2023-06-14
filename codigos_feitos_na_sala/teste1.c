#include <stdio.h>
#include <math.h>

int main(){
    float resp, x, prec, cima, lado;
    int n;

    n = 0;
    x = 0.89;
    prec = 0.001;
    cima = -1.0;
    lado = x;

    for(int a = 0;a<=5;a++){
        //for(int i = a;i>1;i--){
            cima = pow(cima,a);
            lado = pow(lado,(a+1));
        //}
        resp = (cima/(a+1))*lado;
        printf("%f %f %f\n", cima, lado, resp);
        x = resp;
    }

    printf("%f %f %f\n", cima, lado, resp);
    printf("%f\n", resp);

    return 0;
}