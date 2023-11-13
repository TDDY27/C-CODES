#include <stdio.h>
#include <string.h>

signed main(){
	int n;
	scanf("%d", &n);
	char info[105][15][65];
	int rec[105]={0};
	int now=0;
	while(now<n){
		scanf("%s", info[now][0]);
		int num;
		scanf("%d", &num);
		for(int i=1;i<=num;i++) scanf("%s", info[now][i]);
		rec[now]=num;
		for(int i=1;i<=num-1;i++){
			for(int j=i+1;j<=num;j++){
				if(strcmp(info[now][i],info[now][j])>0){
					char* tmp=info[now][i];
					info[now][i]=info[now][j];
					info[now][j]=tmp;
				}
			}
		}
		now++;
	}
	int m;
	scanf("%d", &m);
	while(m>0){
		char fda[65], fdb[65];
		scanf("%s%s", fda,fdb);
		int posa,posb;
		for(int i=0;i<n;i++){
			if(strcmp(fda,info[i][0])==0) posa=i;
			if(strcmp(fdb,info[i][0])==0) posb=i;
		}
		for(int i=1;i<=rec[posa];i++){
			for(int j=1;j<=rec[posb];j++)
				if(strcmp(info[posa][i],info[posb][j])==0) printf("%s ", info[posa][i]);
		}
		printf("\n");
		m--;
	}
}
