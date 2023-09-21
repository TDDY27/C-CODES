#include <stdio.h>
#define min(i,j) (i<j? i:j)
#define max(i,j) (i>j? i:j)
#define INF 1e9+500

int num[10050];

signed main(){
    int n,m;
    scanf("%d%d", &n,&m);
    for(int i=1;i<=n;i++) scanf("%d", &num[i]);
    
    int sum=0, mmin=INF,mmax=-1;
    for(int i=0;i<m;i++){
        sum=0, mmin=INF, mmax=-1;
        for(int j=1;j<=n;j++){
            if(num[j]%m!=i) continue;
            sum+=num[j];
            mmax=max(num[j],mmax);
            mmin=min(num[j],mmin);
        }
        printf("%d %d %d\n",sum,mmax,mmin);
    }

}