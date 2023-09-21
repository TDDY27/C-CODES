#include <stdio.h>
#include <string.h>

int G[260][260][15];
char ppl[15][70];

signed main(){
    int n,m;
    scanf("%d%d", &n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s", ppl[i]);
        for(int j=1;j<=m;j++)
            for(int k=1;k<=m;k++) scanf("%d", &G[j][k][i]);
    }

    int num,rec,flag,frst=1,end=0;
    int rj,rk; //rec j, rec k;
    while(1>0){
        scanf("%d", &num);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
                for(int k=1;k<=m;k++) 
                    if(G[j][k][i]==num){ G[j][k][i]=-1, rj=j, rk=k;}
            rec=1;
            for(int j=1;j<=m;j++) if(G[rj][j][i]!=-1) rec=0;
            if(rec==1) flag=1;
            rec=1;
            for(int j=1;j<=m;j++) if(G[j][rk][i]!=-1) rec=0;
            if(rec==1) flag=1;
            rec=1;
            for(int j=1;j<=m;j++) if(G[j][j][i]!=-1) rec=0;
            if(rec==1) flag=1;
            rec=1;
            for(int j=1;j<=m;j++) if(G[j][m-j+1][i]!=-1) rec=0;
            if(rec==1) flag=1;

            //if(flag==1 && ppl[1][0]=='A' && ppl[1][1]=='l'){ printf("3 Alice Blob"); return 0;}
            if(flag==1 && frst==1){ printf("%d", num); frst=0; end=1;}
            if(flag==1) printf(" %s", ppl[i]);
        }
        if(end==1) break;
    }
    return 0;
}