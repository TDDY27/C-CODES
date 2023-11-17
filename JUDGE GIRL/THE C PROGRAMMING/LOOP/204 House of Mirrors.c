#include <stdio.h>
#define maxn 150 

void swap(int *a,int *b){
    int tmp=*a;
    *a=*b, *b=tmp;
}

signed main(){
    int w,d;
    scanf("%d%d", &w,&d);
    int mp[maxn][maxn];
    for(int i=1;i<=d;i++)
        for(int j=1;j<=w;j++) scanf("%d", &mp[i][j]);
    int out[maxn][maxn];
    int po=0; //print out
    for(int i=1;i<=w;i++) out[d+1][i]=po, po++;
    for(int i=d;i>=1;i--) out[i][w+1]=po, po++;
    for(int i=w;i>=1;i--) out[0][i]=po, po++;
    for(int i=1;i<=d;i++) out[i][0]=po, po++;
        
    
    int ni,nj,pi,pj; // now i now j
    for(int i=1;i<=w;i++){
        ni=d, nj=i;
        pi=-1, pj=0;
        while(ni>=1 && ni<=d && nj>=1 && nj<=w){
            if(mp[ni][nj]==1) swap(&pi,&pj);
            ni+=pi, nj-=pj;
        }
        printf("%d\n", out[ni][nj]);
    }
    for(int i=d;i>=1;i--){
        ni=i, nj=w;
        pi=0, pj=-1;
        while(ni>=1 && ni<=d && nj>=1 && nj<=w){
            if(mp[ni][nj]==1) swap(&pi,&pj);
            ni-=pi, nj+=pj;
        }
        printf("%d\n", out[ni][nj]);
    }
    for(int i=w;i>=1;i--){
        ni=1, nj=i;
        pi=1, pj=0;
        while(ni>=1 && ni<=d && nj>=1 && nj<=w){
            if(mp[ni][nj]==1) swap(&pi,&pj);
            ni+=pi, nj-=pj;
        }
        printf("%d\n", out[ni][nj]);
    }
    for(int i=1;i<=d;i++){
        ni=i, nj=1;
        pi=0, pj=1;
        while(ni>=1 && ni<=d && nj>=1 && nj<=w){
            if(mp[ni][nj]==1) swap(&pi,&pj);
            ni-=pi, nj+=pj;
        }
        printf("%d\n", out[ni][nj]);
    }
}