#include <stdio.h>

void solve(int l,int x,int y,int ex,int ey){
    if(l<2) return;
    int dx,dy;
    dx=(ex>=x), dy=(ey>=y);
    dx-=(dx==0), dy-=(dy==0);
    int di[4][2]={ {1,1}, {-1,1}, {1,-1}, {-1,-1}};
    for(int i=0;i<4;i++){
        if(dx!=di[i][0] || dy!=di[i][1]){
            int tx=0,ty=0;
            tx-=(di[i][0]<0), ty-=(di[i][1]<0);
            solve(l/2,x+(l/4)*di[i][0], y+(l/4)*di[i][1],x+tx,y+ty);
            continue;
        }
        printf("%d %d %d\n", i+1,x,y);
        solve(l/2,x+(l/4)*di[i][0], y+(l/4)*di[i][1],ex,ey);
    }
}

signed main(){
    int l,x,y;
    scanf("%d%d%d", &l,&x,&y);
    solve(l,l/2,l/2,x,y);
}