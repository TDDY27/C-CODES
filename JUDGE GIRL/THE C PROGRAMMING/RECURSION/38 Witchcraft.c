#include <stdio.h>

int solve(long long des,long long s1,long long s2,long long s3,long long l1,long long l2,long long l3){
    if(des==0) return 1;
    if(des<0) return 0;
    int rec=0;
    for(int i=s1;i>=0;i--){ rec+=solve(des-i*l1,-1,s2,s3,l1,l2,l3); if(rec) return rec;}
    for(int i=s2;i>=0;i--){ rec+=solve(des-i*l2,s1,-1,s3,l1,l2,l3); if(rec) return rec;}
    for(int i=s3;i>=0;i--){ rec+=solve(des-i*l3,s1,s2,-1,l1,l2,l3); if(rec) return rec;}
    return rec;
}

signed main(){
    int n;
    scanf("%d", &n);
    while(n>0){
        long long des,s1,s2,s3,l1,l2,l3; 
        scanf("%lld%lld%lld%lld%lld%lld%lld", &des,&s1,&s2,&s3,&l1,&l2,&l3);
        int ans=solve(des,s1,s2,s3,l1,l2,l3);
        ans>0? printf("yes\n"):printf("no\n");
        n--;
    }

}