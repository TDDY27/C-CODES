#include <stdio.h>
#include <string.h>
 
signed main(){
    char lne[100000] = {0};
    char* suf[]={"ed","tion","ness","ful","ing","ly","able","ous","ish","ive","less","ism","ist","ize","ment","ship","ary","ical","ence","hood"};
    for(int i=0;i<20-1;i++){
        for(int j=i+1;j<20;j++){
            if(strcmp(suf[i],suf[j])>0){
                char *tmp=suf[i];
                suf[i]=suf[j];
                suf[j]=tmp;
            }
        }
    }
 
    int rec[30]={0};
    char chk[100000] = {0};
    while(gets(lne)){
        char *tmp;
        char del[]=" \t\n.,!?;:";
        tmp=strtok(lne,del);
        while(tmp!=NULL){
            strcpy(chk,tmp);
            for(int i=0;i<20;i++){
                char* pos=strstr(chk,suf[i]);
                if(pos!=NULL && (pos-chk+strlen(suf[i]) )==strlen(chk)) rec[i]++;
            }
            tmp=strtok(NULL,del);
        }
    }
 
    for(int i=0;i<20;i++)
        if(rec[i]>0) printf("%s:\nFrequency: %d\n", suf[i],rec[i]);
}
