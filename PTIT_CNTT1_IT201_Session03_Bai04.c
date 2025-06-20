#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int **insertToArray(int *rows,int *cols) {
   printf("Nhap so hang va cot:\n");
   scanf("%d %d",rows,cols);
   if (*rows<=0||*cols<=0) {
      printf("Số cột hoac hang không hợp lệ\n");
      return NULL;
   }else {
      int **arr = (int**)malloc((*rows)*sizeof(int*));
      for(int i=0;i<*rows;i++) {
         arr[i] = (int*)malloc((*cols)*sizeof(int));
      }
      for(int i=0;i<*rows;i++) {
         for(int j=0;j<*cols;j++) {
            scanf("%d",&arr[i][j]);
         }
      }
      return arr;
   }
}
int find_max(int **arr,int rows,int cols) {
   int max = arr[0][0];
   for(int i=0;i<rows;i++) {
      for(int j=0;j<cols;j++) {
         if(arr[i][j]>max) {
            max=arr[i][j];
         }
      }
   }
   return max;
}
int find_min(int **arr,int rows,int cols) {
   int min = arr[0][0];
   for(int i=0;i<rows;i++) {
      for(int j=0;j<cols;j++) {
         if(arr[i][j]<min) {
            min=arr[i][j];
         }
      }
   }
   return min;
}
void freeArray(int **arr) {
   free(arr[0]);
   free(arr);
}
int main(){
   int rows,cols;
   int **arr;
   int max;
   int min;
   arr = insertToArray(&rows,&cols);
   if (arr==NULL) {
      return 0;
   }else {
      max = find_max(arr,rows,cols);
      min = find_min(arr,rows,cols);
      printf("max = %d\n",max);
      printf("min = %d",min);
   }
   freeArray(arr);
   return 0;
}