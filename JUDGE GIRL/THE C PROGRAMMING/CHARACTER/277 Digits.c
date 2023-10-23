#include <stdio.h>
#include <string.h>

signed main(){
	char num[15];
	int w,h;
	while(scanf("%s%d%d",num,&w,&h)!=EOF){
		int len=strlen(num);
		for(int i=1;i<=h;i++){
			for(int j=0;j<len;j++){
				if(i==1 && (num[j]=='0' || num[j]=='2' || num[j]=='3' || num[j]=='5' || num[j]=='6' ||num[j]=='7' || num[j]=='8' || num[j]=='9' ) ){
					for(int k=1;k<=w;k++){
						if(k>=2 && k<=w-2) printf("%c", num[j]);
						else printf(" ");
					}
				}else if(i==1){
					for(int k=1;k<=w;k++) printf(" ");
				}
				if(i==h && (num[j]=='0' || num[j]=='2' || num[j]=='3' || num[j]=='5' || num[j]=='6' || num[j]=='8')){
					for(int k=1;k<=w;k++){
						if(k>=2 && k<=w-2) printf("%c", num[j]);
						else printf(" ");
					}
				}else if(i==h){
					for(int k=1;k<=w;k++) printf(" ");
				}
				if(i==(h+1)/2 && (num[j]=='2' || num[j]=='3' || num[j]=='4' || num[j]=='5' || num[j]=='6' || num[j]=='8' || num[j]=='9' )){
					for(int k=1;k<=w;k++){
						if(k>=2 && k<=w-2) printf("%c", num[j]);
						else printf(" ");
					}
				}else if(i==(h+1)/2){
					for(int k=1;k<=w;k++) printf(" ");
				}
				if( i>1 && i<(h+1)/2 && (num[j]=='1' || num[j]=='2' || num[j]=='3') ){
					for(int k=1;k<=w;k++){
						if(k==w-1) printf("%c", num[j]);
						else printf(" ");
					}
				}else if( i>1 && i<(h+1)/2 && (num[j]=='0' || num[j]=='4' || num[j]=='7' || num[j]=='8' || num[j]=='9')){
					for(int k=1;k<=w;k++){
						if(k==1 || k==w-1) printf("%c", num[j]);
						else printf(" ");
					}
				}else if( i>1 && i<(h+1)/2 && (num[j]=='5' || num[j]=='6') ){
					for(int k=1;k<=w;k++){
						if(k==1) printf("%c", num[j]);
						else printf(" ");
					}
				}
				if( i>(h+1)/2 && i<h && (num[j]=='1' || num[j]=='3' || num[j]=='4' || num[j]=='5' || num[j]=='7' || num[j]=='9')){
					for(int k=1;k<=w;k++){
						if(k==w-1) printf("%c", num[j]);
						else printf(" ");
					}
				}else if( i>(h+1)/2 && i<h && (num[j]=='0' || num[j]=='6' || num[j]=='8')){
					for(int k=1;k<=w;k++){
						if(k==1 || k==w-1) printf("%c", num[j]);
						else printf(" ");
					}
				}else if( i>(h+1)/2 && i<h && num[j]=='2'){
					for(int k=1;k<=w;k++){
						if(k==1) printf("%c", num[j]);
						else printf(" ");
					}
				}
			}
			printf("\n");
		}

	}

}
