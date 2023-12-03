#include <stdio.h>
 
void solve(int l,int x,int y,int z,int ex,int ey,int ez){
    if(l<2) return;
    int dx,dy,dz;
    int dix[8]={1,-1,1,-1,1,-1,1,-1};
    int diy[8]={1,1,-1,-1,1,1,-1,-1};
    int diz[8]={1,1,1,1,-1,-1,-1,-1};
    dx=ex-x, dy=ey-y, dz=ez-z;
    if(dx==0) dx++; 
    if(dy==0) dy++;
    if(dz==0) dz++;
    for(int i=0;i<8;i++){
        if(dx*dix[i]<0 || dy*diy[i]<0 || dz*diz[i]<0){
            int tmx=dix[i],tmy=diy[i],tmz=diz[i];
            if(tmx>0) tmx=0;
            if(tmy>0) tmy=0;
            if(tmz>0) tmz=0;
            solve(l/2,x+(l/4)*dix[i], y+(l/4)*diy[i], z+(l/4)*diz[i], x+tmx,y+tmy,z+tmz);
            continue;
        }
        printf("%d %d %d %d\n", i+1,x,y,z);
        solve(l/2,x+(l/4)*dix[i], y+(l/4)*diy[i], z+(l/4)*diz[i], ex,ey,ez);
    }
}
 
signed main(){
    int l,x,y,z;
    scanf("%d%d%d%d", &l,&x,&y,&z);
    solve(l,l/2,l/2,l/2,x,y,z);
}