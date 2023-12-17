#include <stdio.h>
#include <stdlib.h>
// #include "tree.h"
 


typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;
 
typedef struct Answer {
    int sumDepth;
    int sumData;
} Answer;

Node *newNode (int data, Node *l, Node *r) {
    Node *n = (Node *) malloc(sizeof(Node));
    n->data = data;
    n->left = l;
    n->right = r;
    return n;
}

void tra(Node*rt,Answer *ans,int now){
    ans->sumData+=rt->data;
    ans->sumDepth+=now;
    if(rt->left!=NULL) tra(rt->left,ans,now+1);
    if(rt->right!=NULL) tra(rt->right,ans,now+1);
}

void trace(Node *root, Answer *ans){
    tra(root,ans,1);
}
 
int main () {
    Node *root = newNode(
        10,
            newNode(
                5,
                    NULL,
                    newNode(2, NULL, NULL)               
            ),
            newNode(
                7,
                    newNode(1, NULL, NULL),
                    NULL            
            )
    );
    Answer *ans = (Answer*) malloc(sizeof(Answer));
    ans->sumDepth = 0;
    ans->sumData = 0;
    trace(root, ans);
    printf("%d %d\n", ans->sumDepth, ans->sumData);
    return 0;
}