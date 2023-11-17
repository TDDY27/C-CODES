#include <stdio.h>

int n,x1,y1,x2,y2,x3,y3;
int l1,l2,l3;

int ll(int xa,int ya,int xb,int yb){
    return (xa-xb)*(xa-xb)+(ya-yb)*(ya-yb);
}

signed main(){
    scanf("%d", &n);
    while(n>0){
        scanf("%d%d%d%d%d%d", &x1,&y1,&x2,&y2,&x3,&y3);
        l1=ll(x1,y1,x2,y2), l2=ll(x2,y2,x3,y3), l3=ll(x3,y3,x1,y1);
        if(l1==l2 || l2==l3 || l3==l1) printf("isosceles\n");
        else if(l1+l2==l3 || l2+l3==l1 || l1+l3==l2) printf("right\n");
        else if(l1>l2+l3 || l2>l1+l3 || l3>l1+l2) printf("obtuse\n");
        else if(l1<l2+l3 || l2<l1+l3 || l3<l1+l2) printf("acute\n");

        n--;
    }
}
