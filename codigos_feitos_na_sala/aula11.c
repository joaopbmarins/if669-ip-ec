#include <stdio.h>
#include <math.h>

int main(){
    int a = 10;
    int b;

    if (a % 2 == 0){
        b= 5;
    }
    else if(a % 2 == 1){
        b = 10;
    }

    b = (a % 2 == 0) ? 5 : 10;
    //(condição logica) ? valor1 : valor2;

//------------------------------------------------------------------------------------------------------//

    if (a % 2 == 0){
        b= 5;
    }
    else if(a % 2 == 1){
        b = 10;
    }
    else{
        b = 15;
    }

    b = (a == 0) ? 5 : ((a == 1) ? 10 : 15);
    //(condição logica) ? valor1 : ((condição logica) ? valor2 : valor3)

    printf("%d\n", b);


    return 0;
}