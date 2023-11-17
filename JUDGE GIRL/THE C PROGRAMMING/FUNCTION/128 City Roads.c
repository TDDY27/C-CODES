#include "intersection.h"

void intersection(int map[100][100], int result[4]){
    int in=0,T=0,tu=0,de=0;
    int rec;
    int G[150][150];
    for(int i=0;i<150;i++)
        for(int j=0;j<150;j++) G[i][j]=0;
    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++) G[i+1][j+1]=map[i][j];

    for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++){
            if(G[i][j]==0) continue;
            rec=0;
            rec+=G[i+1][j]+G[i-1][j]+G[i][j+1]+G[i][j-1];
            if(rec==4) in++;
            else if(rec==3) T++;
            else if(rec==1) de++;
            else if(rec==2)
                if(G[i+1][j]!=G[i-1][j]) tu++;
        }
    }
    result[0]=in, result[1]=T, result[2]=tu, result[3]=de;
}   