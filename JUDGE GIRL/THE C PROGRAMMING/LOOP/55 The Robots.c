#include <stdio.h>

signed main(){
    int m,n,x1,y1,e1,n1,f1,x2,y2,e2,n2,f2;
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d", &m,&n,&x1,&y1,&e1,&n1,&f1,&x2,&y2,&e2,&n2,&f2);

    int lp1=e1+n1, lp2=e2+n2;


    int t=0;
    while(f1>0 || f2>0){
        if(f1>0) x1+=(t%lp1>=n1),y1+=(t%lp1<n1),f1--;  
        if(f2>0) x2+=(t%lp2<e2),y2+=(t%lp2>=e2),f2--;
        x1%=m, x2%=m, y1%=n, y2%=n;
        t++;
        if(x1==x2 && y1==y2){
            printf("robots explode at time %d", t);
            return 0;
        }
    }
    printf("robots will not explode");
}