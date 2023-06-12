#include <stdio.h>

int main(){
    int n, x, y, z;
    int flag;

    scanf("%d", &n);
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);    


    if(n>=x + y + z)
        flag = 3;
    else if(n>= x+y || n>= x+z || n>= y+z)
        flag = 2;
    else if(n>= x || n>= y || n>= z)
        flag = 1;
    else
        flag = 0;

    printf("%d\n", flag);

    return 0;
}