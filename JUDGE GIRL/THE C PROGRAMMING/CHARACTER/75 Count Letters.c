#include <stdio.h>
#include <string.h>

signed main(){
    char rec[]={};
    scanf("%s", rec);
	int len=sizeof(rec)/sizeof(char);
	
	printf("%ld\n", sizeof(rec));
	printf("%c", rec[0]);
	printf("%d", len);
	int ans[50]={};
	for(int i=0;i<len;i++){
		if(rec[i]>='A' && rec[i]<'a') ans[rec[i]-'A']++;
		else if(rec[i]>='a' && rec[i]<='z') ans[rec[i]-'a']++;		}	
	for(int i=0;i<26;i++) printf("%d\n", ans[i]); 
	printf("%d", (int)rec[0]-'a');
	printf("%d", 5);
}

