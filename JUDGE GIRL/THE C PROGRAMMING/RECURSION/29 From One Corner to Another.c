#include <stdio.h>
 
int solve(int r,int c){
    int sum=0;
    if(r==0 && c==0) return 1;
    if(r<0 || c<0) return 0;
    if(r>0) sum+=solve(r-1,c);
    if(c>0) sum+=solve(r,c-1);
    return sum;
}
 
signed main(){
    int r,c;
    scanf("%d%d", &r,&c);
    int ans=solve(r-1,c-1);
    printf("%d\n", ans);
}