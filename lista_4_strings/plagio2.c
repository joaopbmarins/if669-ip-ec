#include <stdio.h>
#include <string.h>

int main(){
    int c, i=0,j;
    char frase1[50][101] = {};
    char frase2[50][101] = {};

    for(j=0;j<50;j++){
        i=0;
        while ((c = getchar())!= ' '){
            frase1[j][i++] = c;
        }
        frase1[j][i] = '\0';
    }
    
    for(j=0;j<50;j++){
        printf("%s", frase1[j]);
    }

    

    return 0;
}