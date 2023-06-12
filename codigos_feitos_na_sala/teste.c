#include <stdio.h>
#include <math.h>

int main(){
    float nota1, nota2, media;
    scanf("%f %f", &nota1, &nota2);
    media = (nota1 + nota2)/2.0;
    printf("%f", media);
    return 0;
}