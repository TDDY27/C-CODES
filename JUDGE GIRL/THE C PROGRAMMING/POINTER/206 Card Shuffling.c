#include "card.h"
#include <string.h>
#include <stdio.h>

void shuffle(int *deck[]){
    int *ji[10005]; // ji~~lu~~
    int rec=0;
    while(1){
        if(deck[rec]==NULL) break;
        ji[rec]=deck[rec];
        rec++;
    }
    int now=0, jmp=0;
    while(jmp<rec){
        deck[jmp]=ji[now];
        jmp+=2, now++;
    }
    jmp=1;
    while(jmp<rec){
        deck[jmp]=ji[now];
        jmp+=2,now++;
    }
}

void print(int *deck[]){
    int rec=0;
    while(1){
        if(deck[rec]==NULL) break;
        printf("%d ", *deck[rec]);
        rec++;
    }
}

// int main()
// {
//   int card[10000];
//   int *deck[10000];
//   int index = 0;
 
//   while (scanf("%d", &(card[index])) != EOF) {
//     deck[index] = &(card[index]);
//     index++;
//   }
//   deck[index] = NULL;
//   shuffle(deck);
//   print(deck); 
//   return 0;
// }