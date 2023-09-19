#include <stdio.h>

int G[150][150];

signed main(){
    int n;
    scanf("%d", &n);
    //for(int i=0;i<150;i++)
    //    for(int j=0;j<150;j++) G[i][j]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) scanf("%d", &G[i][j]);
    
    int in=0,T=0,tu=0,de=0;
    int rec=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(G[i][j]==0) continue;
            rec=0;
            rec+=G[i+1][j]+G[i-1][j]+G[i][j+1]+G[i][j-1];
            if(rec==4) in++;
            else if(rec==3) T++;
            else if(rec==1) de++;
            else if(rec==2)
                if(G[i+1][j]!=G[i-1][j]) tu++;
        }
    }
    printf("%d\n%d\n%d\n%d\n", in,T,tu,de);
}