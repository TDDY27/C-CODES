#include <stdio.h>
#include <stdlib.h>
#define max(a,b) a>b? a:b

void solve(int n,int now,int mmax,int eg[][20],int usd[],int rec[],int *mmin,int ans[]){
    if(now>n){
        if(mmax<*mmin){
            *mmin=mmax;
            for(int i=1;i<=n;i++) ans[i]=rec[i];
        }
        return;
    }
    if(mmax>=*mmin) return;

    int tmpu[20],tmpr[20],tmpm;
    tmpm=mmax;
    for(int i=0;i<20;i++) tmpu[i]=usd[i], tmpr[i]=rec[i];
    for(int i=1;i<=n;i++){
        if(usd[i])continue;
        rec[now]=i,usd[i]=1;
        for(int j=1;j<=n;j++) if(rec[j]&&eg[now][j]) mmax=max(mmax,abs(i-rec[j]));
        solve(n,now+1,mmax,eg,usd,rec,mmin,ans);
        for(int j=0;j<20;j++) usd[j]=tmpu[j], rec[j]=tmpr[j];
        mmax=tmpm;
    }
}

signed main(){
    int n,m;
    scanf("%d%d", &n,&m);
    int eg[20][20]={};
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d", &u,&v);
        eg[u][v]=1, eg[v][u]=1;
    }
    int mmin=10000000;
    int usd[20]={}, rec[20]={}, ans[20]={};
    solve(n,1,0,eg,usd,rec,&mmin,ans);
    for(int i=1;i<=n;i++) printf("%d ", ans[i]);
}   