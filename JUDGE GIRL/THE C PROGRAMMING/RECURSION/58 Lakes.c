#include <stdio.h>

int  DFS(int G[][410],int i,int j){
    G[i][j]=0;
    int sum=1;
    if( G[i+1][j]==1) sum+=DFS(G,i+1,j);
    if( G[i][j+1]==1) sum+=DFS(G,i,j+1);
    if( G[i-1][j]==1) sum+=DFS(G,i-1,j);
    if( G[i][j-1]==1) sum+=DFS(G,i,j-1);
    return sum;
}

signed main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int G[410][410];
    for(int i=0;i<410;i++)
        for(int j=0;j<410;j++) G[i][j]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) scanf("%d", &G[i][j]);
    int rec[410*410];
    int now=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(G[i][j]==0) continue;
            int ans=DFS(G,i,j);
            rec[now]=ans;
            now++;
        }
    }
    for(int i=0;i<now-1;i++){
        for(int j=i+1;j<now;j++){
            if(rec[i]<rec[j]){
                int tmp=rec[i];
                rec[i]=rec[j];
                rec[j]=tmp;
            }
        }
    }
    for(int i=0;i<now;i++) printf("%d\n", rec[i]);
}