#include <stdio.h>

signed main(){
    int n;
    scanf("%d", &n);
    int num[1500];
    for(int i=1;i<=n;i++) scanf("%d", &num[i]);
    for(int i=n;i>=1;i--){
        printf("%d", num[i]);
        if(i!=1) printf(" ");
    }
}