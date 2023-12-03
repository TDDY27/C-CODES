#include <stdio.h>
#include <stdlib.h>

void solve(int rec[][12],int G[][12],int x,int y){
    int tmp1[12][12]={};
    int tmp2[12][12]={};
    int mne=0;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(i<x-1 && G[i][j]>0) return;
            if(G[i][j]!=0) mne++;
            tmp1[i][j]=G[i][j];
            tmp2[i][j]=rec[i][j];
        }
    }
    if(mne==0){
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++) printf("%d%c", rec[i][j]," \n"[j==8]);
        exit(0);
    }
    if(x>=9) return;
    int nx=x,ny=y+1;
    nx+=ny/9, ny%=9;
    solve(rec,G,nx,ny);
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++) G[i][j]=tmp1[i][j], rec[i][j]=tmp2[i][j];
    if(G[x][y]<=0) return;
    G[x][y]--;
    int xy[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
    for(int i=0;i<8;i++){
        if(x+xy[i][0]>=9 || x+xy[i][0]<0 || y+xy[i][1]>=9 || y+xy[i][1]<0) continue;
        if(G[x+xy[i][0]][y+xy[i][1]]<=0) return;
        G[x+xy[i][0]][y+xy[i][1]]--;
    }
    rec[x][y]=1;
    solve(rec,G,nx,ny);
}

signed main(){
    int G[12][12]={};
    for(int i=0;i<9;i++) 
        for(int j=0;j<9;j++) scanf("%d", &G[i][j]);
    int rec[12][12]={};
    solve(rec,G,0,0);
    printf("no solution\n");
}