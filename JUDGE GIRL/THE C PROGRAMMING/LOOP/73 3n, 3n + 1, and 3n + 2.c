#include <stdio.h>

signed main(){
    int z=0,o=0,t=0;
    int n;
    scanf("%d", &n);
    int num;
    for(int i=1;i<=n;i++){
        scanf("%d", &num);
        if(num%3==0) z++;
        else if(num%3==1) o++;
        else t++;
    }
    printf("%d %d %d", z,o,t);
}