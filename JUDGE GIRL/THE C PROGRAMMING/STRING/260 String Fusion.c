#include <stdio.h>
#include <string.h>

signed main(){
	char str[130];
	char ans[200];
	scanf("%s",ans);
	int la=strlen(ans);
	int flag;
	while(scanf("%s",str)!=EOF){
		int ln=strlen(str);
		if(ln>la){
			for(int i=0;i<la;i++){
				flag=1; 
				for(int j=0;i+j<la;j++){
					if(ans[i+j]!=str[j]) flag=-1;
				}
				if(flag==1){ flag=i; break;}
			}
		}else{
			for(int i=la-ln;i<la;i++){
				flag=1; 
				for(int j=0;i+j<la;j++){
					if(ans[i+j]!=str[j]) flag=-1;
				}
				if(flag==1){ flag=i; break;}
			}
		}
		if(flag==-1){
			for(int i=la;i<la+ln;i++) ans[i]=str[i-la];
			la+=ln;
		}else{
			for(int i=flag;i<flag+ln;i++) ans[i]=str[i-flag];
			la=flag+ln;
		}
		//printf("%s", ans);
		//printf("%d %d\n", la,ln);
	}
	for(int i=0;i<la;i++) printf("%c", ans[i]);
}
