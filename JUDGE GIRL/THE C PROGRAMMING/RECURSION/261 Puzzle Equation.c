#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void solve(int now,char a[],char b[],char gl[],int rec[],int na[],int nb[],int ngl[]){
    int l1=strlen(a), l2=strlen(b), l3=strlen(gl);
    int ten=1;
    int aa=0,bb=0,ggl=0;
    for(int i=l1-1;i>=0;i--, ten*=10) aa+=ten*na[i];
    ten=1;
    for(int i=l2-1;i>=0;i--, ten*=10) bb+=ten*nb[i];
    ten=1;
    for(int i=l3-1;i>=0;i--, ten*=10) ggl+=ten*ngl[i];
    if(aa*bb==ggl){
        printf("%d x %d = %d\n", aa,bb,ggl);
       exit(0);
    }
    if(now==-1) return;
    int ta[15],tb[15],tgl[30];
    for(int i=0;i<15;i++) ta[i]=na[i], tb[i]=nb[i];
    for(int i=0;i<30;i++) tgl[i]=ngl[i];
    int nxt=-1;
    for(int i=now+1;i<26;i++) if(rec[i]){ nxt=i; break; }
    for(int i=1;i<=9;i++){
        for(int j=0;j<strlen(a);j++){
            if(a[j]-'A'==now) na[j]=i;
            else if(isdigit(a[j])) na[j]=a[j]-'0';
        }
        for(int j=0;j<strlen(b);j++){
            if(b[j]-'A'==now) nb[j]=i;
            else if(isdigit(b[j])) nb[j]=b[j]-'0';
        }
        for(int j=0;j<strlen(gl);j++){
            if(gl[j]-'A'==now) ngl[j]=i;
            else if(isdigit(gl[j])) ngl[j]=gl[j]-'0';
        }
        solve(nxt,a,b,gl,rec,na,nb,ngl);
        for(int i=0;i<15;i++) na[i]=ta[i], nb[i]=tb[i];
        for(int i=0;i<30;i++) ngl[i]=tgl[i];
    } 
    
}

signed main(){
    char a[15],b[15],gl[30];
    scanf("%s%s%s", a,b,gl);
    int l1,l2,l3;
    l1=strlen(a), l2=strlen(b), l3=strlen(gl);
    int rec[30]={};
    for(int i=0;i<l1;i++) if(isupper(a[i])) rec[a[i]-'A']=1;
    for(int i=0;i<l2;i++) if(isupper(b[i])) rec[b[i]-'A']=1;
    for(int i=0;i<l3;i++) if(isupper(gl[i])) rec[gl[i]-'A']=1;
    int na[15], nb[15], ngl[30];
    for(int i=0;i<l1;i++) na[i]=1;
    for(int i=0;i<l2;i++) nb[i]=1;
    for(int i=0;i<l3;i++) ngl[i]=1;
    int str;
    for(int i=0;i<26;i++) if(rec[i]){ str=i; break;}
    solve(str,a,b,gl,rec,na,nb,ngl);
}