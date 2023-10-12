#include <stdio.h>
#define maxn 200000

int n,m;
int mh[maxn];
int sz;

int GL(int p){ //GET LARGEST
    int l=p*2;
    int r=p*2+1;
    int mmax=p;
    if(l<=sz && mh[l]>mh[mmax]) mmax=l;
    if(r<=sz && mh[r]>mh[mmax]) mmax=r;
    return mmax;
}

void MH(int p){ // MAX HEAPIFY
    int mmax;
    mmax=GL(p);
    while(mmax!=p){
        int tmp;
        tmp=mh[p], mh[p]=mh[mmax], mh[mmax]=tmp;
        p=mmax;
        mmax=GL(p);
    }
}

void BMH(){ // BUILD MAX HEAP
    for(int i=sz/2;i>=1;i--) MH(i);
}

int EXT(){
    if(sz<1) return -404;
    int mmax=mh[1];
    mh[1]=mh[sz];
    sz--;
    MH(1);
    return mmax;
}

int INS(int val){
    sz++;
    mh[sz]=val;
    int pos=sz;
    while(pos>1 && mh[pos/2]<mh[pos]){
        int tmp;
        tmp=mh[pos/2], mh[pos/2]=mh[pos], mh[pos]=tmp;
        pos/=2;
    }
}

signed main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%d", &mh[i]);
    sz=n;
    BMH();
    for(int i=1;i<=n;i++) printf("%d%c", mh[i], " \n"[i==n]);
    
    scanf("%d", &m);
    for(int i=0;i<m;i++){
        int tmp;
        scanf("%d", &tmp);
        if(tmp==-1) printf("%d%c", EXT()," \n"[i==m-1]);
        else INS(tmp);
    }
}