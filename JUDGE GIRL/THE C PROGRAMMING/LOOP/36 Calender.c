#include <stdio.h>
//#include <stdlib.h>

signed main(){
    int y,m,d;
    scanf("%d%d%d", &y,&m,&d);
    int flag=0;
    if(y%400==0 || (y%4==0 && y%100!=0)) flag=1;

    if(m>12 || m<1 || d>6 || d<0){
        printf("invalid\n");
        return 0;
    }
    int end;
    switch(m){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            end=31; break;
        case 4: case 6: case 9: case 11:
            end=30; break;
        case 2:
            end=28+flag; break;
    }


    printf(" Su Mo Tu We Th Fr Sa\n");
    printf("=====================\n");

    int rec=1;
    d++;
    while(rec<=end){
        printf(" ");
        for(int i=1;i<=7;i++){
            if(rec<d) printf("  "), d--;
            else if(rec<10) printf(" %d", rec), rec++;
            else if(rec>=10) printf("%d", rec), rec++;
            if(rec>end) break;            
            if(i<7) printf(" ");
        }
        printf("\n");
    }
    printf("=====================\n");
}