#include <stdio.h>

int main(){
    int hora_inicial, minuto_inicial;
    printf("Horario atual: \n");
    scanf("%d %d", &hora_inicial, &minuto_inicial);
    int minuto_adc;
    printf("Minutos a serem adicionados: \n");
    scanf("%d", &minuto_adc);
    int hora_final, minuto_final;

    hora_final = (((hora_inicial * 60) + minuto_adc + minuto_inicial)/60) % 24;
    minuto_final = ((hora_inicial * 60) + minuto_adc + minuto_inicial) % 60;

    printf("%02d:%02d\n", hora_final, minuto_final);

    return 0;
}