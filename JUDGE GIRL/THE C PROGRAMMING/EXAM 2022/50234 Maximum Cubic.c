#include <stdio.h>

int num[150][150][150];
int n;

struct info{
    int v;
    int x;
    int y;
    int z;
};

struct info mh[150*150*150];
int sz;

int GL(int p){ // GET LARGEST
    int l=p*2;
    int r=p*2+1;
    int mmax=p;
    if(l<=sz && mh[l].v>mh[mmax].v) mmax=l;
    if(r<=sz && mh[r].v>mh[mmax].v) mmax=r;
    return mmax;
}

void MH(int p){ // MAX HEAPIFY
    int mmax=GL(p);
    while(mmax!=p){
        struct info tmp;
        tmp=mh[p];
        mh[p]=mh[mmax];
        mh[mmax]=tmp;
        p=mmax;
        mmax=GL(p);
    }
}

void BLD(){ // BUILD
    for(int i=sz/2;i>=1;i--) MH(i);
}

struct info EX(){ // POP MAX
    struct info mmax=mh[1];
    mh[1]=mh[sz];
    sz--;
    MH(1);
    return mmax;
}

void INS(struct info a){
    sz++;
    mh[sz]=a;
    int pos=sz;
    while(pos>1){
        if(mh[pos].v>mh[pos/2].v){
            struct info tmp;
            tmp=mh[pos/2];
            mh[pos/2]=mh[pos];
            mh[pos]=tmp;
        }
        pos/=2;
    }
}


signed main(){
    scanf("%d", &n);
    int end=0;
    sz=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            for(int k=1;k<=i;k++){
                scanf("%d", &num[i][j][k]);
                end++;
                if(j==i || k==i){
                    sz++;
                    mh[sz].v=num[i][j][k];
                    mh[sz].x=i;
                    mh[sz].y=j;
                    mh[sz].z=k;
                }
            }
        }
    }
    BLD();
    while(end>0){
        struct info tmp=EX();
        printf("%d%c", tmp.v," \n"[end==1]);
        num[tmp.x][tmp.y][tmp.z]=0;
        if(tmp.x+1<=n){
            struct info und;
            und.v=num[tmp.x+1][tmp.y][tmp.z];
            und.x=tmp.x+1;
            und.y=tmp.y;
            und.z=tmp.z;
            INS(und);
        }
        end--;
    }
}