#include <stdio.h>

int v,sa,aa,bb,cc;
//surface area

signed main(){
    int a,b,c,d,e;
    scanf("%d%d%d%d%d", &a,&b,&c,&d,&e);

    aa=a-e*2;
    bb=b-e*2;
    cc=c-e*2;

    v=a*b*c-(aa*cc+bb*cc+aa*bb)*d*2;

    sa=(a*c+a*b+b*c)*2+(aa+bb+cc)*d*8;
    printf("%d\n%d", sa,v);
}
