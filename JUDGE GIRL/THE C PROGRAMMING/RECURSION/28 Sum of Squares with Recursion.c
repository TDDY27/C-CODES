#include <stdio.h>

int solve(int now,int end){
    if(now>end) return 0;
    return now*now+solve(now+1,end);
}

signed main(){
    int end;
    scanf("%d", &end);
    int ans;
    ans=solve(1,end);
    printf("%d", ans);
}