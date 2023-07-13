/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>

int main()
{
    char letras[1001][2] = {"a","a","a","b","t"};
    char aux[1001] = {"aaabt"};
    char combinados[125][4];
    int qtd_letras = 5, index=0, nao_serve=0;
    char combinando[4];
    
    for(int i=0;i<qtd_letras;i++){
        //printf("-%d-",i);
        combinando[0] = letras[i][0];
        //printf("%s\n", combinando);
        for(int j=0;j<qtd_letras;j++){
            combinando[1] = letras[j][0];
            //printf("%s\n", combinando);
            for(int k=0;k<qtd_letras;k++){
                combinando[2] = letras[k][0];
                combinando[3] = '\0';
                nao_serve = 0;
                for(int w=0;w<index;w++){
                    if(strcmp(combinando,combinados[w]) == 0){
                        //printf("%d",strcmp(combinando,combinados[0]));
                        nao_serve = 1;
                    }
                }
                
                
                
                //printf("\n");
                //printf("%d", nao_serve);
                if(nao_serve == 0){
                    strcpy(combinados[index],combinando);
                    printf("%s\n", combinados[index]);
                    index++;
                    
                }
            }
            //printf("\n");
        }
        //printf("\n");
    }
    
    
    return 0;
}
