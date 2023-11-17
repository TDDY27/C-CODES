#include "max.h"

int max(int array[5][5]){
    int mmax=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            mmax= mmax>array[i][j]? mmax:array[i][j];
        }
    }
    return mmax;
}
