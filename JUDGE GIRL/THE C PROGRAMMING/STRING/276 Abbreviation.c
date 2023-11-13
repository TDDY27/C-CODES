#include <stdio.h>
#include <string.h>

signed main(){
	char wrd[130];
	while(scanf("%s",wrd)!=EOF){
		int ln=strlen(wrd);
		int flag=1;
		if(wrd[ln-1]=='.') ln--, flag=0;
		if(ln==2 && wrd[0]=='o' && wrd[1]=='f') ; 
		else if(ln==2 && wrd[0]=='a' && wrd[1]=='t') ;
		else if(ln==3 && wrd[0]=='t' && wrd[1]=='h' && wrd[2]=='e') ;
		else if(ln==3 && wrd[0]=='a' && wrd[1]=='n' && wrd[2]=='d') ;
		else if(wrd[0]!='.') printf("%c", wrd[0]-'a'+'A');
		if(flag==0) printf("\n");
	}
}
