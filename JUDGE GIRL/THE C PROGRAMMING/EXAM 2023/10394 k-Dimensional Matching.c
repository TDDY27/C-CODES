#include <stdio.h>
#define max(a,b) a>b? a:b

void srch(int svn,int k,int n,int knw,int nnw,int G[][55],int rec[],int pth[][105],int rte[],int num,int *mmax);
void solve(int k,int n,int nnw,int *mmax,int G[][55],int rec[],int pth[][105],int rte[],int num);

void srch(int svn,int k,int n,int knw,int nnw,int G[][55],int rec[],int pth[][105],int rte[],int num,int *mmax){
    if(knw==k-1){ solve(k,n,svn,mmax,G,rec,pth,rte,num+1); return; }
    for(int i=1;i<=G[nnw][0];i++){
        if(rec[G[nnw][i]]==0) continue;
        rec[G[nnw][i]]=0;
        rte[knw]=G[nnw][i];
        srch(svn,k,n,knw+1,G[nnw][i],G,rec,pth,rte,num,mmax);
        rec[G[nnw][i]]=1;
    }
}

void solve(int k,int n,int nnw,int *mmax,int G[][55],int rec[],int pth[][105],int rte[],int num){
    if(nnw==n-1) return;
    if(num>*mmax){
        pth[num][0]=nnw;
        for(int i=0;i<k;i++) pth[num][i+1]=rte[i];
        *mmax=num;
    }
    if(nnw<n-1){
        srch(nnw,k,n,0,nnw+1,G,rec,pth,rte,num,mmax);
        srch(nnw,k,n,0,nnw+1,G,rec,pth,rte,num,mmax);
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
    }
    int pnw=0;
    int mmax=0;
    int pth[55][105]={};
    int rte[105]={};
    srch(0,k,n/k,0,0,G,rec,pth,rte,0,&mmax);   
    printf("%d\n\n", mmax);
    for(int i=1;i<=mmax;i++){
        for(int j=0;j<k;j++) printf("%d ", pth[i][j]);
        printf("\n");
    }
}