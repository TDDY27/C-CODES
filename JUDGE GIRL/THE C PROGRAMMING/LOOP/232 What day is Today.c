#include <stdio.h>

int y,da,n,m,d;
int flag;

signed main(){
    scanf("%d%d%d", &y,&da,&n);
    if(y%400==0 || (y%4==0 && y%100!=0) ) flag=1;

    while(n>0){
        int rec=0;
        scanf("%d%d", &m,&d);

        if(m>12 || m<1){
            printf("-1\n");
            n--;
            continue;
        }
        for(int i=1;i<m;i++){
            if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
                rec+=31;
            else if(i==2)
                rec+=28+flag;
            else 
                rec+=30;
        }
        rec+=d-1;
        //printf("%d\n", rec);
        int chk=0;
        
        if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12){
            if(d>31 || d<1) chk=1;
        }else if(m==2){
            if(d>28+flag || d<1) chk=1;
        }else if(m==4 || m==6 || m==9 || m==11){
            if(d>30 || d<1) chk=1;
        }

        if(chk==1) printf("-2\n");
        else printf("%d\n", (rec+da)%7 );

        n--;
    }
}