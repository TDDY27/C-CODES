#include <stdio.h>
#include <stdlib.h>

struct info{
    int r;
    int x;
    int y;
};

int dis(int xa,int ya,int xb,int yb){
    if(abs(xa-xb)>20 || abs(ya-yb)>20) return 200; 
    else return (xa-xb)*(xa-xb)+(ya-yb)*(ya-yb);
}

signed main(){
    int n;
    scanf("%d", &n);
    while(n>0){
        struct info c1,c2,c3;
        scanf("%d%d%d%d%d%d%d%d%d", &c1.x,&c1.y,&c1.r,&c2.x,&c2.y,&c2.r,&c3.x,&c3.y,&c3.r);
        int rec=0;
        int ans=0;
        for(int i=c1.x-c1.r;i<=c1.x+c1.r;i++){
            for(int j=c1.y-c1.r;j<=c1.y+c1.r;j++){
                if(dis(i,j,c1.x,c1.y)<=c1.r*c1.r && dis(i,j,c2.x,c2.y)>c2.r*c2.r && dis(i,j,c3.x,c3.y)>c3.r*c3.r)
                    ans++;
                else if(dis(i,j,c1.x,c1.y)<=c1.r*c1.r && dis(i,j,c2.x,c2.y)<=c2.r*c2.r && dis(i,j,c3.x,c3.y)<=c3.r*c3.r)
                    ans++,rec++;
            }
        }
        for(int i=c2.x-c2.r;i<=c2.x+c2.r;i++){
            for(int j=c2.y-c2.r;j<=c2.y+c2.r;j++){
                if(dis(i,j,c2.x,c2.y)<=c2.r*c2.r && dis(i,j,c1.x,c1.y)>c1.r*c1.r && dis(i,j,c3.x,c3.y)>c3.r*c3.r)
                    ans++;
                /*else if(dis(i,j,c1.x,c1.y)<=c1.r*c1.r && dis(i,j,c2.x,c2.y)<=c2.r*c2.r && dis(i,j,c3.x,c3.y)<=c3.r*c3.r)
                    ans++,rec++;*/
            }
        }
        for(int i=c3.x-c3.r;i<=c3.x+c3.r;i++){
            for(int j=c3.y-c3.r;j<=c3.y+c3.r;j++){
                if(dis(i,j,c3.x,c3.y)<=c3.r*c3.r && dis(i,j,c2.x,c2.y)>c2.r*c2.r && dis(i,j,c1.x,c1.y)>c1.r*c1.r)
                    ans++;
                /*else if(dis(i,j,c1.x,c1.y)<=c1.r*c1.r && dis(i,j,c2.x,c2.y)<=c2.r*c2.r && dis(i,j,c3.x,c3.y)<=c3.r*c3.r)
                    ans++,rec++;*/
            }
        }

        printf("%d\n", ans);

        n--;
    }
}