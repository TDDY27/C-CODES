#include <stdio.h>
#include <string.h>

signed main(){
	char vo[10]={'a','e','i','o','u','A','E','I','O','U'};
	char str[150];
	
	scanf("%s", str);
	int len=strlen(str);
	int num=0, alp=0, vow=0, con=0;
	for(int i=0;i<len;i++){
		if( (str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z') ){
			alp++;
			int flag=0;
			for(int j=0;j<10;j++) 
				if(str[i]==vo[j]) flag=1;
			if(flag) vow++;
			else con++;
		}
		if(str[i]>='0' && str[i]<='9') num++;
	}
	printf("%d %d %d %d\n", num,alp,vow,con);
}
