// #include <stdio.h>
// #include <assert.h>
#include "snake.h"
 
void snake(const int *ptr_array[100][100], int m){
    const int **one[10005];
    int now=0;
    for(int i=0;i<m;i++){
        if(i%2==0){
            for(int j=0;j<m;j++) one[now]=&ptr_array[i][j], now++;
        }else{
            for(int j=m-1;j>=0;j--) one[now]=&ptr_array[i][j], now++;
        }
    }
    for(int i=0;i<now-1;i++){
        for(int j=i;j<now;j++){
            if(**one[i]>**one[j]){
                const int *tmp=*one[i];
                *one[i]=*one[j];
                *one[j]=tmp;
            }
        }
    }
}
 
// int main()
// {
//   int array[100][100], check[100][100];
//   const int *ptr_array[100][100];
//   int i, j, m;
 
//   scanf("%d", &m);
//   for (i = 0; i < m; i++)
//     for (j = 0; j < m; j++) {
//       ptr_array[i][j] = &(array[i][j]);
//       scanf("%d", &(array[i][j]));
//       check[i][j] = array[i][j];
//     }
 
//   snake(ptr_array, m);
 
//   for (i = 0; i < m; i++) {
//     for (j = 0; j < m; j++) {
//       assert(check[i][j] == array[i][j]);
//       assert((ptr_array[i][j] >= &array[0][0]) && (ptr_array[i][j] <= &array[99][99]));
//       printf("%d ", *(ptr_array[i][j]));
//     }
//     printf("\n");
//   }
 
//   return 0;
// }