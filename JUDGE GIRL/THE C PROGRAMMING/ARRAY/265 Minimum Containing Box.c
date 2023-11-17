#include <stdio.h>
#define INF 1e9+500;
#define _INF -1e9-500;
#define max(i,j) (i>j? i:j)
#define min(i,j) (i<j? i:j)

signed main(){
    int mxx=_INF; int mxy=_INF; int mix=INF; int miy=INF;
    int ti,tj;
    while(scanf("%d%d", &ti,&tj)!=EOF){
        mxx=max(mxx,ti);
        mix=min(mix,ti);
        mxy=max(mxy,tj);
        miy=min(miy,tj);
    }
    printf("%d", (mxx-mix)*(mxy-miy) );
}