#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>

// #include "huffmanTree.h"
#define SYM_MAX_LEN 8
#define SYM_MAX_NUM 100000
 
typedef struct Node {
    char symbol[SYM_MAX_LEN];
    int frequency;
    struct Node *left, *right;
} Node;

int cmp(const void *a,const void *b){
    Node *aa=*(Node**)a, *bb=*(Node**)b;
    if( aa->frequency < bb->frequency ) return -1;
    else if(aa->frequency==bb->frequency && strcmp(aa->symbol,bb->symbol)<0) return -1;
    return 1;
}

Node *bld(Node *nds[],int n){
    if(n==1) return nds[0];
    // for(int i=0;i<n;i++){
    //     printf("%s %d\n",nds[i]->symbol,nds[i]->frequency);
    // }
    Node *tmp=(Node*) malloc(sizeof(Node));
    tmp->frequency=nds[0]->frequency+nds[1]->frequency;
    if(strcmp(nds[0]->symbol,nds[1]->symbol)<0) strcpy(tmp->symbol,nds[0]->symbol);
    else strcpy(tmp->symbol,nds[1]->symbol);
    tmp->right=nds[0];
    tmp->left=nds[1];
    nds[1]=tmp;
    int now=1;
    while(now+1<n){
        if( cmp((&nds[now]),(&nds[now+1])) >0){
            tmp=nds[now];
            nds[now]=nds[now+1], nds[now+1]=tmp;
        }
        nds[now-1]=nds[now];
        now++;
    }
    nds[now-1]=nds[now];
    return bld(nds,n-1); 
}
 
Node* buildHuffmanTree(char* s[SYM_MAX_NUM], int n){
    int now=0;
    char* sym[100005];
    int tms[100005]={};
    for(int i=0;i<n;i++){
        int flag=0;
        for(int j=0;j<now;j++){
            if(strcmp(s[i],sym[j])==0){
                flag=1;
                tms[j]++;
                break;
            }
        }
        if(flag==0){
            sym[now]=(char*)malloc(sizeof(char*)*8);
            strcpy(sym[now],s[i]);
            tms[now]=1;
            now++;
        }
    }
    // printf("now =%d\n",now);
    Node *nds[100005];
    for(int i=0;i<now;i++){
        nds[i]=(Node*)malloc(sizeof(Node));
        strncpy( (nds[i]->symbol), sym[i],8);
        nds[i]->frequency=tms[i];
        nds[i]->left=NULL, nds[i]->right=NULL;
    }
    qsort(nds,now,sizeof(Node*),cmp);
    return bld(nds,now);
}



// void printTree(Node* node){
//     if(node->left == NULL && node->right == NULL){
//         printf("%d %s\n", node->frequency, node->symbol);
//         return;
//     }
//     printf("%d\n", node->frequency);
//     printTree(node->left);
//     printTree(node->right);
// }
 
// int main(){
//     int n;
//     char* s[SYM_MAX_NUM];
//     scanf("%d", &n);
//     for(int i = 0; i < n; i++){
//         s[i] = (char*)malloc(sizeof(char) * SYM_MAX_LEN);
//         scanf("%s", s[i]);
//     }
//     buildHuffmanTree(s, n);
//     Node *root = buildHuffmanTree(s, n);
//     printTree(root);
 
//     for(int i = 0; i < n; i++){
//         free(s[i]);
//     }
// }