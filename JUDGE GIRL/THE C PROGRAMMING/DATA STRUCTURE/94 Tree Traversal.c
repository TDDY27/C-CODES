#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tmpbt{
    int val;
    struct tmpbt *l;
    struct tmpbt *r;
} bt;

bt *bld(char inp[],int *now){
    bt *nde=(bt*) malloc(sizeof(bt*));
    // if(*now>=strlen(inp)) return nde;
    if(inp[*now]=='('){
        *now+=1; // can't use *now++
        nde->l=bld(inp,now);
        *now+=1;
        nde->r=bld(inp,now);
        *now+=1;
        nde->val=(nde->l->val+nde->r->val);
    }else if(inp[*now]<='9' && inp[*now]>='0'){
        nde->val=0, nde->l=NULL, nde->r=NULL;
        while(inp[*now]<='9'&& inp[*now]>='0'){
            nde->val*=10;
            nde->val+=inp[*now]-'0';
            *now+=1;
        }
    }
    return nde;
}

void tra(bt *nde,int ord){
    printf("%d\n", nde->val);
    if(ord==0){
        if(nde->l!=NULL) tra(nde->l,1);
        printf("%d\n", nde->val);
        if(nde->r!=NULL) tra(nde->r,1);
    }else{
        if(nde->l!=NULL) tra(nde->r,0);
        printf("%d\n", nde->val);
        if(nde->r!=NULL) tra(nde->l,0);
    }
    
}

signed main(){
    char inp[4010];
    scanf("%s", inp);
    int now=0;
    bt *rt=bld(inp,&now);
    tra(rt,0);
}