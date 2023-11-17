#include <stdio.h>

int ra,ch,cr;

signed main(){
    int s,f,t;
    scanf("%d%d%d", &s,&f,&t);
    cr=s-t;
    f-=cr*8;
    ra=(f-2*t);
    if(ra%2==1){ printf("0"); return 0;}
    else ra/=2;
    ch=s-ra-cr;
    if(ch>=0 && ra>=0 && cr>=0)printf("%d\n%d\n%d", ch,ra,cr);
    else printf("0");
}
