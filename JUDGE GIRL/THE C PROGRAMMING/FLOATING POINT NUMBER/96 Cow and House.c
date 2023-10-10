#include <stdio.h>
#define pi 3.1415926

signed main(){
    double a,b,c;
    scanf("%lf%lf%lf", &a,&b,&c);
    double area;
    area=c*c*pi*3/4;
    if(c>b) area+=(c-b)*(c-b)*pi/4;
    if(c>a) area+=(c-a)*(c-a)*pi/4;
    printf("%lf",area);
}