#include <stdio.h>
#include <string.h>
#include <ctype.h>

int hash(char str[]){
	int res=0;
	for(int i=0;i<strlen(str);i++) res+=(int)str[i];
	return res%1000;
}

signed main(){
	char ht[1000][4][25];
	int rec[1000][4]={0};
	char str[25];
	while(scanf("%s",str)!=EOF){
		int flag=0;
		for(int i=0;i<strlen(str);i++){
			flag=0;
			if( i==0 && (isalpha(str[0]) || str[0]=='_') ) flag=1;
			if( i!=0 && (isdigit(str[i]) || isalpha(str[i]) || str[i]=='_') ) flag=1;
			if(flag==0) break;
		}
		if(!flag) continue;
		int pos=hash(str);
		printf("%s ", str);
		for(int i=0;i<3;i++){
			if( strcmp(ht[pos][i],str)==0 ){
				rec[pos][i]++;
				printf("%d\n", rec[pos][i]);
				break;
			}else if(rec[pos][i]==0){
				rec[pos][i]++;
				strcpy(ht[pos][i],str);
				printf("1\n");
				break;
			}
		}
	}
}
