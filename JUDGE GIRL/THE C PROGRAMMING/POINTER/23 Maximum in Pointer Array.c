#include "max.h"

int max(int *iptr[], int n){
    int mmax=-2147483648;
    for(int i=0;i<n;i++) mmax= mmax>*iptr[i]? mmax:*iptr[i]; 
    return mmax;
}