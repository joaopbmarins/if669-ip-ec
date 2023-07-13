#include <stdio.h>
#include <string.h>

int main() {
    int n, index=0;
    scanf("%d", &n);
    char mov, palavra[13], palavra_procurada[13],string_buscada[273];
    for(int i=0;i<n;i++){
        scanf(" %c", &mov);
        scanf(" %12[^\n]", palavra);

        switch (mov){
        case 'd':
            for(int j=0;j<6;j++){
                string_buscada[index] = palavra[j];
                index++;
            }
            break;

        case 'e':
            for(int j=11;j>=6;j--){
                string_buscada[index] = palavra[j];
                index++;
            }
            break;
        default:
            break;
        }
    }
    string_buscada[index] = '\0';
    scanf(" %12[^\n]", palavra_procurada);
    int tam = strlen(string_buscada);
    int tam_p = strlen(palavra_procurada);
    int index1=0, k=0, flag=0, achadas=0;

    while(flag != tam + (tam_p-1)){
        if(string_buscada[k] == palavra_procurada[index1]){
            index1++;
        }
        else if(index1 != 0){
            index1=0;
        }
        if(index1==tam_p){
            index1=0;
            achadas++;
        }
        k++;
        if(k == strlen(string_buscada)){
            k=0;
        }
        flag++;
    }

    k=strlen(string_buscada) -1;
    //flag = tam -1;
    index1=0;
    //printf("%s\n",string_buscada);
    
    while(flag != 0){
        if(string_buscada[k] == palavra_procurada[index1]){
            index1++;
        }
        else if(index1 != 0){
            index1=0;
        }
        if(index1==tam_p){
            index1=0;
            achadas++;
        }
        k--;
        if(k == 0){
            k=strlen(string_buscada);
        }
        flag--;
    }   

    printf("%s", palavra_procurada);
    printf("%d\n", achadas);

	return 0;
}