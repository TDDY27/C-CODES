#include <stdio.h>

int x;
int scr;

signed main(){
    scanf("%d", &x);
    if(x<=0) scr=-100;
    else{
        if(x%3==0) scr+=3;
        if(x%5==0) scr+=5;
        if(x>=100 && x<=200) scr+=50;
        else scr-=50;
    }
    printf("%d",scr);
}
