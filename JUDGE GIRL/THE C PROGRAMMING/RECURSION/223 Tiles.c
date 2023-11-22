#include <stdio.h>

void solve(int cx,int cy,int typ,int l,int m){
    if(l==2){
        printf("%d %d %d\n", typ,cx,cy);
        return;
    } 
    if(m*2<l){
        solve(cx,cy,typ,m*2,m);
        solve(cx-m,cy-m,typ,l,m*2);
        return;
    }
    solve(cx,cy,typ,l/2,m/2);
    if(typ==1){
        solve(cx-m/2,cy-m/2,1,l/2,m/2);
        solve(cx-m/2,cy+m/2,4,l/2,m/2);
        solve(cx+m/2,cy-m/2,2,l/2,m/2);
    }else if(typ==2){
        solve(cx+m/2,cy-m/2,2,l/2,m/2);
        solve(cx-m/2,cy-m/2,1,l/2,m/2);
        solve(cx+m/2,cy+m/2,3,l/2,m/2);
    }else if(typ==3){
        solve(cx+m/2,cy+m/2,3,l/2,m/2);
        solve(cx+m/2,cy-m/2,2,l/2,m/2);
        solve(cx-m/2,cy+m/2,4,l/2,m/2);
    }else if(typ==4){
        solve(cx-m/2,cy+m/2,4,l/2,m/2);
        solve(cx-m/2,cy-m/2,1,l/2,m/2);
        solve(cx+m/2,cy+m/2,3,l/2,m/2);
    }
    
}

signed main(){
    int l,m;
    scanf("%d%d", &l,&m);
    solve(l-m,l-m,1,l,m);
}