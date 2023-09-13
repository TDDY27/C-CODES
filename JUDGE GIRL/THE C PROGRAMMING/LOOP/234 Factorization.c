#include <stdio.h>
#include <string.h>
#define maxn 100000
//#define int long long 

long long fx(long long  x,long long a,long long b,long long c){
    return x*x*x+a*x*x+b*x+c;
}

long long ffx(long long  x,long long a,long long b,long long c){
    return 3*x*x+2*a*x+b;
}

long long fffx(long long  x,long long a,long long b,long long c){
    return 6*x+2*a;
}

signed main(){
    int a,b,c;
    scanf("%d%d%d", &a,&b,&c);

    int rec=1;
    int tmp=c;
    if(c==0) tmp=b;
    if(c==0 && b==0) tmp=a;
    if(tmp<0) tmp*=-1;


    int flag=0;
    for(int i=-tmp;i<=tmp;i++){
        if(fffx(-i,a,b,c)==0 && ffx(-i,a,b,c)==0 && fx(-i,a,b,c)==0 ){
            printf("%d %d %d", i,i,i);
        }else if(ffx(-i,a,b,c)==0 && fx(-i,a,b,c)==0 ){
            printf("%d %d", i,i);
            flag+=2;
            if(flag<3) printf(" ");
        }else if(fx(-i,a,b,c)==0 ){
            printf("%d", i);
            flag++;
            if(flag<3) printf(" ");
        }
    }
}