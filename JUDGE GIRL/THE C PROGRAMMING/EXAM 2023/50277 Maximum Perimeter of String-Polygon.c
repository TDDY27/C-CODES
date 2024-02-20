#include <stdio.h>
#include <string.h>
#define max(a,b) a>b?a:b

int solve(char str[][105],int n,int now,int cut,int rec,int len){
    if(now==n) return len;
    int nxt=(now+1)%n;
    int l1=strlen(str[now]), l2=strlen(str[nxt]);
    if(nxt==0) l2=rec;
    int mmax=0;
    for(int i=cut;i<l1;i++){
        for(int j=0;j<l2;j++){
            if(str[now][i]!=str[nxt][j]) continue;
            if(now==0) rec=i;
            mmax=max(mmax, solve(str,n,now+1,j,rec,len+i+1-j-1) );
        }
    }
    return mmax;
}

signed main(){
    char str[22][105];
    int now=0;
    while(scanf("%s", str[now])!=EOF) now++;
    printf("%d\n", solve(str,now,0,0,0,0));
}
