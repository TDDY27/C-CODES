#include <stdio.h>
#define maxn 150

int fst[maxn];
int sec[maxn];
int ans[maxn];

signed main(){
    int n,m;
    scanf("%d", &n);
    for(int i=n-1;i>=0;i--) scanf("%d", &fst[i]);
    scanf("%d", &m);
    for(int i=m-1;i>=0;i--) scanf("%d", &sec[i]);
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=m-1;j++){
            ans[i+j]+=fst[i]*sec[j];
        }
    }
    for(int i=n-1+m-1;i>=0;i--) printf("%d%c",ans[i]," \n"[i==0]);
}