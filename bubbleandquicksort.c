#include<stdio.h>
void swap(int *a,int *b){
   int temp = *a;
   *a = *b;
   *b = temp;
}
int size;
void print(int *, int);
void bubblesort(int *arr,int size){
   int i,j;
   for(i = 0; i<(size-1); i++ ){
      for(j = 0; j<(size-i)-1; j++){
         if(arr[j]>=arr[j+1]){
            swap(&arr[j],&arr[j+1]);
         }
      }
   }
}
void print(int *arr,int size){
   int i;
   for(i = 0; i<(size); i++ ){
      printf("-%d-",arr[i]);

   }
   printf("\n");
}
void quicksort(int *arr, int min, int max){
   if(min>=max || min<0)
      return;
   
   int pivot;
   pivot = (min+max)/2;
   for(int i=min;i<pivot;i++){
      if(arr[i]>arr[pivot]){
         int num = arr[i];
         for(int j = i;j<pivot && j<max;j++){
            arr[j] = arr[j+1];
         }
         arr[pivot] = num;
         pivot = pivot-1;
         i--;
      }
   }
   for(int i=pivot;i<max;i++){
	   if(arr[i]<arr[pivot]){
         int num = arr[i];
         for(int j = i;j>pivot;j--){
            arr[j] = arr[j-1];
         }
         arr[pivot] = num;
         pivot = pivot+1;
      }
   }
   if(arr[min]!=arr[pivot] && (pivot-min)!=1)
      quicksort(arr,min,pivot);
   if(arr[max]!=arr[pivot] && (pivot-max)!=-1)
      quicksort(arr,pivot,max);

}
int main(){
   
   scanf("%d",&size);
// getting the number of elements to be inserted
   int i;
   int arr[size];
   for(i = 0; i<size; i++){
      printf("Insert Number %d ",i+1);
      scanf("%d",&arr[i]);
   }
//   bubblesort(arr, size);
//   quicksort(arr, 0, size);
   print(arr, size);
   return 0;
}
