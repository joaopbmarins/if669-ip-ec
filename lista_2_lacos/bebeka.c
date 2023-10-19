#include <stdio.h>

int main(){
    char dir;
    int dist=0, posi = 10*2;

    //scanf("%c %d", &dir, &dist);
    while ((scanf(" %c %d", &dir, &dist)) != EOF){
        switch (dir){
        case 'd':
            for(int i=0;i<posi; i++){
                printf(" ");
            }
            for(int i=0;i<dist;i++){
                printf("->");
            }
            posi += dist*2;
            printf("\n");
            break;
        case 'e':
            posi -= dist*2;
            for(int i=0;i<posi; i++){
                printf(" ");
            }
            for(int i=0;i<dist;i++){
                printf("<-");
            }
            printf("\n");
            break;
        case 'f':
            for(int j=0;j<dist;j++){
                for(int i=0;i<posi; i++){
                    printf(" ");
                }
                printf("|\n");
            }
            break;
        case 'x':
            for(int i=0;i<posi;i++){
                printf(" ");
            }
            printf("x");
            break;

        default:
            break;
    }
    }

    return 0;
}