#include <stdio.h>
#include <string.h>

int scmp(int n1,int n2,int l1,int l2,char s1[],char s2[]){
    if(n1==l1 && n2<l2) return l2-n2;
    else if(n1<l1 && n2==l2) return l1-n1;
    else if(n1==l1 && n2==l2) return 0;
    if(s1[n1]==s2[n2]) return scmp(n1+1,n2+1,l1,l2,s1,s2);
    int mnm,tmp1,tmp2;;
    tmp1=1+scmp(n1+1,n2,l1,l2,s1,s2);
    tmp2=1+scmp(n1,n2+1,l1,l2,s1,s2);
    mnm= tmp1<tmp2? tmp1:tmp2; 
    return mnm;
}

signed main(){
    int n=0;
    char str[102][12];
    int lng[102];
    while(scanf("%s", str[n])!=EOF){ lng[n]=strlen(str[n]); n++; }
    int id1,id2,mnm=100000;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int l1,l2;
            l1=strlen(str[i]), l2=strlen(str[j]);
            if(l2-l1>mnm || l1-l2>mnm) continue;
            int tmp=scmp(0,0,l1,l2,str[i],str[j]);
            if(tmp<mnm) mnm=tmp,id1=i,id2=j;
        }
    }
    printf("%d %d %d\n", mnm,id1+1,id2+1);
}