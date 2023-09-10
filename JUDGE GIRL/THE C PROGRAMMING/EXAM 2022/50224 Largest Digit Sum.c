#include <stdio.h>

int num;
int msum,mdi,mnum;
int tsum,tdi,tnum;

signed main(){
    scanf("%d", &num);
    mnum=num;
    while(num!=0){
        mdi++;
        msum+=num%10;
        num/=10;
    }

    int flag;
    while(scanf("%d", &num)!=EOF){
        flag=0, tsum=0, tdi=0, tnum=0;
        tnum=num;
        while(tnum!=0){
            tdi++;
            tsum+=tnum%10;
            tnum/=10;
        }
        if(tsum>msum) flag=1;
        else if(tsum==msum){
            if(tdi<mdi) flag=1;
            else if(tdi==mdi){
                if(num>mnum) flag=1;
            }
        }
        if(flag==1) msum=tsum, mdi=tdi, mnum=num;
    }
    printf("%d", mnum);
}