#include <stdio.h>

int solve(int r,int c,int nr,int nc,int G[][15]){
    int sum=0;
    if(nr==1 && nc==c) return 1;
    if(nr<=0 || nc>c) return 0;
    if(G[nr][nc]==0) return 0;
    if(nr>0) sum+=solve(r,c,nr-1,nc,G);
    if(nc<=c) sum+=solve(r,c,nr,nc+1,G);
    return sum;
}

signed main(){
    int r,c;
    scanf("%d%d", &r,&c);
    int G[15][15];
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++) scanf("%d", &G[i][j]);
    int ans=solve(r,c,r,1,G);
    printf("%d\n", ans);
}