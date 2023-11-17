// #include <stdio.h>
// #include "fill_array.h"

void fill_array(int *ptr[], int n){
    int now=0;
    while(ptr[0]+now<=ptr[n-1]){
        *(ptr[0]+now)=0;
        now++;
    }
    for(int i=0;i<n;i++) *ptr[i]=i;
    int rc1[20000]={}, rc2[20000]={};
    now=0;
    while(ptr[0]+now<=ptr[n-1]){
        rc1[now]=*(ptr[0]+now);
        if( *(ptr[0]+now)!=0 ) rc2[now]=1;
        now++;
    }
    int rec=rc1[0];
    for(int i=1;i<now;i++){
        if(rc2[i]==1) rec=rc1[i];
        else *(ptr[0]+i)+=rec;
    }
    for(int i=now-1;i>0;i--){
        if(rc2[i]==1) rec=rc1[i];
        else *(ptr[0]+i)+=rec;
    }
}

// int main() {
//     int arr[100] = {};
//     int *ptr[100];
//     int n = 6, m = 0;
//     int A[100] = {0, 5, 6, 9, 3, 12};
//     for (int i = 0; i < n; i++) {
//         ptr[i] = &arr[A[i]];
//         if (A[i] > m)    m = A[i];
//     }
//     fill_array(ptr, n);
//     for (int i = 0; i <= m; i++)
//         printf("%d%c", arr[i], " \n"[i==m]);
//     // printf("%d %d %d", ptr[0], ptr[0]+1, *(ptr[0]+3) );
//     return 0;
// }