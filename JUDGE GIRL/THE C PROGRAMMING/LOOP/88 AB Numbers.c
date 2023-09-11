#include <stdio.h>

int a,b;
int A,B;

signed main(){
    scanf("%d%d", &a,&b);

    int tmpa=a,tmpb=b;
    for(int i=0;i<4; i++, tmpa/=10, tmpb/=10) if(tmpa%10==tmpb%10) A++;

    tmpa=a;
    for(int i=0;i<4; i++, tmpa/=10){
        tmpb=b;
        for(int j=0;j<4; j++, tmpb/=10){
            if(i==j) continue;
            if(tmpa%10==tmpb%10) B++;
        }
    }
    printf("%dA%dB", A,B);
}
