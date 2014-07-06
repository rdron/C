#include<stdio.h>
#include<stdlib.h>
struct node {
   int num;
   struct node* left;
   struct node* right;

}*head;
struct queue {
   struct node *ele;
   struct queue *next;
}*front,*rear;

void buildHeap(int list[],struct node **,int,int );

void printHeap(struct node *);

void heapify(struct node *);

void heapSort();

int main() {
   int size;
   scanf("%d",&size);
   int arr[size];
   int i;
   
   for(i=0;i<size;i++) {
      scanf("%d",&arr[i]);
   }

   buildHeap(arr,&head,1,size);
   printHeap(head);
   heapSort();   
   return 0;
}
void buildHeap(int list[] ,struct node ** data_addr, int i,int size) {
   if(i-1<size) {
      *data_addr=(struct node*)malloc(sizeof(struct node));
      struct node *data=*data_addr;
 
      data->num=list[i-1];
     
      if(i<=size/2) {
         buildHeap(list,&(data->left),2*i,size);
         buildHeap(list,&(data->right),2*i+1,size);
      }
      heapify(data);
      //printHeap(data);
     // printf("\n");
   }
   
}
void printHeap(struct node* data) {
   if(data!=NULL && data->num==-999){ data=NULL;
   free(data);}
   else if(data!=NULL) {
      printf("%d ",data->num);
      printHeap(data->left);
      printHeap(data->right);
   }

}
void heapify(struct node *a) {
   struct node *left=a->left;
   struct node *right=a->right;
   struct node *largest;
   if(left!=NULL && a->num < left->num ) {
      largest=left;
   } 
   else
   largest=a;
   if(right!=NULL && largest->num < right->num) {
      largest=right;
   }
   if(largest!=a) {
      int temp=largest->num;
      largest->num=a->num;
      a->num=temp;
      heapify(largest);
   }
  
}
void heapSort() {
   if(head!=NULL && head->num!=-999) {
      struct node *temp;
      front=(struct queue *)malloc(sizeof(struct queue));
      rear=front;
      rear->ele=head;
      rear->next=NULL;      
      while(front!=NULL) {
         temp=front->ele;
         if (temp->left!=NULL) {
           struct queue *q= (struct queue *)malloc(sizeof(struct queue));
           q->ele=temp->left;
           q->next=NULL;
           rear->next=q;
           rear=rear->next;
         }  
         
         if (temp->right!=NULL) {
           struct queue *q= (struct queue *)malloc(sizeof(struct queue));
           q->ele=temp->right;
           q->next=NULL;
           rear->next=q;
           rear=rear->next;
         }
         
         front=front->next;  
      }
      printf("\n%d\n ",head->num);
      head->num=temp->num;      
      temp->num=-999;  
      heapify(head);
//    printHeap(head);
  //  printf("\n");
      heapSort();
   }

}
