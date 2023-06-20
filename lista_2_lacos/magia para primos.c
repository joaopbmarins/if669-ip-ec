/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int j,k, num = 4,num_o = num, primo = 0 ,divisores = 0;
    
    //antes_for:
    for(k = 2; k<=num;k++){
        printf("%d ", k);
        if(k == 2)
            primo = 1;
        for(j = 2; j<k; j++){
            if(k == 1)
                primo = 1;
            else if(k == 2)
                primo = 1;
            else if(k % j == 0)
                primo = 0;
            else
                primo = 1;}
        if(num % k == 0 && primo == 1){
            //num = num/k;
            divisores++;
            //goto antes_for;
                }
    }
    
    if(num == num_o)
        printf("%d não tem divisores",divisores);
    else
        printf("-%d-%d",num, divisores);
        
        
    return 0;
}
