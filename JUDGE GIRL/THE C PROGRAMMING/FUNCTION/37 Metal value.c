// #include <stdio.h>

#include "value.h"

int value(int type, int width, int height, int length){
    int p=-1;
    long long w=width, h=height, l=length;
    switch(type){
        case 79: p=30; break;
        case 47: p=10; break;
        case 29: p=4; break;
        case 82: p=5; break;
        case 26: p=3; break;
        case 22: p=9; break;
    }
    if(p==-1) return -1;
    if(w<=0 || h<=0 || l<=0 ) return -2;
    long long ans=0;
    int tmp,tw=w,th=h,tl=l;
    while(tw>0 && th>0){
        if(tw>th) tw-=th;
        else th-=tw;
    }
    tmp= tw>th? tw:th;
    while(tmp>0 && tl>0){
        if(tmp>tl) tmp-=tl;
        else tl-=tmp;
    }
    tmp= tmp>tl? tmp:tl;
    ans=tmp*tmp*tmp*w*h*l*p;

    return ans;
}

// signed main(){
//     int ty,wi,he,le;
//     scanf("%d%d%d%d", &ty,&wi,&he,&le);
//     printf("%d", value(ty,wi,he,le));
// }