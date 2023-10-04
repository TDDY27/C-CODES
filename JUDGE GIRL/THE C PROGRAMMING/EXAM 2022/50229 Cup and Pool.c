#include <stdio.h>

struct info{
    int wat;
    int cap;
};

signed main(){
    int k;
    struct info cp[20100];
    scanf("%d", &k);
    for(int i=0;i<k;i++) scanf("%d", &cp[i].cap);
    for(int i=0;i<k;i++) scanf("%d", &cp[i].wat);
    int p,q;
    while(scanf("%d%d", &p,&q)!=EOF){
        if(p==k) cp[q].wat=cp[q].cap;
        else if(q==k) cp[p].wat=0;
        else{
            cp[q].wat+=cp[p].wat;
            if(cp[q].wat>cp[q].cap){
                cp[p].wat=cp[q].wat-cp[q].cap;
                cp[q].wat=cp[q].cap;
            }else cp[p].wat=0;
        }
    }
    for(int i=0;i<k;i++) printf("%d%c", cp[i].wat," \n"[i==k-1]);
}