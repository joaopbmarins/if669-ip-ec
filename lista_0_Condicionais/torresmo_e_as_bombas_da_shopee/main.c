#include <stdio.h>
#define e1 75
#define e2 50
#define e3 25
#define e4 50


int main(){
    int d, c1, c2, c3, c4;
    float media_cb;

    scanf("%d", &d);
    scanf("%d%d%d%d", &c1, &c2, &c3, &c4);

    media_cb = ((e1/c1)+(e2/c2)+(e3/c3)+(e4/c4))/4.0;

    if(c1<=d){
        if((e1/c1) < media_cb)
            printf("EH BOMBA TORRESMO\n");
        else if(e1/c1 >= media_cb)
            printf("eh dento\n");
    }
    else if(c1>d)
        printf("foi de comes\n");
    
    if(c2<=d){
        if((e2/c2) < media_cb)
            printf("EH BOMBA TORRESMO\n");
        else if(e2/c2 >= media_cb)
            printf("eh dento\n");
    }
    else if(c2>d)
        printf("foi de comes\n");

    if(c3<=d){
        if((e3/c3) < media_cb)
            printf("EH BOMBA TORRESMO\n");
        else if(e3/c3 >= media_cb)
            printf("eh dento\n");
    }
    else if(c3>d)
        printf("foi de comes\n");

    if(c4<=d){
        if((e4/c4) < media_cb)
            printf("EH BOMBA TORRESMO\n");
        else if(e4/c4 >= media_cb)
            printf("eh dento\n");
    }
    else if(c4>d)
        printf("foi de comes\n");


    return 0;
}