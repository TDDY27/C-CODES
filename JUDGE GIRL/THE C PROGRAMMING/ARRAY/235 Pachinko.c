#include <stdio.h>

struct info{
    long long  rp;
    long long  rq;
    long long  lp;
    long long  lq;
};

struct info G[40][40];

void nof(long long *a, long long *b){
    int ta=*a, tb=*b;
    while(ta>0 && tb>0){
        if(ta>tb) ta-=tb;
        else tb-=ta;
    }
    if(ta>tb) *a/=ta, *b/=ta;
    else *a/=tb, *b/=tb;
}
//no overflow

signed main(){
    int n;
    scanf("%d", &n);
    for(int i=0;i<40;i++)
        for(int j=0;j<40;j++) G[i][j].lp=0, G[i][j].lq=1, G[i][j].rp=0, G[i][j].rq=1;

    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            long long p,q;
            scanf("%lld%lld", &p, &q);
            G[i][j].lp=p, G[i][j].rp=q;
            G[i][j].lq=p+q, G[i][j].rq=p+q;
            nof( &G[i][j].lp, &G[i][j].lq);
            nof( &G[i][j].rp, &G[i][j].rq);
        }
    }
    
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            long long tp=0,tq=0;
            tp+=G[i-1][j-1].rp*G[i-1][j].lq;
            tp+=G[i-1][j].lp*G[i-1][j-1].rq;
            tq=G[i-1][j-1].rq*G[i-1][j].lq;
            G[i][j].lp*=tp, G[i][j].lq*=tq;
            G[i][j].rp*=tp, G[i][j].rq*=tq;
            nof( &G[i][j].lp, &G[i][j].lq);
            nof( &G[i][j].rp, &G[i][j].rq);
        }
    }
    long long ans[40][3];
    for(int j=1;j<=n+1;j++){
        int i=n+1;
        long long tp=0,tq=0;
        tp+=G[i-1][j-1].rp*G[i-1][j].lq;
        tp+=G[i-1][j].lp*G[i-1][j-1].rq;
        tq=G[i-1][j-1].rq*G[i-1][j].lq;
        ans[j][0]=tp, ans[j][1]=tq;
        nof( &ans[j][0], &ans[j][1]);
    }
    if(n==0) printf("1/1\n");
    else for(int i=1;i<=n+1;i++) printf("%lld/%lld\n", ans[i][0], ans[i][1]);

}