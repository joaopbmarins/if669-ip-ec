#include <stdio.h>
#include <string.h>

/*
João Pedro Barbosa Marins
jpbm 
Lista Ponteiros
Questão 3
*/

int main(){
    char str[50];     // String
    char str_inv[50]; // String invertida
    char *ptr_str = str;
    char *ptr_inv = str_inv;
    int i = -1;
    scanf(" %s", str);

    int final_str;
    for(int j=0;j<50;j++){
        if(*(ptr_str+j) == '\0'){
            final_str = j;
            j = 50;
        }
    }

    for(int j=0;j<final_str;j++){
        *(ptr_inv+j) = *(ptr_str+(final_str-1)+(j*i));
    }

    *(ptr_inv+final_str+1) = '\0';

    printf(" O inverso da string : %s\n\n", str_inv);
    return 0;
}