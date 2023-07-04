#include <stdio.h>
#define TAM 3

int main(){
    int lado0[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    int lado1[3][3] = {{1,1,1},{1,1,1},{1,1,1}};
    int lado2[3][3] = {{2,2,2},{2,2,2},{2,2,2}};
    int lado3[3][3] = {{3,3,3},{3,3,3},{3,3,3}};
    int lado4[3][3] = {{4,4,4},{4,4,4},{4,4,4}};
    int lado5[3][3] = {{5,5,5},{5,5,5},{5,5,5}};
    int aux,aux1,aux2,aux3,aux4, aux5;
    char mov, direc;


    while(scanf(" %c%c", &mov, &direc) != EOF){
        switch (direc)
        {
        case 'L':
            switch (mov)
            {
            case 'B':
                aux  = lado2[0][0];
                aux1 = lado2[1][0];
                aux2 = lado2[2][0];
                lado2[0][0] = lado1[0][0];
                lado2[1][0] = lado1[0][1]; 
                lado2[2][0] = lado1[0][2];
                aux3 = lado5[2][0];
                aux4 = lado5[2][1];
                aux5 = lado5[2][2];
                lado5[2][0] = aux;
                lado5[2][1] = aux1;
                lado5[2][2] = aux2;
                aux  = lado3[0][2];
                aux1 = lado3[1][2];
                aux2 = lado3[2][2];
                lado3[0][2] = aux3;
                lado3[1][2] = aux4;
                lado3[2][2] = aux5;
                lado1[0][0] = aux;
                lado1[0][1] = aux1;
                lado1[0][2] = aux2;
                break;

            case 'L':
                aux  = lado0[0][2];
                aux1 = lado0[1][2];
                aux2 = lado0[2][2];
                lado0[0][2] = lado1[0][0];
                lado0[1][2] = lado1[1][0]; 
                lado0[2][2] = lado1[2][0];
                aux3 = lado5[0][0];
                aux4 = lado5[1][0];
                aux5 = lado5[2][0];
                lado5[0][0] = aux;
                lado5[1][0] = aux1;
                lado5[2][0] = aux2;
                aux  = lado4[0][0];
                aux1 = lado4[1][0];
                aux2 = lado4[2][0];
                lado4[0][0] = aux3;
                lado4[1][0] = aux4;
                lado4[2][0] = aux5;
                lado1[0][0] = aux;
                lado1[1][0] = aux1;
                lado1[2][0] = aux2;
                break;

            case 'U':
                aux  = lado0[0][0];
                aux1 = lado0[0][1];
                aux2 = lado0[0][2];
                lado0[0][0] = lado2[0][0];
                lado0[0][1] = lado2[0][1]; 
                lado0[0][2] = lado2[0][2];
                aux3 = lado3[0][0];
                aux4 = lado3[0][1];
                aux5 = lado3[0][2];
                lado3[0][0] = aux;
                lado3[0][1] = aux1;
                lado3[0][2] = aux2;
                aux  = lado4[0][0];
                aux1 = lado4[0][1];
                aux2 = lado4[0][2];
                lado4[0][0] = aux3;
                lado4[0][1] = aux4;
                lado4[0][2] = aux5;
                lado2[0][0] = aux;
                lado2[0][1] = aux1;
                lado2[0][2] = aux2;
                break;

            case 'R':
                aux  = lado0[0][0];
                aux1 = lado0[1][0];
                aux2 = lado0[2][0];
                lado0[0][0] = lado1[0][2];
                lado0[1][0] = lado1[1][2]; 
                lado0[2][0] = lado1[2][2];
                aux3 = lado5[0][2];
                aux4 = lado5[1][2];
                aux5 = lado5[2][2];
                lado5[0][2] = aux;
                lado5[1][2] = aux1;
                lado5[2][2] = aux2;
                aux  = lado4[0][2];
                aux1 = lado4[1][2];
                aux2 = lado4[2][2];
                lado1[0][2] = aux;
                lado1[1][2] = aux1;
                lado1[2][2] = aux2;
                lado4[0][2] = aux3;
                lado4[1][2] = aux4;
                lado4[2][2] = aux5;
                break;

            case 'F':
                aux  = lado1[2][0];
                aux1 = lado1[2][1];
                aux2 = lado1[2][2];
                lado1[2][0] = lado3[0][0];
                lado1[2][1] = lado3[1][0]; 
                lado1[2][2] = lado3[2][0];
                aux3 = lado2[0][2];
                aux4 = lado2[1][2];
                aux5 = lado2[2][2];
                lado2[0][2] = aux;
                lado2[1][2] = aux1;
                lado2[2][2] = aux2;
                aux  = lado5[0][0];
                aux1 = lado5[0][1];
                aux2 = lado5[0][2];
                lado3[0][0] = aux;
                lado3[1][0] = aux1;
                lado3[2][0] = aux2;
                lado5[0][0] = aux3;
                lado5[0][1] = aux4;
                lado5[0][2] = aux5;
                break;

            case 'D':
                aux  = lado0[2][0];
                aux1 = lado0[2][1];
                aux2 = lado0[2][2];
                lado0[2][0] = lado2[2][0];
                lado0[2][1] = lado2[2][1]; 
                lado0[2][2] = lado2[2][2];
                aux3 = lado3[2][0];
                aux4 = lado3[2][1];
                aux5 = lado3[2][2];
                lado3[2][0] = aux;
                lado3[2][1] = aux1;
                lado3[2][2] = aux2;
                aux  = lado4[2][0];
                aux1 = lado4[2][1];
                aux2 = lado4[2][2];
                lado2[2][0] = aux;
                lado2[2][1] = aux1;
                lado2[2][2] = aux2;
                lado4[2][0] = aux3;
                lado4[2][1] = aux4;
                lado4[2][2] = aux5;
                break;

            default:
                break;
            }


            break;
        case 'R':
            switch (mov)
            {
            case 'B':
                aux  = lado1[0][0];
                aux1 = lado1[0][1];
                aux2 = lado1[0][2];
                lado1[0][0] = lado2[0][0];
                lado1[0][1] = lado2[1][0]; 
                lado1[0][2] = lado2[2][0];
                aux3 = lado3[0][2];
                aux4 = lado3[1][2];
                aux5 = lado3[2][2];
                lado3[0][2] = aux;
                lado3[1][2] = aux1;
                lado3[2][2] = aux2;
                aux  = lado5[2][0];
                aux1 = lado5[2][1];
                aux2 = lado5[2][2];
                lado5[2][0] = aux3;
                lado5[2][1] = aux4;
                lado5[2][2] = aux5;
                lado2[0][0] = aux;
                lado2[1][0] = aux1;
                lado2[2][0] = aux2;
                break;

            case 'L':
                aux  = lado0[0][2];
                aux1 = lado0[1][2];
                aux2 = lado0[2][2];
                lado0[0][2] = lado5[0][0];
                lado0[1][2] = lado5[1][0]; 
                lado0[2][2] = lado5[2][0];
                aux3 = lado1[0][0];
                aux4 = lado1[1][0];
                aux5 = lado1[2][0];
                lado1[0][0] = aux;
                lado1[1][0] = aux1;
                lado1[2][0] = aux2;
                aux  = lado4[0][0];
                aux1 = lado4[1][0];
                aux2 = lado4[2][0];
                lado4[0][0] = aux3;
                lado4[1][0] = aux4;
                lado4[2][0] = aux5;
                lado5[0][0] = aux;
                lado5[1][0] = aux1;
                lado5[2][0] = aux2;
                break;

            case 'U':
                aux  = lado0[0][0];
                aux1 = lado0[0][1];
                aux2 = lado0[0][2];
                lado0[0][0] = lado3[0][0];
                lado0[0][1] = lado3[0][1]; 
                lado0[0][2] = lado3[0][2];
                aux3 = lado2[0][0];
                aux4 = lado2[0][1];
                aux5 = lado2[0][2];
                lado2[0][0] = aux;
                lado2[0][1] = aux1;
                lado2[0][2] = aux2;
                aux  = lado4[0][0];
                aux1 = lado4[0][1];
                aux2 = lado4[0][2];
                lado4[0][0] = aux3;
                lado4[0][1] = aux4;
                lado4[0][2] = aux5;
                lado3[0][0] = aux;
                lado3[0][1] = aux1;
                lado3[0][2] = aux2;
                break;

            case 'R':
                aux  = lado0[0][0];
                aux1 = lado0[1][0];
                aux2 = lado0[2][0];
                lado0[0][0] = lado5[0][2];
                lado0[1][0] = lado5[1][2]; 
                lado0[2][0] = lado5[2][2];
                aux3 = lado1[0][2];
                aux4 = lado1[1][2];
                aux5 = lado1[2][2];
                lado1[0][2] = aux;
                lado1[1][2] = aux1;
                lado1[2][2] = aux2;
                aux  = lado4[2][0];
                aux1 = lado4[2][1];
                aux2 = lado4[2][2];
                lado4[0][2] = aux3;
                lado4[1][2] = aux4;
                lado4[2][2] = aux5;
                lado5[0][2] = aux;
                lado5[1][2] = aux1;
                lado5[2][2] = aux2;
                break;

            case 'F':
                aux  = lado1[2][0];
                aux1 = lado1[2][1];
                aux2 = lado1[2][2];
                lado1[2][0] = lado2[0][2];
                lado1[2][1] = lado2[1][2]; 
                lado1[2][2] = lado2[2][2];
                aux3 = lado3[0][0];
                aux4 = lado3[1][0];
                aux5 = lado3[2][0];
                lado3[0][0] = aux;
                lado3[1][0] = aux1;
                lado3[2][0] = aux2;
                aux  = lado5[0][0];
                aux1 = lado5[0][1];
                aux2 = lado5[0][2];
                lado5[0][0] = aux3;
                lado5[0][1] = aux4;
                lado5[0][2] = aux5;
                lado2[0][2] = aux;
                lado2[1][2] = aux1;
                lado2[2][2] = aux2;
                break;

            case 'D':
                aux  = lado0[2][0];
                aux1 = lado0[2][1];
                aux2 = lado0[2][2];
                lado0[2][0] = lado3[2][0];
                lado0[2][1] = lado3[2][1]; 
                lado0[2][2] = lado3[2][2];
                aux3 = lado2[2][0];
                aux4 = lado2[2][1];
                aux5 = lado2[2][2];
                lado2[2][0] = aux;
                lado2[2][1] = aux1;
                lado2[2][2] = aux2;
                aux  = lado4[2][0];
                aux1 = lado4[2][1];
                aux2 = lado4[2][2];
                lado4[2][0] = aux3;
                lado4[2][1] = aux4;
                lado4[2][2] = aux5;
                lado3[2][0] = aux;
                lado3[2][1] = aux1;
                lado3[2][2] = aux2;
                break;

            default:
                break;
            }
            break;

        default:
            break;
        }
    }
    
    for(int i=0;i<TAM;i++){
        for(int j=0;j<TAM;j++)
            printf("%d ", lado0[i][j]);
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<TAM;i++){
        for(int j=0;j<TAM;j++)
            printf("%d ", lado1[i][j]);
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<TAM;i++){
        for(int j=0;j<TAM;j++)
            printf("%d ", lado2[i][j]);
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<TAM;i++){
        for(int j=0;j<TAM;j++)
            printf("%d ", lado3[i][j]);
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<TAM;i++){
        for(int j=0;j<TAM;j++)
            printf("%d ", lado4[i][j]);
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<TAM;i++){
        for(int j=0;j<TAM;j++)
            printf("%d ", lado5[i][j]);
        printf("\n");
    }
    printf("\n");

    return 0;
}
