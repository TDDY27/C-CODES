#include <stdio.h>

int solve(int w,int now,int itm[][3]){
    int tt=0,nt=0;
    if(w==0 || now<0) return 0;
    if(w-itm[now][0]>=0) tt=itm[now][1]+solve(w-itm[now][0],now-1,itm);
    nt=solve(w,now-1,itm);
    return tt>nt? tt:nt;
}

signed main(){
    int n,w;
    scanf("%d%d", &n,&w);
    int itm[25][3];
    for(int i=0;i<n;i++) scanf("%d%d", &itm[i][0], &itm[i][1]);
    int ans=solve(w,n-1,itm);
    printf("%d\n", ans);
}