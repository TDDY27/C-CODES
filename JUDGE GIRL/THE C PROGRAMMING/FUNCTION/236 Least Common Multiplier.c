#include <stdio.h>

int gcd(int a,int b){
    while(a>0 && b>0){
        int tmp;
        if(a>b) a%=b; 
        else b%=a;
    }
    if(a>b) return a;
    return b;
}

signed main(){
    int rec,num;
    scanf("%d", &rec);
    while(scanf("%d", &num)!=EOF){
        int tmp;
        tmp=gcd(rec,num);
        rec=num*rec/tmp;
    }
    printf("%d", rec);
}