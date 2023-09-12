#include <stdio.h>
#include <string.h>
#define int long long 

int fx(int x,int a,int b,int c){
    return x*x*x+a*x*x+b*x+c;
}

signed main(){
    int a,b,c;
    scanf("%d%d%d", &a,&b,&c);

    int rec=1;
    int fac[100000];
    memset(fac,0,sizeof fac);
    for(int i=c;i>=1;i--) if(c%i==0) fac[rec]=-i, rec++;
    for(int i=1;i<=c;i++) if(c%i==0) fac[rec]=i, rec++;

    int flag=1;
    for(int i=1;i<=rec;i++){
        if(fx(-fac[i],a,b,c)==0 && flag<3){
            printf("%d ", fac[i]);
            flag++;
        }else if(fx(-fac[i],a,b,c)==0 && flag==3){
            printf("%d", fac[i]);
            break;
        }
    }
}