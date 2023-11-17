#include <stdio.h>

signed main(){
    int n;
    scanf("%d", &n);
    int odd[1500], even[1500];
    int no=0,ne=0;
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d", &tmp);
        if(tmp%2==1) odd[no++]=tmp;
        else even[ne++]=tmp;
    }
    for(int i=0;i<no;i++){
        printf("%d",odd[i]);
        if(i!=no-1) printf(" ");
    }
    printf("\n");
    for(int i=0;i<ne;i++){
        printf("%d",even[i]);
        if(i!=ne-1) printf(" ");
    }
}