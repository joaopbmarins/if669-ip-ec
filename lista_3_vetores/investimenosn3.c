#include <stdio.h>
#define TAM 4

int main(){
    int cidade[TAM][TAM] = {{0,0,0,0},
                            {0,0,0,0},
                            {0,0,0,0},
                            {0,0,0,0}};
    char movimento;
    int x = 0,y = 0;
    int xfinal = 0, yfinal = 0, num = 0;

    while(scanf(" %c", &movimento) != EOF){
        switch (movimento)
        {
        case 'c':
            y--;
            cidade[y][x] = cidade[y][x] + 1;
            break;
        
        case 'b':
            y++;
            cidade[y][x] = cidade[y][x] + 1;
            break;

        case 'd':
            x++;
            cidade[y][x] = cidade[y][x] + 1;
            break;

        case 'e':
            x--;
            cidade[y][x] = cidade[y][x] + 1;
            break;

        default:
            break;
        }
    }
/*
    for(int i=0;i<TAM;i++){
        for(int j=0;j,j<TAM;j++){
            printf("%d ", cidade[i][j]);
        }
        printf("\n");
    }
*/
    
    for(int i=0;i<TAM;i++){
        for(int j=0;j,j<TAM;j++){
            if(cidade[i][j] > num){
                xfinal = j;
                yfinal = i;
                num = cidade[i][j];
            }
        }
    }

    printf("Coordenada X:%d, Y:%d\n", xfinal, yfinal);

    return 0;
}