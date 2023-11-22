#include <stdio.h>

void solve(int r,int n,int rec[],int num[],int flag){
    if(r==n) for(int i=0;i<r;i++) printf("%d%c", rec[i]," \n"[i==n-1]);
    int tmp[10];
    for(int i=0;i<10;i++) tmp[i]=num[i];
    for(int i=0;i<n;i++){
        if(num[i]==flag) continue;
        rec[r]=num[i], num[i]=flag;
        solve(r+1,n,rec,num,flag);
        num[i]=tmp[i];
    }
}

signed main(){
    int n;
    scanf("%d", &n);
    int num[10];
    for(int i=0;i<n;i++) scanf("%d", &num[i]);
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(num[i]>num[j]){
                int tmp=num[j];
                num[j]=num[i], num[i]=tmp;
            }
        }
    }
    int rec[10];
    int flag=num[0]-1;
    solve(0,n,rec,num,flag);
}