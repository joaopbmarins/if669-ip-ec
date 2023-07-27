#include <stdio.h>

/*
João Pedro Barbosa Marins
jpbm 
Lista Ponteiros
Questão 1
*/

int main(){
    char c = 'a';
    char *pc = &c;

    printf("a)\n");
    printf("\tendereço de c: %p\n\tvalor guardado em c: %c\n",&c, c);
    printf("b)\n");
    printf("\tendereço armazenado em pc: %p\n\tvalor guardado no endereço armazenado em pc: %c\n",pc, *pc);
    printf("c)\n");
    printf("\tendereço de pc: %p\n",&pc);
    printf("d)\n");
    printf("\tendereço do valor guardado no endereço apontado por pc: %p\n\tvalor guardado no endereço de pc: %p\n",&*pc, *&pc);
    //explicacao
    printf("\n\tR= Quando voce acessa o endereço de pc voce recebe o valor guardado nele logo o endereço da variavel armazenada.\n");
    printf("\tE quando voce acessa pc para alcancar a variavel armazenada nele e pede o endereço dela voce recebe o endereço da variavel que tambem é o endereço armazenado em pc.\n");    

    return 0;
}
