#include <stdio.h>
#include <stdlib.h>
#define min(i,j) i<j? i:j
#define max(i,j) i>j? i:j

struct info{
    int ldx, ldy;
    int rux, ruy;
};

int area1(struct info a){
    return (a.rux-a.ldx)*(a.ruy-a.ldy);
}

int area2(struct info a, struct info b){
    if(a.ldx>b.rux || b.ldx>a.rux || a.ruy<b.ldy || b.ruy<a.ldy) return 0;
    struct info trt;
    trt.rux=min(a.rux,b.rux);
    trt.ruy=min(a.ruy,b.ruy);
    trt.ldx=max(a.ldx,b.ldx);
    trt.ldy=max(a.ldy,b.ldy);
    return (trt.rux-trt.ldx)*(trt.ruy-trt.ldy);
}

int area3(struct info a,struct info b,struct info c){
    if(a.ldx>b.rux || b.ldx>a.rux || a.ruy<b.ldy || b.ruy<a.ldy) return 0;
    struct info trt;
    trt.rux=min(a.rux,b.rux);
    trt.ruy=min(a.ruy,b.ruy);
    trt.ldx=max(a.ldx,b.ldx);
    trt.ldy=max(a.ldy,b.ldy);
    return area2(trt,c);
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