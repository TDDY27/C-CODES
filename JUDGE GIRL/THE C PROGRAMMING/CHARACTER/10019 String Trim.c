#include <stdio.h>
#include <string.h>
#include <ctype.h>

signed main(){
	char rec[150];
	while(fgets(rec,150,stdin)!=NULL){
		int len=strlen(rec);
		int l=0,r=len-1;
		while( isspace(rec[l])) l++;
		while( isspace(rec[r])) r--;
		for(int i=l;i<=r;i++) printf("%c", rec[i]);
	}
}
