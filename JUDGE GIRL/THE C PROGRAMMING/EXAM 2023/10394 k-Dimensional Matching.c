#include <stdio.h>
#define max(a,b) a>b? a:b

void srch(int svn,int k,int n,int knw,int nnw,int G[][55],int rec[],int pth[][105],int rte[][105],int num,int *mmax);
void solve(int k,int n,int nnw,int *mmax,int G[][55],int rec[],int pth[][105],int rte[][105],int num);

// svn==solve now (the number solving in the first block (k==0))
void srch(int svn,int k,int n,int knw,int nnw,int G[][55],int rec[],int pth[][105],int rte[][105],int num,int *mmax){
    if(knw==k-1){ solve(k,n,svn,mmax,G,rec,pth,rte,num+1); return; }
    rte[num][knw]=nnw;
    for(int i=1;i<=G[nnw][0];i++){
        if(rec[G[nnw][i]]==0) continue;
        rec[G[nnw][i]]=0;
        rte[num][knw+1]=G[nnw][i];
        srch(svn,k,n,knw+1,G[nnw][i],G,rec,pth,rte,num,mmax);
        rec[G[nnw][i]]=1;
    }
}

void solve(int k,int n,int nnw,int *mmax,int G[][55],int rec[],int pth[][105],int rte[][105],int num){
    if(nnw==n) return;
    if(num>*mmax){
        for(int i=0;i<num;i++)
            for(int j=0;j<k;j++) pth[i][j]=rte[i][j];
        *mmax=num;
    }
    int tmp[1005];
    for(int i=0;i<1005;i++) tmp[i]=rec[i];
    for(int i=1; i+nnw<n; i++){
        srch(nnw+i,k,n,0,nnw+i,G,rec,pth,rte,num,mmax);
        for(int j=0;j<1005;j++) rec[j]=tmp[j];
    }
}

signed main(){
    int k,n,e;
    scanf("%d%d%d", &k,&n,&e);
    int G[1005][55]={};
    int rec[1005]={};
    for(int i=0;i<e;i++){
        int u,v;
        scanf("%d%d", &u,&v);
        G[u][0]++;
        G[u][G[u][0]]=v;
        rec[v]=1;
        rec[u]=1;
    }
    // printf("\nshow sth please\n");
    int pnw=0;
    int mmax=0;
    int pth[55][105]={};
    int rte[55][105]={};
    // printf("\nshow sth please\n");
    for(int i=0;i<n/k;i++) srch(i,k,n/k,0,i,G,rec,pth,rte,0,&mmax);   
    // printf("%d\n", mmax);
    for(int i=0;i<mmax;i++){
        for(int j=0;j<k;j++) printf("%d ", pth[i][j]);
        printf("\n");
    }
}
