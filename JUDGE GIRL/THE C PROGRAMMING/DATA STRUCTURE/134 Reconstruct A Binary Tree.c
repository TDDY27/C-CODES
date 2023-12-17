#include <stdio.h>
#include <stdlib.h>
#include <search.h>

typedef struct tmpbst{
    int val;
    int dpt;
    struct tmpbst *l;
    struct tmpbst *r;
}bst;

int cmp(const void *a,const void *b){
    if( (*((bst**)a))->dpt < (*((bst**)b))->dpt) return -1;
    return 1;
}

void bld(bst *now,bst *nde){
    if(nde->val<now->val){
        if(nde->dpt==now->dpt+1){ now->l=nde; return; }
        bld(now->l,nde);
    }else{
        if(nde->dpt==now->dpt+1){ now->r=nde; return; }
        bld(now->r,nde);
    }
}

int fnd(bst *now,int ind){
    if(ind==now->val) return now->dpt;
    if(ind>now->val) fnd(now->r,ind);
    else fnd(now->l,ind);
}

int cmn(int a,int b,bst *now){
    if(now->val>b) cmn(a,b,now->l);
    else if(now->val<a) cmn(a,b,now->r);
    else return now->dpt;
}

signed main(){
    bst *nds[1005];
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        nds[i]=(bst*)malloc(sizeof(bst));
        scanf("%d%d", &(nds[i]->val),&(nds[i]->dpt));
    }
    qsort(nds,n,sizeof(bst*),cmp);

    bst *rt=nds[0];
    for(int i=1;i<n;i++) bld(rt,nds[i]);

    int p;
    scanf("%d", &p);
    for(int i=0;i<p;i++){
        int a,b;
        scanf("%d%d", &a,&b);
        int da,db;
        da=fnd(rt,a), db=fnd(rt,b);
        int cpar;
        if(a>b) cpar=cmn(b,a,rt);
        else cpar=cmn(a,b,rt);
        printf("%d\n", da-cpar+db-cpar);
    }
}