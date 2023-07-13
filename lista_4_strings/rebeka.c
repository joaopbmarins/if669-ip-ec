#include <stdio.h>
#include <string.h>

int main(){
    char frase[1001],letras[1001],num[1001];
    int qtd_letra[27], aux[27];
    char combinando[4], combinados[125][4];
    int index=0,index1=0,index_a=0,index_b=0,nao_serve=0;

    for(int i=0;i<26;i++) {qtd_letra[i] = 0;}

    while(scanf(" %s", frase) != EOF){
        for(int i=0;i<strlen(frase);i++){
            if(frase[i]>= 'a' && frase[i]<= 'z'){
                if(qtd_letra[frase[i]-96]<3){
                    qtd_letra[frase[i]-96] += 1;
                    letras[index] = frase[i];
                    index++;
                }
            }
            else if(frase[i] >= '0' && frase[i] <= '9'){
                num[index1] = frase[i];
                index1++;
            }
        }
    }
    letras[index+1] = '\0';
    num[index1+1] = '\0';
    //printf("%s\n", letras);
    //printf("%s\n", num);

    for(int i=0;i<27;i++){
        aux[i] = qtd_letra[i];
    }



    //anagrama
    for(int i=0;i<index;i++){
        combinando[0] = letras[i];
        for(int j=0;j<index;j++){
            combinando[1] = letras[j];
            for(int k=0;k<index;k++){
                combinando[2] = letras[k];
                combinando[3] = '\0';
                nao_serve = 0;
                for(int w=0;w<index_a;w++){
                    if(strcmp(combinando,combinados[w]) == 0){
                        nao_serve = 1;
                    }
                }

                for(int w=0;w<strlen(combinando);w++){
                    aux[combinando[w]-96] -= 1;
                }
                for(int w=0;w<27;w++){
                    if(aux[w]<0)
                        nao_serve = 1;
                }

                if(nao_serve == 0){
                    strcpy(combinados[index_a],combinando);
                    //printf("%s\n", combinados[index_a]);
                    index_a++;
                    
                }
                index_b=0;
                for(int w=0;w<27;w++){
                    aux[w] = qtd_letra[w];
                }
            }
            //printf("\n");
        }
        //printf("\n");
    }
    char aux1[4];
    for(int i=0;i<index_a;i++){
        for(int j=0;j<index_a-1-i;j++){
            if(strcmp(combinados[j],combinados[j+1]) > 0){
                strcpy(aux1,combinados[j]);
                strcpy(combinados[j],combinados[j+1]);
                strcpy(combinados[j+1],aux1);
            }
        }
    }
    
    for(int i=0;i<index_a;i++) printf("%s",combinados[i]);
    
    

    return 0;
}
