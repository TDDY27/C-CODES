#include <stdio.h>

int  solve(int num[],int k,int n,int now,int pos,int m){
    if(pos>n || m<0 || now>k) return 0;
    if(now==k && m>=0) return 1;
    return  solve(num,k,n,now+1,pos+1,m-num[pos])+solve(num,k,n,now,pos+1,m);
}

signed main(){
    int k,n,m;
    scanf("%d%d%d", &k,&n,&m);
    int num[22];
    for(int i=0;i<n;i++) scanf("%d", &num[i]);
    int ttl=0;
    for(int i=k;i<=n;i++) ttl+=solve(num,i,n,0,0,m);
    printf("%d\n", ttl);
}