#include <stdio.h>

int na[513][513]; // n array
int ka[129][129]; // k array
int ans[513][513];

signed main(){
    int n,k;
    scanf("%d%d", &n,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) scanf("%d", &na[i][j]);
    for(int i=1;i<=k;i++)
        for(int j=1;j<=k;j++) scanf("%d", &ka[i][j]);
    for(int i=1;i<=n-k+1;i++){
        for(int j=1;j<=n-k+1;j++){
            ans[i][j]=0;
            for(int p=0;p<k;p++){
                for(int q=0;q<k;q++){
                    ans[i][j]+=na[i+p][j+q]*ka[p+1][q+1];
                }
            }

        }
    }
    for(int i=1;i<=n-k+1;i++){
        for(int j=1;j<=n-k+1;j++){
            printf("%d%c",ans[i][j]," \n"[j==n-k+1] );
        }
    }
}   