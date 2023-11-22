#include <stdio.h>

int solve(int a,int b,int c,int uni[][4]){
    if(a==0 && b==0 && c==0)return 1;
    if(a<0 || b<0 || c<0) return 0;
    int rec=0;
    rec+=solve(a-uni[0][0],b-uni[0][1],c-uni[0][2],uni);
    rec+=solve(a-uni[1][0],b-uni[1][1],c-uni[1][2],uni);
    rec+=solve(a-uni[2][0],b-uni[2][1],c-uni[2][2],uni);
    return rec;
}

void rpt(int t,int uni[][4]){
    if(t<=0) return;
    int a,b,c;
    scanf("%d%d%d", &a,&b,&c);
    int res=solve(a,b,c,uni);
    res>0? printf("yes\n"):printf("no\n");
    rpt(t-1,uni);
}

signed main(){
    int uni[4][4];// da db dc ea eb ec da db dc
    scanf("%d%d%d", &uni[0][0], &uni[0][1], &uni[0][2]);
    scanf("%d%d%d", &uni[1][0], &uni[1][1], &uni[1][2]);
    scanf("%d%d%d", &uni[2][0], &uni[2][1], &uni[2][2]);
    int n;
    scanf("%d",&n);
    rpt(n,uni);
}