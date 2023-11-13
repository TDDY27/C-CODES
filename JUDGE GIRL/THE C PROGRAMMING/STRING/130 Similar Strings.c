#include <stdio.h>
#include <string.h>

signed main(){
	char st1[100];
	char st2[100];
	int n;
	scanf("%d",&n);
	while(n>0){
		scanf("%s%s", st1,st2);
		int ln1,ln2;
		ln1=strlen(st1), ln2=strlen(st2);
		int rec=0;
		int now=0;
		if(ln1-ln2==1){
			while(now<ln2){
				if(st1[now+rec]!=st2[now]) rec++,now--;
				if(rec>1) break;
				now++;
			}
		}else if(ln2-ln1==1){
			while(now<ln1){
				if(st2[now+rec]!=st1[now]) rec++,now--;
				if(rec>1) break;
				now++;
			}
		}else if(ln2==ln1){
			while(now<ln1){
				if(st1[now]!=st2[now] && st1[now]==st2[now+1] && st1[now+1]==st2[now]) rec++, now++;
				else if(st1[now]!=st2[now]) rec+=2;
				if(rec>1) break;
				now++;
			}
		}
		if(now>0 && rec<2) printf("yes\n");
		else printf("no\n");

		n--;
	}
}
