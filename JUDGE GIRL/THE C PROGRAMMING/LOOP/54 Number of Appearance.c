#include <stdio.h>

signed main(){
    int n,m;
    scanf("%d%d", &n, &m);

    int tmpn,tmpm;
    int ans=0;
    for(int i=0;i<7;i++, m/=10){
        tmpn=n;
        tmpm=m;
        for(int j=0;j<2;j++, tmpn/=10, tmpm/=10){
            if(tmpn%10==tmpm%10 && j==1) ans++;
            else if(tmpn%10!=tmpm%10) break;
        }
    }
    printf("%d\n", ans);
}