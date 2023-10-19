#include <stdio.h>

int main(){
    int x = 10;
    int *pont = &x;

    if(pont != NULL)
        *pont = 10;

    return 0;
}