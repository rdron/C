#include<stdio.h>
#include<stdlib.h>
struct ll{
   int index;
   struct ll *next;
};

void createlist(struct ll **);

int ifloop(struct ll *);

void printloopstart(struct ll *, int);

int main(){
   struct ll *head=NULL; 
   createlist(&head);
   int flag = ifloop(head);
   if (flag){
      printf("There is a loop \n");
      printloopstart(head,flag);
   }
   return 0;
}

void createlist(struct ll **head){
   if(*head==NULL){
      *head = (struct ll *)malloc(sizeof(struct ll *));
      (*head)->index = 1;
   }
   struct ll *node = *head;
   int i=20;
   for(; i>0; i--){
      node->next = (struct ll *)malloc(sizeof(struct ll *));
      node = node->next;
      node->index = 22 - i;
      
   }
   i = 17;
   struct ll *loopnode = *head;
   for(;i>=0;i--){
      loopnode = loopnode->next;
   }
   node->next = loopnode;
   printf("List Created \n"); 
}

int ifloop(struct ll *head){
   int max = 1000;
   int flag = 0;
   struct ll *slow, *fast;
   slow = fast = head;
   while(max){
      if(slow!=NULL && (fast->next!=NULL && fast->next->next!=NULL)){
         slow = slow->next;
         fast = fast->next->next;
      
         if(slow==fast){
            flag = slow->index;
            break;
         }
         max--;
      }
      else{
         break;
      }
   }
   return flag;
}

void printloopstart(struct ll *head,int flag){
   int arr[20],count=-1;
   struct ll *slow, *fast;
   slow = fast = head;
   while(fast->index!=flag){
      fast=fast->next->next;
   }
   do{
      count++;
      arr[count] = slow->index;  
      slow = slow->next; 
   }while(slow->index!=flag);
   arr[++count] = flag;   
   int x=100;
   while(x){
      fast = fast->next;
      int num = fast->index;
      int j = count;
      for(; j>=0; j--){
         if(num==arr[j]){
            printf("Intersection at %d\n",num);
            return; 
         }
      }
      x--;
   }
}
