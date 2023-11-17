#include <stdio.h>

#if define 
#define maxn 1000
#else  
#define maxn 100050
#endif

int fx(int a,int mo){
    return (77*a+2222)%mo;
}

signed main(){
    int S,C,K;
    scanf("%d%d", &S,&C);
    int ht[maxn][12]={0};

    while(scanf("%d",&K)!=EOF){
        int pos=fx(K,S);
        int rec=ht[pos][0];
        int now=1;
        while(now<=rec){
            if(ht[pos][now]==K) break;
            else now++;
        }
        if(now<=rec){
            ht[pos][now]=ht[pos][rec];
            ht[pos][rec]=0;
            ht[pos][0]--;
            printf("%d %d\n", K,pos);
        }else{
            ht[pos][now]=K;
            ht[pos][0]++;
        }
    }
}