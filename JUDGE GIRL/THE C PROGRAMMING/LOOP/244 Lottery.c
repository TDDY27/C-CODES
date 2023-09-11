#include <stdio.h>

signed main(){
    int sp1,sp2,sp3,fs1,fs2,fs3;
    scanf("%d%d%d%d%d%d", &sp1,&sp2,&sp3,&fs1,&fs2,&fs3);

    int num,sum=0;
    while(scanf("%d",&num)!=EOF){
        if(num==sp1) sum+=2000000;
        if(num==sp2) sum+=2000000;
        if(num==sp3) sum+=2000000;

        int tmp=num,tmp1=fs1,tmp2=fs2,tmp3=fs3,sm1=0,sm2=0,sm3=0;// sm=same
        for(int i=0;i<8;i++, tmp/=10, tmp1/=10){
            if(tmp%10==tmp1%10) sm1++;
            else break;
        }
        tmp=num;
        for(int i=0;i<8;i++, tmp/=10, tmp2/=10){
            if(tmp%10==tmp2%10) sm2++;
            else break;
        }
        tmp=num;
        for(int i=0;i<8;i++, tmp/=10, tmp3/=10){
            if(tmp%10==tmp3%10) sm3++;
            else break;
        }

        switch(sm1){
            case 3: sum+=200; break; case 4: sum+=1000; break; case 5: sum+=4000; break;
            case 6: sum+=10000; break; case 7: sum+=40000; break; case 8: sum+=200000; break;
            default: sm1=0; 
        }
        switch(sm2){
            case 3: sum+=200; break; case 4: sum+=1000; break; case 5: sum+=4000; break;
            case 6: sum+=10000; break; case 7: sum+=40000; break; case 8: sum+=200000; break;
            default: sm2=0;
        }
        switch(sm3){
            case 3: sum+=200; break; case 4: sum+=1000; break; case 5: sum+=4000; break;
            case 6: sum+=10000; break; case 7: sum+=40000; break; case 8: sum+=200000; break;
            default: sm3=0;
        }
    }
    printf("%d\n" ,sum);
}