#include <stdio.h>

signed main(){
    int r,c;
    scanf("%d%d", &r,&c);
    int num[150][150];
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++) scanf("%d", &num[i][j]);
    int rec;
    for(int j=0;j<c;j++){
        rec=0;
        for(int i=0;i<r;i++) rec+=num[i][j];
        printf("%d\n", rec/r);
    }
}