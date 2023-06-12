#include <stdio.h>
#include <math.h>

int main(){
    int total_dinheiro, x, y, z;    //x,y,z são porcentagem de casa homem
    float h1, h2, h3;
    int resto;

    scanf("%d", &total_dinheiro);
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);

    h1 = total_dinheiro *(x/100.0);
    h2 = total_dinheiro *(y/100.0);
    h3 = total_dinheiro *(z/100.0);

    if(h1 == ceil(h1) && h2 == ceil(h2) && h3 == ceil(h3)){
        printf("Cada homem ficou com %.f, %.f e %.f reais, respectivamente\n", h1, h2, h3);
        resto = total_dinheiro - (h1+h2+h3);
        if(resto != 0 && resto >= 4)
            printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n");
        else if(resto == 0 || (resto < 4 && resto > 0))
            printf("E parece que Rebeka vai ter que voltar andando...\n");
    }
    else{
        total_dinheiro = total_dinheiro + 1;
        h1 = total_dinheiro *(x/100.0);
        h2 = total_dinheiro *(y/100.0);
        h3 = total_dinheiro *(z/100.0);
        resto = total_dinheiro - (h1+h2+h3);
        if((h1 == ceil(h1) && h2 == ceil(h2) && h3 == ceil(h3)) && resto > 1){
            printf("Cada homem ficou com %.f, %.f e %.f reais, respectivamente\n", h1, h2, h3);
            if(resto != 0 && resto >= 4)
                printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n");
            else if(resto == 0 || (resto < 4 && resto > 0))
                printf("E parece que Rebeka vai ter que voltar andando...\n");
        }
        else{
            total_dinheiro = total_dinheiro + 1;//Investindo dois reais
            h1 = total_dinheiro *(x/100.0);
            h2 = total_dinheiro *(y/100.0);
            h3 = total_dinheiro *(z/100.0);
            resto = total_dinheiro - (h1+h2+h3);
            if((h1 == ceil(h1) && h2 == ceil(h2) && h3 == ceil(h3)) && resto > 2){
                printf("Cada homem ficou com %.f, %.f e %.f reais, respectivamente\n", h1, h2, h3);
                char a,b,c;
                scanf(" %c %c %c",&a,&b,&c);
                printf("%d\n", (a+b+c)-(96*3));
                if(resto != 0 && resto >= 4)// não mexa parece tá tudo certo dai pra baixo
                    printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n");
                else if(resto == 0 || (resto < 4 && resto > 0))
                    printf("E parece que Rebeka vai ter que voltar andando...\n");
            }
            else{
                total_dinheiro = total_dinheiro + 1;//Investindo três reais
                h1 = total_dinheiro *(x/100.0);
                h2 = total_dinheiro *(y/100.0);
                h3 = total_dinheiro *(z/100.0);
                resto = total_dinheiro - (h1+h2+h3);
                if((h1 == ceil(h1) && h2 == ceil(h2) && h3 == ceil(h3)) && resto > 3){
                    printf("Cada homem ficou com %.f, %.f e %.f reais, respectivamente\n", h1, h2, h3);
                    int a,b,c, soma;
                    scanf("%d %d %d", &a,&b,&c);
                    soma = (a % 3 == 0)? (a/3) + soma : soma;
                    soma = (b % 3 == 0)? (b/3) + soma : soma;
                    soma = (c % 3 == 0)? (c/3) + soma : soma;
                    printf("%d\n",soma);
                    if(resto != 0 && resto >= 4)
                        printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n");
                    else if(resto == 0 || (resto < 4 && resto > 0))
                        printf("E parece que Rebeka vai ter que voltar andando...\n");
                }
            }
        }
    }
    return 0;
}