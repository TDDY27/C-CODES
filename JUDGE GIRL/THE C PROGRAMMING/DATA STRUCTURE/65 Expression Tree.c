#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct tmpbt{
    int typ; // 0: operator 1:variable 2:number
    char nme[40];
    int num;
    struct tmpbt *l;
    struct tmpbt *r;
}bt;

bt* bld(char inp[]){
    if(inp[0]=='(' || inp[0]==')'){
        scanf("%s", inp);
        return bld(inp);
    }else if(inp[0]=='+' || inp[0]=='-' || inp[0]=='*' || inp[0]=='/'){
        bt *nde=(bt*)malloc(sizeof(bt));
        // nde->l=NULL, nde->r=NULL;
        nde->typ=0;
        nde->nme[0]=inp[0];
        scanf("%s", inp);
        nde->l=bld(inp);
        scanf("%s", inp);
        nde->r=bld(inp);
        return nde;
    }else if(isalpha(inp[0]) || inp[0]=='_' || inp[0]=='$'){
        bt *nde=(bt*)malloc(sizeof(bt));
        nde->typ=1;
        nde->l=NULL, nde->r=NULL;
        strcpy(nde->nme,inp);
        return nde;
    }else if(isdigit(inp[0])){
        bt *nde=(bt*)malloc(sizeof(bt));
        nde->typ=2;
        nde->l=NULL, nde->r=NULL;
        nde->num=0;
        int now=0;
        while(now<strlen(inp)){
            nde->num*=10;
            nde->num+=inp[now]-'0';
            now+=1;
        }
        return nde;
    }
}

void solve(bt *now,int op,int *rc,int *ans,int n,char var[][40],int val[60]){
    if(now->l!=NULL) solve(now->l,op,rc,ans,n,var,val);
    if(now->typ==0){
        if(now->nme[0]=='+'){
            *ans+=*rc;
            *rc=1;
            op=1;
        }else if(now->nme[0]=='-'){
            *ans+=*rc;
            *rc=-1;
            op=1;
        }else if(now->nme[0]=='*'){
            op=1;
        }else if(now->nme[0]=='/'){
            op=2;
        }
    }else if(now->typ==1){
        int tmp;
        for(int i=0;i<n;i++) if(strcmp(var[i],now->nme)==0) tmp=val[i];
        if(op==1) *rc*=tmp;
        else if(op==2) *rc/=tmp;
    }else if(now->typ==2){
        if(op==1) *rc*=now->num;
        else if(op==2) *rc/=now->num;
    }
    if(now->r!=NULL) solve(now->r,op,rc,ans,n,var,val);
}

void tra(bt *now){
    if(now->l != NULL) tra(now->l);

    if(now->typ==0) printf("%c ", now->nme[0]);
    else if(now->typ==1) printf("%s ", now->nme);
    else if(now->typ==2) printf("%d ", now->num);

    if(now->r != NULL) tra(now->r);
}

signed main(){
    char inp[40];
    bt *rt;
    scanf("%s", inp);
    rt=bld(inp);
    int ans=0, rc=0;
    char var[60][40];
    char bruh;
    int val[60];
    int now=0;

    while(scanf("%s%c%d", var[now],&bruh,&val[now])!=EOF) now++;
    solve(rt,1,&rc,&ans,now,var,val);
    printf("%d\n", ans);
}