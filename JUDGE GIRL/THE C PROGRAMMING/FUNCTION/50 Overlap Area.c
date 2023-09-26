#include <stdio.h>
#include <stdlib.h>

struct info{
    int lux, luy;
    int ldx, ldy;
    int rux, ruy;
    int rdx, rdy;
};

int area1(struct info a){
    return (a.rux-a.ldx+1)*(a.ruy-a.ldy+1);
}

int area2(struct info a, struct info b){
    if(a.ldx>b.rux || b.ldx>a.rux || a.ruy<b.ldy || b.ruy<a.ldy) return 0;
    if(a.ldx<=b.rux && a.ldy<=b.ruy) return (b.rux-a.ldx+1)*(b.ruy-a.ldy+1);
    if(a.ldx<=b.rux && a.ruy>=b.ldy) return (b.rux-a.ldx+1)*(a.ruy-b.ldy+1);
    if(a.rux>=b.ldx && a.ldy<=b.ruy) return (a.rux-b.ldx+1)*(b.ruy-a.ldy+1);
    if(a.rux>=b.ldx && a.ruy>=b.ldy) return (a.rux-b.ldx+1)*(a.ruy-b.ldy+1);
}

int area3(struct info a,struct info b,struct info c){
    int sum=0,flag;
    for(int i=a.ldx;i<=a.rux;i++){
        for(int j=a.ldy;j<=a.ruy;j++){
            flag=1;
            if(i>a.rux || i<a.ldx || i>b.rux || i<b.ldx || i>c.rux || i<c.ldx) flag=0;
            if(j>a.ruy || j<a.ldy || j>b.ruy || j<b.ldy || j>c.ruy || j<c.ldy) flag=0;
            if(flag==1) sum++;
        }
    }
    return sum;
}

signed main(){
    struct info rt1,rt2,rt3;
    int ans=0;
    scanf("%d%d%d%d", &rt1.ldx, &rt1.ldy, &rt1.rux, &rt1.ruy);
    scanf("%d%d%d%d", &rt2.ldx, &rt2.ldy, &rt2.rux, &rt2.ruy);
    scanf("%d%d%d%d", &rt3.ldx, &rt3.ldy, &rt3.rux, &rt3.ruy);
    ans+=area1(rt1)+area1(rt2)+area1(rt3);
    ans-=area2(rt1,rt2)+area2(rt2,rt3)+area2(rt3,rt1);
    ans+=area3(rt1,rt2,rt3);
    printf("%d\n", ans);
}