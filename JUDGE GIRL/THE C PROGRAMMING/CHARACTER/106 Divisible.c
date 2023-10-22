#include <stdio.h>
#include <string.h>

signed main(){
	char num[1010];
	while( scanf("%s", num)){
		int len=strlen(num);	
		if(len==2 && num[0]=='-' && num[1]=='1') break;
		
		int sum=0,end=0,so=0,se=0;
		for(int i=0;i<len;i++){
			sum+=num[i]-'0';
			if(i%2) so+=num[i]-'0';
			else se+=num[i]-'0';
			if(i==len-1) end=num[i]-'0';
		}
		if(end%2==0) printf("yes ");
		else printf("no ");
		if(sum%3==0) printf("yes ");
		else printf("no ");
		if(end==0 || end==5) printf("yes ");
		else printf("no ");
		so-=se;
		if(so%11==0) printf("yes\n");
		else printf("no\n");
	}
	

}
