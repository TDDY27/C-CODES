#include <stdio.h>

#if define 
#define maxn1 1000
#else 
#define maxn1 110*110
#endif

#if define 
#define  maxn2 30
#else 
#define maxn2 110
#endif

struct info{
    int v;
    int x;
    int y;
    int z;
};

int fx(long long a,long long mo){
    return (a*77+2222)%mo;
}

void solve(struct info ht[][12],int num[][maxn2][maxn2],struct info k,int mo){
    int now=1;
    int pos=fx(k.v,mo);
    int rec=ht[pos][0].v;
    while(now<=rec){
        if(ht[pos][now].v==k.v) break;
        now++;
    }
    if(now<=rec){
        printf("%d ",k.v);
        struct info tmp=ht[pos][now];
        num[k.x][k.y][k.z]=0, num[tmp.x][tmp.y][tmp.z]=0;
        ht[pos][now]=ht[pos][rec];
        ht[pos][0].v--;
        if(num[tmp.x+1][tmp.y][tmp.z]!=0){
            tmp.x++;
            tmp.v=num[tmp.x][tmp.y][tmp.z];
            solve(ht,num,tmp,mo);
        }
        if(num[k.x+1][k.y][k.z]!=0){
            k.x++;
            k.v=num[k.x][k.y][k.z];
            solve(ht,num,k,mo);
        }
    }else{
        ht[pos][now]=k;
        ht[pos][0].v=now;
    }
}

signed main(){
    struct info ht[maxn1][12];
    for(int i=0;i<maxn1;i++) ht[i][0].v=0;

    int num[maxn2][maxn2][maxn2]={0};

    int n,s,c;
    scanf("%d%d%d", &n,&s,&c);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            for(int k=1;k<=i;k++){
                scanf("%d",&num[i][j][k]);
                if(num[i-1][j][k]==0){
                    struct info tmp;
                    tmp.v=num[i][j][k];
                    tmp.x=i;
                    tmp.y=j;
                    tmp.z=k;
                    solve(ht,num,tmp,s);
                }
            }
        }
    }
}