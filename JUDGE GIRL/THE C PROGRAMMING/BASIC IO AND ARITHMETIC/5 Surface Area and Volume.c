#include <stdio.h>

signed main(){
    int a,b,c;
    scanf("%d%d%d", &a,&b,&c);
    printf("%d\n", a*b*2+a*c*2+b*c*2);
    printf("%d\n", a*b*c);
}
