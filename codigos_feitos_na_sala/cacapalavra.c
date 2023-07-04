#include <stdio.h>
#define tamC 50
#define tamP 15
#define qtdP 10
typedef struct{
    char L,C;
} SENTIDO;


int main(){
    char cacapalavra[tamC][tamC], palavra[qtdP][tamP], achei = 0;
    char sentido[8][3] = {"E", "SE", "S", "SW", "W", "NW", "N", "NE"};
    //char deslL[8] = {0,1,1,1,0,-1,-1,-1};
    //char deslC[8] = {1,1,0,-1,-1,-1,0,1};
    SENTIDO desl[8] = {{0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1}};
    int i,j,k, iP, iD;
    for(iP=0;iP<qtdP;iP++){
        for(i=0;i<tamC && !achei;i++){
            for(j=0;j<tamC && !achei;j++){
                if(cacapalavra[i][j]==palavra[iP][0]){
                    for(iD=0;iD<8 && !achei;iD++){
                        achei = 1;
                        for(k=1;palavra[iP][k]!='\0' && achei==1;k++){
                        achei = (palavra[iP][k] == cacapalavra[i+k*desl[iD].L][j+k*desl[iD].C]);
                    if(achei==1){
                        printf("Achei %s na posicao(%d, %d), no sentido %s\n", palavra[iP], i+1,j+1, sentido[iD]);
                        }
                        }
                    }
                }
            }
        }
    }
    
    return 0;
}
