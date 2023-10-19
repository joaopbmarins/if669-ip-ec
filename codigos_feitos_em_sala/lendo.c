#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *file = NULL;
    file = fopen("teste.txt","r");

    char ans[110];

    while(!feof(file)){
        fscanf(file, " %[^','], ", ans);
        printf("Texto no arquivo: %s\n", ans);
    }
    
    fclose(file);
    return 0;
}