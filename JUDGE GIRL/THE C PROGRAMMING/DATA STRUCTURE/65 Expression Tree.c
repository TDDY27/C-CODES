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
 
int solve(bt *now,int n,char var[][40],int val[60]){
    if(now->typ==0){
        if(now->nme[0]=='+') return solve(now->l,n,var,val)+solve(now->r,n,var,val);
        else if(now->nme[0]=='-') return solve(now->l,n,var,val)-solve(now->r,n,var,val);
        else if(now->nme[0]=='*') return solve(now->l,n,var,val)*solve(now->r,n,var,val);
        else return solve(now->l,n,var,val)/solve(now->r,n,var,val);
    }else if(now->typ==1){
        for(int i=0;i<n;i++) if(strcmp(var[i],now->nme)==0) return val[i];
    }else if(now->typ==2){
        return now->num;
    }
}

signed main(){
    char inp[40];
    bt *rt;
    scanf("%s", inp);
    rt=bld(inp);

    char var[60][40];
    char bru;
    int val[60];
    int now=0;
    while(scanf("%s", var[now])!=EOF){
        if (strcmp(var[now],")")==0 ) continue;
        scanf(" %c", &bru); // remark the left over new line character in the input buffer
        scanf("%d", &val[now]);
        now++;
    }
    printf("%d\n",solve(rt,now,var,val) );
}