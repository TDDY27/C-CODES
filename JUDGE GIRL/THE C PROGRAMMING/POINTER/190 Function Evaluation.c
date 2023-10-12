// #include <stdio.h>
#include "evaluate_f.h"

int evaluate_f(int *iptr[], int n, int *index){
    int mmax=-2147483648;
    for(int i=0;i<n;i++){
        int tx,ty;
        tx=*(iptr[i]+0), ty=*(iptr[i]+1);
        if(4*tx-6*ty>mmax) mmax=4*tx-6*ty, *index=i;
    }
    return mmax;
}
 
// int main(){
//   int a[] = { 9, 7 };
//   int b[] = { 3, 2 };
//   int c[] = { 3, 2 };
//   int d[] = { 9, 7 };
//   int *iptr[] = { a, b, c, d };
//   int max, index;
//   max = evaluate_f(iptr, 4, &index);
//   printf("%d %d\n", max, index);
// }