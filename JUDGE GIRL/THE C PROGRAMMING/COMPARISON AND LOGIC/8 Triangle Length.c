#include <stdio.h>

int a,b,c;

signed main(){
    scanf("%d%d%d", &a,&b,&c);
    if(a+b>c && a+c>b && b+c>a) printf("1");
    else printf("0");
}
