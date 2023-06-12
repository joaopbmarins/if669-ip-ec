#include <stdio.h>

int main(){
    int coord_x, coord_y, c;
    int adc_y, adc_x;

    scanf("%d %d %d", &coord_x, &coord_y, &c);

    if(coord_x > 0 && coord_y > 0){         //1º quadrante
        if(c == 1 || c == 3){
            printf("caminhada invalida\n");
        }
        else if(c == 2){    // não pode passar pelo 2º quadrante
            adc_y = coord_y + 1;
            adc_x = coord_x + 1;
            printf("%d passos em y e %d passos em x\n", adc_y, adc_x);
        }
        else if(c == 4){    // não pode passar pelo 4º quadrante
            adc_x = coord_x + 1;
            adc_y = coord_y + 1;
            printf("%d passos em x e %d passos em y\n", adc_x, adc_y);
        }
        else{
            printf("caminhada invalida\n");
        }
    }
    else if(coord_x < 0 && coord_y > 0){    //2º quadrante
        if(c == 2 || c == 4){
            printf("caminhada invalida\n");
        }
        else if(c == 1){    // não pode passar pelo quadrante 1
            adc_y = coord_y + 1;
            adc_x = (coord_x*-1) + 1;
            printf("%d passos em y e %d passos em x\n", adc_y, adc_x);
        }
        else if(c == 3){
            adc_x = (coord_x*-1) + 1;
            adc_y = coord_y + 1;
            printf("%d passos em x e %d passos em y\n", adc_x, adc_y);
        }
        else{
            printf("caminhada invalida\n");
        }
    }   
    else if(coord_x < 0 && coord_y < 0){    //3º quadrante
        if(c == 1 || c == 3){
            printf("caminhada invalida\n");
        }
        else if(c == 2){    // não pode passar pelo 2º quadrante
            adc_x = (coord_x*-1) + 1;
            adc_y = (coord_y*-1) + 1;
            printf("%d passos em x e %d passos em y\n", adc_x, adc_y);
        }
        else if(c == 4){    // não pode passar pelo 4º quadrante
            adc_y = (coord_y*-1) + 1;
            adc_x = (coord_x*-1) + 1;
            printf("%d passos em y e %d passos em x\n", adc_y, adc_x);
        }
        else{
            printf("caminhada invalida\n");
        }
    }   
    else if(coord_x > 0 && coord_y < 0){    //4º quadrante
        if(c == 2 || c == 4){
            printf("caminhada invalida\n");
        }
        else if(c == 1){
            adc_y = (coord_y*-1) + 1;
            adc_x = coord_x + 1;
            printf("%d passos em x e %d passos em y\n", adc_x, adc_y);
        }
        else if(c == 3){
            adc_y = (coord_y*-1) + 1;
            adc_x = coord_x + 1;
            printf("%d passos em y e %d passos em x\n", adc_y, adc_x);
        }
        else{
            printf("caminhada invalida\n");
        }
    }   
    else{
        printf("caminhada invalida\n");
    }

    return 0;
}