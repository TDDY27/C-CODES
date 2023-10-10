#include <stdio.h>

signed main(){
    int n;
    scanf("%d", &n);
    double M[20][20];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) scanf("%lf", &M[i][j]);
    double res[20];
    for(int i=1;i<=n;i++) scanf("%lf", &res[i]);
    double ans[20];
    for(int i=n;i>=1;i--){
        for(int j=n;j>i;j--){
            res[i]-=M[i][j]*ans[j];
        }
        ans[i]=res[i]/M[i][i];
    }
    for(int i=1;i<=n;i++) printf("%lf\n", ans[i]);


}