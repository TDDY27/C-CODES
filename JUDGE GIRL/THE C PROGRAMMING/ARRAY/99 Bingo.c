#include <stdio.h>
#include <string.h>
#define maxn 260*260

int R[maxn][15][2];
int G[260][260][15];
char ppl[15][70];
 
signed main(){
    int n,m;
    scanf("%d%d", &n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s", ppl[i]);
        for(int j=1;j<=m;j++){
            for(int k=1;k<=m;k++){ 
                scanf("%d", &(G[j][k][i]));
                R[ G[j][k][i] ][i][0]=j;
                R[ G[j][k][i] ][i][1]=k;
            }
        }
    }
 
    int num,rec,flag=0,frst=1;
    int rj,rk; //rec j, rec k;
    while(frst){
        scanf("%d", &num);
        for(int i=1;i<=n;i++){
            flag=0;
            rj=R[num][i][0], rk=R[num][i][1];
            G[rj][rk][i]=-1;
            // printf("%d %d\n",rj,rk);
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
            if(flag==1 && frst==1){ printf("%d", num); frst=0;}
            if(flag==1) printf(" %s", ppl[i]);
        }
    }
    return 0;
}