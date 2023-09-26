#include <stdio.h>

long long CC(int a,int b){
    long long rec=1;
    for(int i=a;i>=a-b+1;i--) rec*=i;
    for(int i=1;i<=b;i++) rec/=i;
    return rec;
}

signed main(){
    int n,m;
    scanf("%d%d", &n,&m);
    long long ans=0;
    for(int i=0;i<=m;i++) ans+=CC(n,i);
    printf("%d",ans);
}