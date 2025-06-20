#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int *insertToArray(int *arr, int *size, int value) {
   (*size)++;
   arr = (int*)realloc(arr, (*size)*sizeof(int));
   arr[*size-1] = value;
   return arr;
}
int main(){
   int n;
   int *arr = NULL;
   int size = 0;

   printf("Nhap so luong phan tu:");
   scanf("%d",&n);
   if (n<0) {
      printf("Số lượng phần tử không được âm");
   }else if (n == 0) {
      printf("Số lượng phần tử phải lớn hơn 0");
   }else {
      for (int i = 0; i < n; i++) {
         int value;
         printf("Nhap phan tu %d:",i+1);
         scanf("%d", &value);
         arr = insertToArray(arr, &size, value);
      }
      int max=arr[0];
      for (int i = 1; i < size; i++) {
         if (max<arr[i]) {
            max=arr[i];
         }
      }
      printf("%d",max);
   }
   free(arr);
   return 0;
}