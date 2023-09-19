#include <stdio.h>
#include <string.h>
#define maxn 200050

signed main(){
    int n;
    scanf("%d", &n);
    int num[n+1000];
    for(int i=0;i<n;i++) scanf("%d", &num[i]);
    
    int m;
    scanf("%d", &m);
    int rec[maxn];
    memset(rec,0,sizeof rec);
    for(int i=0;i<n;i++) rec[num[i]%m]++;
    
    for(int i=0;i<=m-1;i++) printf("%d\n", rec[i]);

}