#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mergeString.h"

void mergeString(char** P, char L[26], char* A){
	int cmp[26];
	for(int i=0;i<26;i++) cmp[ (int)(L[i]-'a') ]=i;
	int flag=0;
	int now=0;
	int ln=0;
	while( P[ln]!=NULL) ln++;
	while(flag<ln){
		int max=30, pos;
		for(int i=0;i<ln;i++){
			if(*P[i]=='\0') continue;
			if( cmp[ (int)(*P[i]-'a') ]<max){
				max=cmp[ (int)(*P[i]-'a') ];
				pos=i;
			}
		}
		*(A+now)=L[max];
		P[pos]=P[pos]+1;
		if(*P[pos]=='\0') flag++;
		now++;
	}
}

/*
int main(){
    int n;
    scanf("%d", &n);
    char* P[n + 1];
    char* freeP[n];
    int lengthA = 0;
    for(int i = 0; i < n; i++){
        int m;
        scanf("%d", &m);
        P[i] = (char*)malloc((m + 1) * sizeof(char));
        scanf("%s", P[i]);
        // We may change the pointers in P in mergeString,
        // so we make a copy of P to free them in the last step.
        freeP[i] = P[i];
        lengthA += m;
    }
    P[n] = NULL;
    char L[26], buffer[30];
    scanf("%s", buffer);
    strncpy(L, buffer, 26);
 
    char* A = (char *)malloc((lengthA + 1) * sizeof(char));
    mergeString(P, L, A);
    A[lengthA] = '\0';
    printf("%s\n", A);
 
    // free the memory
    for(int i = 0; i < n; i++){
        free(freeP[i]);
    }
    free(A);
}*/
