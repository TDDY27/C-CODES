#include <stdio.h>

signed main(){
    long long a,b,c,d,e,f,g;
    scanf("%lld%lld%lld%lld%lld%lld%lld", &a,&b,&c,&d,&e,&f,&g);
    if(a<0) b*=-1;
    if(e<0) g*=-1;
    b+=a*c, f+=e*g;
    b*=g, f*=c;
    c*=g, g=c;
    //printf("%d %d %d\n%d %d %d\n", a,b,c,e,f,g);
    long long h=0,i,j;
    if(d==0) i=b+f, j=c;
    else if(d==1) i=b-f, j=c;
    else if(d==2) i=b*f, j=c*c;
    else i=b*c, j=c*f;
    //printf("%d %d %d\n%d %d %d\n", a,b,c,e,f,g);
    long long flag=1;
    if(i<0) i*=-1, flag*=-1;
    if(j<0) j*=-1, flag*=-1;
    long long gcd, tmpi=i, tmpj=j;
    while(tmpi!=0 && tmpj!=0){
        if(tmpi>tmpj) tmpi-=tmpj;
        else tmpj-=tmpi;
    }
    //printf("10000000");
    gcd= tmpj>tmpi? tmpj : tmpi;
    i/=gcd, j/=gcd;
    h=i/j*flag;
    i=i%j;
    printf("%lld\n%lld\n%lld\n", h,i,j);

}
