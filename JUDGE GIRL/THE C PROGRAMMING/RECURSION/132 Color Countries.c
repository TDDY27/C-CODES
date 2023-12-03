#include <stdio.h>
#include <stdlib.h>

void solve(int c,int n,int now,int pos,int G[][22],int C[]){
    if(now==n){
        for(int i=0;i<n;i++) printf("%d\n", C[i]);
        exit(0);
    }
    for(int i=1;i<=c;i++){
        int flag=1;
        for(int j=0;j<n;j++){
            if(G[pos][j]==0) continue;
            if(C[j]==i) flag=0;
        }
        if(flag){ C[pos]=i; solve(c,n,now+1,pos+1,G,C); }
    }
}

signed main(){
    int n,c,p;
    scanf("%d%d%d", &n,&c,&p);
    int G[22][22]={};
    int C[22]={};
    for(int i=0;i<p;i++){
        int u,v;
        scanf("%d%d", &u,&v);
        G[u][v]=1;
        G[v][u]=1;
    }
    solve(c,n,0,0,G,C);
    printf("no solution.\n");
}