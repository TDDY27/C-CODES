#include <stdio.h>
int G[15][15];

signed main(){
    int n;
    scanf("%d", &n);
    
    int flag=1, win=0;
    int ti,tj,rec=0;
    while(n>0){
        scanf("%d%d", &ti,&tj);
        if(ti>2 || ti<0 || tj>2 || tj<0 || G[ti][tj]!=0 ){ n--;continue;}
        G[ti][tj]=flag;
        for(int i=0;i<=2;i++){
            if(G[0][i]==flag && G[1][i]==flag && G[2][i]==flag){ win=1; break;}
            if(G[i][0]==flag && G[i][1]==flag && G[i][2]==flag){ win=1; break;}
        }
        if(G[0][0]==flag && G[1][1]==flag && G[2][2]==flag) win=1;
        if(G[0][2]==flag && G[1][1]==flag && G[2][0]==flag) win=1;
        
        if(win&&flag==1){ printf("Black wins.\n"); return 0;}
        if(win&&flag==-1){ printf("White wins.\n"); return 0;}
        flag*=-1;
        n--;
    }
    printf("There is a draw.\n");
}