#include<stdio.h>
#include<stdlib.h>

struct list{
   char c;
   int count;
   struct list *next;
   struct list *dict;
};

char *stringprint;

int limit = 0;

int permutes = 0;

struct list* copylist(struct list *List){
   struct list *head = NULL,*temp;
   struct list*list = List;
   while(list){
      if(head==NULL){
         head = (struct list *)malloc(sizeof(struct list));
         head->c = list->c;
         head->count = list->count;
         head->next = NULL;
         head->dict = NULL;
         temp = head;
      }
      else{
            temp->next = (struct list *)malloc(sizeof(struct list));
            temp = temp->next;
            temp->c = list->c;
            temp->count = list->count ;
            temp->next = NULL;
            temp->dict = NULL;
      }
      list = list->next;
   }
   return head;
}

struct list* createlist(char *s){
   struct list *head=NULL;
   while(*s){
      if(head==NULL){
         head = (struct list *)malloc(sizeof(struct list));
         head->c = *s;
         head->count = 1;
         head->next = NULL;
         head->dict = NULL;
      }
      else{
         struct list *temp = head;
         int flag=0;
         while(temp!=NULL){
            if((temp->c)==*s){
               temp->count++;
               flag=1;
               break;
            }
            temp=temp->next;
         }
         if(flag==0){
            struct list *temp = head;
            while(temp->next!=NULL)
               temp=temp->next;
            temp->next = (struct list *)malloc(sizeof(struct list));
            temp = temp->next;
            temp->c = *s;
            temp->count = 1;
            temp->next = NULL;
            temp->dict = NULL;
         }
      }
      s++;   
   }
   return head;
}

void createdict(struct list *,int);

void printdict(struct list*,int);

int main(){
   char string[20];
   printf("Enter the String to permute\n");
   scanf("%s",string);
   char *s = string;
   while (*s!='\0'){
      limit++;
      s++;
   }
   stringprint = (char *)malloc(limit);
   stringprint[limit]='\0';
   struct list *List = createlist(string);
   createdict(List,0);
   printdict(List,0);
   printf("Total Permutes = %d\n",permutes);
   return 0;
}
void createdict(struct list *l,int i){
   struct list *node = l;
   while(node!=NULL){
      if(node->count>0){
//         printf("%c\n",node->c);
         struct list *newlist = copylist(l);
         struct list *temp = newlist;
         while(temp!=NULL){
            if(temp->c==node->c){
               temp->count--;
            }
            temp=temp->next;
         }
         node->dict = newlist;
         createdict(node->dict,i++);
     
      }
      node=node->next;
   }
}
void printdict(struct list *l,int i){
   struct list *node = l;
   if(i==limit) {
      printf("%s\n",stringprint);
      permutes++;
   }
   while(node!=NULL){
      if(node->count>0){
         stringprint[i] = node->c;
         printdict(node->dict,i+1);
      }
      node=node->next;
   }

}
