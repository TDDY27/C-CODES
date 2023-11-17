#include <stdio.h>
#define maxn 350

void swap(int *xa,int *ya,int *xb,int *yb){
    int tmp=*xa;
    *xa=*xb, *xb=tmp;
    tmp=*ya;
    *ya=*yb, *yb=tmp;
}

signed main(){
    int X,Y,x1,y1,x2,y2,dx1,dy1,dx2,dy2,sec;
    scanf("%d%d%d%d%d%d%d%d%d%d%d", &X,&Y,&x1,&y1,&x2,&y2,&dx1,&dy1,&dx2,&dy2,&sec);

    int box[maxn][maxn];
    while(sec>0){
        x1+=dx1, y1+=dy1, x2+=dx2, y2+=dy2;
        if(x1==x2 && y1==y2) swap(&dx1,&dy1,&dx2,&dy2);
        if(x1==1 || x1==X) dx1*=-1;
        if(x2==1 || x2==X) dx2*=-1;
        if(y1==1 || y1==Y) dy1*=-1;
        if(y2==1 || y2==Y) dy2*=-1;
        sec--;
    }
    printf("%d\n%d\n%d\n%d\n", x1,y1,x2,y2);
}