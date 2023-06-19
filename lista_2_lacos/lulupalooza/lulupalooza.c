#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int num_recebido, n_canais, f1=0, f2=0, ftemp=0, f=2,fr, canal, dist_fr=0, soma=0, num_soma;
    scanf("%d %d", &num_recebido, &n_canais);

    for(int i=1; i<=n_canais; i++){//laço para cada canal   i = canal
        scanf("%d %d", &f1 ,&f2);
        f = 2;// o problema é no while q tá dando True quando num_recebido é menor q f1 e f2.
        if(num_recebido<f1)
            goto selecao_canal;
        while( !(num_recebido <= f2 && num_recebido >= f1)){//laço para checar se o número está entre o quais f1 e f2
            f++;//incrementa f para saber em qual f2 foi achado o espaço
            ftemp = f1 + f2;//ajeita a ordem dos fs
            f1 = f2;
            f2 = ftemp;
            //printf("%d %d\n",f1,f2);
        }
        selecao_canal:
        //printf("%d\n",abs(f2 - num_recebido));
        //printf("%d\n",abs(num_recebido - f1));
        if( abs(f2 - num_recebido) > abs(num_recebido - f1)){ //distancia do f1 pro num/ menor
            if(abs(num_recebido - f1)<=dist_fr && i!=1){
                dist_fr = abs(num_recebido - f1);//define dist_fr como a menor distancia entre f1 e f2 para o num
                canal = i;
                fr = f-1;
                num_soma = f1;
            }
            else if(i==1){
                dist_fr = abs(num_recebido - f1);
                canal = i;
                num_soma = f1;
                fr = f-1;}
        }
        else if(abs(f2 - num_recebido) < abs(num_recebido - f1)){//distancia do f2 pro num/ menor
            if(abs(f2 - num_recebido)<=dist_fr && i!=1){
                dist_fr = abs(f2 - num_recebido);//define dist_fr como a menor distancia entre f1 e f2 para o num
                canal = i;
                num_soma = f2;
                fr = f;
            }
            else if(i==1){
                dist_fr = abs(f2 - num_recebido);
                canal = i;
                num_soma = f2;
                fr = f;}
        }
        else if(abs(f2 - num_recebido) == abs(num_recebido - f1)){
            dist_fr = abs(num_recebido - f1);//define dist_fr como a menor distancia entre f1 e f2 para o num
            canal = i;
            num_soma = f1;
            fr = f-1;
        }
        //printf("\n%d %d\n",fr ,dist_fr);
    }
    //printf("\ncanal: %d minuto: %d\n", canal, fr);

    while(num_soma>0){
        int algoritmo;
        algoritmo = num_soma % 10;
        soma += algoritmo;
        num_soma = num_soma/10;
        
    }
    //printf("%d", soma);

    if(soma>10 && n_canais >0){
        printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %d e sera chamado mais ou menos no minuto %d e com o VIP garantido!!!\n", canal, fr);
    }
    else if(soma<=10 && soma>0 && n_canais >0){
        printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %d e sera chamado mais ou menos no minuto %d, mas o ingresso VIP não vai rolar :(\n", canal, fr);
    }

    return 0;
}