#include <stdio.h>

//amarelo 
int side0[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
//azul > topo
int side1[3][3] = { {1, 1, 1}, {1, 1, 1}, {1, 1, 1} };
//laranja 
int side2[3][3] = { {2, 2, 2}, {2, 2, 2}, {2, 2, 2} };
//vermelho
int side3[3][3] = { {3, 3, 3}, {3, 3, 3}, {3, 3, 3} };
//branco 
int side4[3][3] = { {4, 4, 4}, {4, 4, 4}, {4, 4, 4} };
//verde
int side5[3][3] = { {5, 5, 5}, {5, 5, 5}, {90, 5, 5} };

int aux1, aux2, aux3, aux4, aux5, aux0;   

void movUR (void) { //para cima direita
    for(int i=0; i<3; i++) {
        aux2 = side2[0][i]; 
        side2[0][i] = side5[2][i]; 
        aux1 = side1[0][i]; 
        side1[0][i] = aux2; 
        aux3 = side3[0][i]; 
        side3[0][i] = aux1; 
        aux5 = side5[2][i]; 
        side5[2][i] = aux3; 
    }
} 

void movUL (void) { //para cima direita
    for(int i=0; i<3; i++) {
        aux2 = side2[0][i]; 
        side2[0][i] = side1[0][i]; 
        
        aux3 = side3[0][i]; 
        side3[0][i] = side5[2][i];
        
        aux1 = side1[0][i]; 
        side1[0][i] = aux3; 
        
        aux5 = side5[2][i]; 
        side5[2][i] = aux2; 
    }
} 
void movLB(void) { //nao mexe com 1 e 5 
    for(int i=0; i<3; i++) {
        aux3 = side3[i][2]; 
        side3[i][2] = side4[2][i]; 
        
        aux0 = side0[2][i]; 
        side0[2][i] = aux3; 
        
        aux2 = side2[i][0]; 
        side2[i][0] = aux0; 
        
        side4[2][i] = aux2; 
        
    }
}
void movLL(void) {
    int index5 = 2; 
    int backup5[3] = {side5[0][0], side5[1][0], side5[2][0]}; 
    for(int i=0; i<3; i++) {
        aux1 = side1[i][0]; 
        side1[i][0] = side4[i][0]; 
        
        aux4 = side4[i][0]; 
        side4[i][0] = backup5[i]; 
        
        aux0 = side0[i][0]; 
        side0[i][0] = aux1; 
        
        side5[index5][0] = aux0; 
        index5--; 
    }
}
void movLR(void) {
    int index5 = 2; 
    int backup5[3] = {side5[0][2], side5[1][2], side5[2][2]}; 
    for(int i=0; i<3; i++) {
        aux1 = side1[i][2]; 
        side1[i][2] = side4[i][2]; 
        
        aux4 = side4[i][2]; 
        side4[i][2] = backup5[i]; 
        
        aux0 = side0[i][2]; 
        side0[i][2] = aux1; 
        
        side5[index5][2] = aux0; 
        index5--; 
    }
}
//a partir dessa
void movLF(void) {
    for(int i=0; i<3; i++) {
        aux4 = side4[0][i]; 
        side4[0][i] = side3[i][0]; 
        
        aux2 = side2[i][2]; 
        side2[i][2] = aux4; 
        
        aux0 = side0[2][i]; 
        side0[2][i] = aux2; 
        
        side3[i][0] = aux0; 
        
    }
}
void movLD(void){

    for(int i=0; i<3; i++) {
        aux2 = side2[2][i]; 
        side2[2][i] = side1[2][i]; 
        
        aux3 = side3[2][i]; 
        side3[2][i] = side5[0][i];
        
        aux1 = side1[2][i]; 
        side1[2][i] = aux3; 
        
        aux5 = side5[0][i]; 
        side5[0][i] = aux2; 
    }
    
}
void movRB(void) {
    for(int i=0; i<3; i++) {
        aux3 = side3[i][2]; 
        side3[i][2] = side0[2][i]; 
        
        aux0 = side0[0][i]; 
        side0[2][i] = aux2; 
        
        aux2 = side2[i][0]; 
        side2[i][0] = side4[2][i]; 
        
        side4[2][i] = aux2; 
    }
}
//testar a rotacao LL
void movRL(void) {
    int index5 = 2; 
    int backup5[3] = {side5[0][0], side5[1][0], side5[2][0]}; 
    for(int i=0; i<3; i++) {
        aux1 = side1[i][0]; 
        side1[i][0] = side0[i][0]; 
    
        //
        aux4 = side4[i][0]; 
        side4[i][0] = aux1; 
        
        aux0 = side0[i][0]; 
        side0[i][0] = backup5[i]; 
        
        side5[i][0] = aux4; 
        index5--; 
    }
}
void movRR(void) {
    
}
void movRF(void) {
    int vec1[3] = {side1[0][0], side1[0][1], side1[0][2] }; 
    int vec2[3] = {side1[0][2], side1[1][2], side1[2][2] }; 
    int vec3[3] = {side1[2][0], side1[2][1], side1[2][2] };
    int vec4[3] = {side1[0][0], side1[1][0], side1[2][0] }; 
    side1[0][0] = vec4[2]; 
    side1[0][1] = vec4[1];
    side1[0][2] = vec4[0]; 
    
    
    
    for(int i=0; i<3; i++) {
        aux0 = side0[2][i]; 
        side0[2][i] = side2[i][2]; 
        
        aux2 = side2[i][2];
        side2[i][2] = side4[0][i]; 
        
        aux4 = side4[0][i]; 
        side4[0][i] = side3[i][0];
        
        side3[i][0] = aux0; 
        
        
        
    }
}
void movRD(void) {
    for(int i=0; i<3; i++) {
        
    }
}
int main()
{
    
    char mov, dir; 
    
   // scanf("%c%c", &mov, &dir); 
    movRF(); 
    
    int i, j; 
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) printf("%d ", side0[i][j]); 
        printf("\n"); 
    }
    printf("\n");
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) printf("%d ", side1[i][j]); 
        printf("\n"); 
    }
    printf("\n");
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) printf("%d ", side2[i][j]); 
        printf("\n"); 
    }
    printf("\n");
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) printf("%d ", side3[i][j]); 
        printf("\n"); 
    }
    printf("\n");
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) printf("%d ", side4[i][j]); 
        printf("\n"); 
    }
    printf("\n");
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) printf("%d ", side5[i][j]); 
        printf("\n"); 
    }
    printf("\n");
    return 0;
}
