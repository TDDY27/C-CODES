#include <stdio.h>

int ra,ch,cr;

signed main(){
    int s,f,t;
    scanf("%d%d%d", &s,&f,&t);
    cr=s-t;
    f-=cr*8;
    ra=(f-2*t)/2;
    ch=s-ra-cr;
    printf("%d\n%d\n%d", ch,ra,cr);
}
