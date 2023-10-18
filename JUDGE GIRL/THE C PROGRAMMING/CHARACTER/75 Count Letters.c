#include <stdio.h>
#include <string.h>

signed main(){
    char rec[150];
    scanf("%s", rec);
	int len=strlen(rec);
	
	int ans[50]={};
	for(int i=0;i<len;i++){
		if(rec[i]>='A' && rec[i]<'a') ans[rec[i]-'A']++;
		else if(rec[i]>='a' && rec[i]<='z') ans[rec[i]-'a']++;		}	
	for(int i=0;i<26;i++) printf("%d\n", ans[i]); 
}

