#include <stdio.h>
#include <string.h>
#include <stdlib.h>

signed main(){
	char rec[5000];
	int flag=0;
	int ans=0;
	while( fgets(rec,5000,stdin)!=NULL){
		int len=strlen(rec);
		for(int i=0;i<len;i++){
			if(rec[i]=='.') flag=1;
			else if(flag && rec[i]==' ') flag++;
			else if(flag && rec[i]=='\n') flag+=2;
			else if(flag && rec[i]=='\0') flag=2;
			else flag=0;
			if(flag==2)ans++, flag=0;
		}
	}
	printf("%d\n", ans);
}
