#include <stdio.h>

int solve(int gl,int n,int now,int num[]){
    if(gl==0) return 1;
    if(gl<0) return 0;
    if(now>=n) return 0;
    int ttl=0;
    ttl+=solve(gl-num[now],n,now+1,num)+solve(gl,n,now+1,num);
    return ttl;
}

signed main(){
    int n;
    scanf("%d", &n);
    int num[20];
    for(int i=0;i<n;i++) scanf("%d", &num[i]);
    int gl;
    while(scanf("%d", &gl)!=EOF){
         int ans=solve(gl,n,0,num);
        printf("%d\n", ans);
    }
}