#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int **insertToArray(int *rows,int *cols) {
   printf("Nhap so hang va cot:\n");
   scanf("%d %d",rows,cols);
   if (*rows<=0||*cols<=0) {
      printf("So cot hoac hang khong hop le\n");
      return NULL;
   }else if (*rows != *cols) {
      printf("khong co duong cheo chinh,phu\n");
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

int duong_cheo_chinh(int **arr,int *rows) {
   int sum=0;
   for(int i=0;i<*rows;i++) {
      sum+=arr[i][i];
   }
   return sum;
}
int duong_cheo_phu(int **arr,int *rows,int *cols) {
   int sum=0;
   for(int i = 0; i < *rows; i++) {
      sum += arr[i][*cols - 1 - i];
   }
   return sum;
}
void freeArray(int **arr) {
   free(arr[0]);
   free(arr);
}
int main(){
   int rows,cols;
   int **arr;
   int sum1;
   int sum2;
   arr = insertToArray(&rows,&cols);
   if (arr==NULL) {
      return 0;
   }else {
      sum1 = duong_cheo_chinh(arr,&rows);
      sum2 = duong_cheo_phu(arr,&rows,&cols);
      printf("Tổng đường chéo chính = %d\n",sum1);
      printf("Tổng đường chéo phụ = %d",sum2);
   }
   freeArray(arr);
   return 0;
}