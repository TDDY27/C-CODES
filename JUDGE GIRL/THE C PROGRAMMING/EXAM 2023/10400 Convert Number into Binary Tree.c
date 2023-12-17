#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
// #include "numToTree.h"
#define NUMBITS 64
 
struct treenode {
    uint64_t value;
    struct treenode *left;
    struct treenode *right;
};
 
typedef struct treenode TreeNode;
TreeNode *numToTree(uint64_t num, int bitNum){
    if(num==0) return NULL;
    TreeNode *node=(TreeNode*)malloc(sizeof(TreeNode*));
    node->value=num;
    // node->left=NULL, node->right=NULL;
    int l=0,r=0,now=1;
    for(int i=0;i<bitNum/2;i++){
        if(num&1) r+=now;
        num>>=1;
        now*=2;
    }
    node->right=numToTree(r,bitNum/2);
    now=1;
    for(int i=0;i<bitNum/2;i++){
        if(num&1) l+=now;
        num>>=1;
        now*=2;
    }
    node->left=numToTree(l,bitNum/2);
    return node;
}

void preorderTree(TreeNode *root){
    if(root == NULL) return;
    printf("%lu ", root->value);
    preorderTree(root->left);
    preorderTree(root->right);
}
 
void inorderTree(TreeNode *root){
    if(root == NULL) return;
    inorderTree(root->left);
    printf("%lu ", root->value);
    inorderTree(root->right);
}
 
int main(){
    uint64_t num;
    scanf("%lu", &num);
 
    TreeNode *root = (TreeNode*) malloc(sizeof(TreeNode));
    root = numToTree(num, NUMBITS);
 
    preorderTree(root);
    printf("\n");
    inorderTree(root);
    printf("\n");
 
    return 0;
}