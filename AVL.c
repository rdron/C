#include<stdio.h>
#include<stdlib.h>
struct AVL{
   int num;
   struct AVL *left;
   struct AVL *right;
}*root;
int height(struct AVL *node){
//   printf("Calculating height for \n");
   if(node==NULL)
      return 0;
   else{
      int left = height(node->left);
      int right = height(node->right);
      return (left>right)?left+1:right+1; 
   }
}

void balance(struct AVL *node){
   if(node==NULL)
      return;
   balance(node->left);
   balance(node->right);
//   printf("Children ballanced\n"); 
   if(height(node->left)-height(node->right)==2){
      struct AVL *a,*b,*c;
      a = node;
      b = a->left; 
      if(height(b->left)<height(b->right)){
      /*----------------------------------
      case 1 double rotation needed
            /
            \
      ------------------------------------
      */
         c = b->right;        
         struct AVL *d = (struct AVL *)malloc(sizeof(struct AVL));
         d->num = a->num;
         d->right = a->right;
         d->left = c->right;
         a->right = d;
         a->num = c->num;
         b->right = c->left;
         free(c);
  
      }
      else{
      /*---------------------------------
      case 2 single rotation
            /
           /
      ------------------------------------
      */
         c = b->left;
         int temp = a->num;
         a->num = b->num;
         a->right = (struct AVL *)malloc(sizeof(struct AVL));
         a->right->num = temp;
         a->right->right = NULL;
         a->right->left = NULL;
         b->num = c->num;
         b->left =NULL;
         free(c);
      }
   }
   else if(height(node->left)-height(node->right)==-2){
      struct AVL *a,*b,*c;
      a = node;
      b = a->right;
      if(height(b->right)<height(b->left)){
      /*----------------------------------
      case 1 double rotation needed
            \
            /
      ------------------------------------
      */
         c = b->left;
         struct AVL *d = (struct AVL *)malloc(sizeof(struct AVL));
         d->num = a->num;
         d->right = c->left;
         d->left = a->left;
         a->num = c->num;
         a->left = d;
         b->left = c->right;
         free(c);

      }
      else{
      /*---------------------------------
      case 2 single rotation
           \
            \
      ------------------------------------
      */
         c = b->right;
         int temp = a->num;
         a->num = b->num;
         a->left = (struct AVL *)malloc(sizeof(struct AVL));
         a->left->num = temp;
         a->left->right = NULL;
         a->left->left = NULL;
         b->num = c->num;
         b->right = NULL;
         free(c);
      }
      
   }
}
void insertInAvl(int num){
   
   if (root==NULL){
  //    printf("Inserting\n");
      root = (struct AVL *)malloc(sizeof(struct AVL));
      root->num = num;
      root->left = NULL;
      root->right = NULL;
  //    printf("Inserted\n");
   }
   else{
   //   printf("Root not NULL\n");
      struct AVL *temp = root;
      while(1){
         if(num>temp->num && temp->right==NULL){
            temp->right = (struct AVL *)malloc(sizeof(struct AVL));
            temp = temp->right;
            temp->num = num;
            temp->left = NULL;
            temp->right = NULL;  
            break; 
         }
         else if(num>temp->num){
            temp = temp->right;
         }
         else if(temp->left==NULL){
            temp->left = (struct AVL *)malloc(sizeof(struct AVL));
            temp = temp->left;
            temp->num = num;
            temp->left = NULL;
            temp->right = NULL;
            break;
         }
         else{
            temp = temp->left;
         }
      }
   }
  // printf("Going to ballance\n");
   balance(root);
}
void print(struct AVL *node,int exp,int cur){
   if(node==NULL)
     return;
  // printf("%d %d exp cur \n",exp,cur);
   if(exp == cur){
      printf("%d ",node->num);
   }
   else {
      print(node->left,exp,cur+1);
      print(node->right,exp,cur+1);
   }
}

void printbyLevel(){
   int h = height(root);
   int i;
   for(i = 0;i<h;i++){
      print(root,i,0);
      printf("\n");
   }
}

int main(){
   int num;
   int i;
   printf("How many numbers are you going to insert?\n"); 
   scanf("%d", &num);
   int arr[num];
   printf("Insert the numbers\n");
   for(i=0;i<num;i++){
      printf("Enter num :\n");
      scanf("%d", &arr[i]);
      insertInAvl(arr[i]);
      printf("Level order display\n");
      printbyLevel();
   }
  // printf("%d \n",root->num);
   return 0;
}
