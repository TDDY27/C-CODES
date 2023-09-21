#include <stdio.h>
#define maxn 150

int num[maxn];

int solve(int p,int q){
    int flag,l,r;
    for(int i=p;i<q;i++){
        flag=1;
        if( (i-p+1)%2==1 ) l=(i+p)/2-1, r=(i+p)/2+1;
        else l=(i+p)/2, r=(i+p)/2+1;
        while(l>=p && r<=i){
            if(num[l]!=num[r]) flag=0;
            l--, r++;
        }
        if( (q-(i+1)+1)%2==1 ) l=(i+1+q)/2-1, r=(i+1+q)/2+1;
        else l=(i+1+q)/2, r=(i+1+q)/2+1;
        while(l>i && r<=q){
            if(num[l]!=num[r]) flag=0;
            l--, r++;
        }
        if(flag==1) return 1;
    }
    return 0;
}

signed main(){
    int tmp,rec=0;
    while(scanf("%d", &tmp)!=EOF) num[++rec]=tmp;
    int ans[maxn];
    int la=1; //length of a
    for(int i=1;i<=rec-1;i++){
        for(int j=i+1;j<=rec;j++){
            if(solve(i,j) && j-i+1>=la){
                la=j-i+1;
                for(int k=0;k<la;k++) ans[k]=num[i+k]; 
            }
        }
    }
    for(int i=0;i<la;i++) printf("%d%c", ans[i]," \n"[i==la-1]);
}