#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *file = NULL;
    file = fopen("teste.txt","w");

    fprintf(file, "%s\n", "Oi algo esta escrito");


    fclose(file);
    return 0;
}