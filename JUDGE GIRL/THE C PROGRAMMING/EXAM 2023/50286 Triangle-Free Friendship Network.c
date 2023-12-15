#include <stdio.h>

void solve(int n,int m,int now,int sum,int rel[][2],int rec[][70],int *mmax,int ans[][70]){
    if(now==m) return;
    if(sum+m-now<*mmax) return;
    int tmp[70][70];
    int u=rel[now][0], v=rel[now][1];
    int flag=1;
    for(int i=0;i<n;i++) if(rec[u][i]==1 && rec[v][i]==1 ){ solve(n,m,now+1,sum,rel,rec,mmax,ans); return; }
    rec[u][v]=1, rec[v][u]=1;
    if(*mmax<sum+1){
        *mmax=sum+1;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) ans[i][j]=rec[i][j];
    }
    solve(n,m,now+1,sum+1,rel,rec,mmax,ans);
    for(int i=now;i<m;i++) rec[rel[i][0]][rel[i][1]]=0, rec[rel[i][1]][rel[i][0]]=0;
    solve(n,m,now+1,sum,rel,rec,mmax,ans);
}

signed main(){
    int n,m;
    scanf("%d%d", &n,&m);
    int rel[40][2]={};
    for(int i=0;i<m;i++) scanf("%d%d", &rel[i][0],&rel[i][1]);
    int mmax=0;
    int rec[70][70]={};
    int ans[70][70]={};
    solve(n,m,0,0,rel,rec,&mmax,ans);
    // printf("%d\n", &mmax);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(ans[i][j]){ printf("%d %d\n", i,j); ans[j][i]=0; }
        }
    }
}