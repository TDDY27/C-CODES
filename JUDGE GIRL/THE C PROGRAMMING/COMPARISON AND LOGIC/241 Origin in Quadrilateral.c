#include <stdio.h>

int x1,y1,x2,y2,x3,y3,x4,y4;
int flag;

int crs(int xa,int ya,int xb,int yb){
    return xa*yb-xb*ya;
}

signed main(){
    scanf("%d%d%d%d%d%d%d%d", &x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
    flag=crs(x1,y1,x2,y2);
    if(flag*crs(x2,y2,x3,y3)<0) printf("0");
    else if(flag*crs(x3,y3,x4,y4)<0) printf("0");
    else if(flag*crs(x4,y4,x1,y1)<0) printf("0");
    else printf("1");
}

