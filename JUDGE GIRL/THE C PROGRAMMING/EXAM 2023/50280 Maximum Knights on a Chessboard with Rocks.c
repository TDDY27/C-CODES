#include <stdio.h>
#include <stdlib.h>
#define max(x,y) x>y? x:y
 
void solve(int n,int m,int x,int y,int G[][20],int *mmax,int sum){
    if(x==-1 && y==-1) return;
    int rec=0,nx=-1,ny=-1;
    int tmp[20][20];
    for(int i=x;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==x && j<=y) continue;
            if(G[i][j]==0) rec++;
            if(G[i][j]==0 && nx==-1 && ny==-1) nx=i,ny=j;
            tmp[i][j]=G[i][j];
        }
    }
    if(sum+rec<*mmax) return;
    *mmax=max(*mmax,sum);
    solve(n,m,nx,ny,G,mmax,sum);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) G[i][j]=tmp[i][j];;
    int plx[8]={1,2,2,1,-1,-2,-2,-1};
    int ply[8]={2,1,-1,-2,-2,-1,1,2};
    G[x][y]=2;
    for(int i=0;i<8;i++){
        if(x+plx[i]<0 || x+plx[i]>=n || y+ply[i]<0 || y+ply[i]>=m) continue;
        G[x+plx[i]][y+ply[i]]=1;
    }
    nx=-1, ny=-1;
    for(int i=x;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==x && j<=y) continue;
            if(G[i][j]==0 && nx==-1 && ny==-1) nx=i,ny=j;
        }
    }
    *mmax=max(*mmax,sum+1);
    solve(n,m,nx,ny,G,mmax,sum+1);
}
 
signed main(){
    int n,m;
    scanf("%d%d", &n,&m);
    int G[20][20]={};
    int x,y;
    while(scanf("%d%d", &x,&y)!=EOF) G[x][y]=1;
    int stx=-1,sty=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(G[i][j]==0){ 
                stx=i, sty=j; 
                break; 
            }
        }
        if(stx!=-1 && sty!=-1) break;
    }
    int mmax=0;
    solve(n,m,stx,sty,G,&mmax,0);
    printf("%d\n", mmax);
}