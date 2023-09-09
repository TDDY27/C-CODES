#include <stdio.h>

int n,ith;

signed main(){
    scanf("%d%d", &n,&ith);
    int tmp=n;
    for(int i=2;i<=ith;i++) n*=tmp;
    printf("%d", n);
}
