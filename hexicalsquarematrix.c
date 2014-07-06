#include<stdio.h>
int main(){
  int matrix[5][5]={1,2,3,4,5,6,7,8,9,0,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
  for (int i=0;i<5;i++){
     for(int j=0; j<5;j++)
        printf("%d ",matrix[i][j]);
     printf("\n");
  }
  for (int i=0; i<=8;i++){
     for(int row=0; row<5; row++){
        for(int col=0; col<5; col++){
           if ((row+col)==i)
              printf("%d ",matrix[row][col]);
        }
     }
     printf("\n");
  }
}
