#include <stdio.h>
#include <stdlib.h>
#define INF 1e9

struct info{
    int x;
    int y;
    int c;
};

signed main(){
    int n,m;
    struct info lt[20];
    scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%d%d%d", &lt[i].x, &lt[i].y, &lt[i].c);
    
    scanf("%d", &m);
    int xx,yy;
    int min, rec, recx, recy; 
    int ans[20];
    for(int i=0;i<=n;i++) ans[i]=0;

    for(int i=0;i<m;i++){
        scanf("%d%d", &xx, &yy);

        min=INF;
        for(int j=1;j<=n;j++){
            if( abs(xx-lt[j].x)+abs(yy-lt[j].y)<min && lt[j].c>0){
                rec=j;
                recx=lt[j].x;
                recy=lt[j].y;
                min=abs(xx-lt[j].x)+abs(yy-lt[j].y);
            }else if( abs(xx-lt[j].x)+abs(yy-lt[j].y)==min && lt[j].c>0){
                if(lt[j].x<recx) rec=j, recx=lt[j].x, recy=lt[j].y;
                else if(lt[j].x==recx && lt[j].y<recy) rec=j, recx=lt[j].x, recy=lt[j].y;
            }
        }
        ans[rec]++;
        lt[rec].c--;
    }

    for(int i=1;i<=n;i++) printf("%d\n", ans[i]);


}