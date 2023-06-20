#include <stdio.h>

int main()
{
    long int n, k_q;
    int j,k, num = 0, primo = 0 ,p_calculado = 0, p_divisores = 0;
    int p, q=0;

    scanf("%ld %ld %d", &n,&k_q,&p);
    //antes_for:
    for(int i = n; i<k_q;i++){
        num = i;
        
        while(num>1 && p_divisores != -1){
        p_calculado = 0;
        p_divisores = 0;
        for(k = 2; k<=num;k++){
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
                num = num/k;
                if(k != 2){
                    if(p_divisores != k){
                        p_divisores = k;
                        p_calculado++;
                    }
                    else{
                        p_divisores = -1;
                    }
                }
                    
                //goto antes_for;
                }
    }
    }
    if(p_calculado == p && p_divisores != -1){
        q++;
        printf("%d=%d\n",p_divisores, i); 
    }
    }
    
    printf("%d\n",q);
    
        
        
    return 0;
}
