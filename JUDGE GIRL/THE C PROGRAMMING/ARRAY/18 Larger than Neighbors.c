#include <stdio.h>

int G[120][120];

signed main(){
    int r,c;
    scanf("%d%d", &r,&c);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++) scanf("%d", &G[i][j]);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++) 
            if(G[i][j]>G[i-1][j] && G[i][j]>G[i+1][j] && G[i][j]>G[i][j+1] && G[i][j]>G[i][j-1])
                printf("%d\n", G[i][j]);
}