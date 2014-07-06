#include<stdio.h>
int length(char *s){
   int len=0;
   while(*s){
      s++;
      len++;
   }
   return len;
}
void swap(char *s,int len){
   for(int i = 0; i<len/2; i++ ){
   char temp = *(s+i);
   *(s+i) = *(s + len-1-i);
   *(s+ len-1-i) = temp;
   }
   printf("%s\n",s);
}
int main(){
   char string[]="Hell World";
   int len = length(string);
   char stringRev[len];
   stringRev[len]='\0';
   swap(string,len);
   for(int i = 0;len>0;len--,i++){
      stringRev[i]=string[len-1];
   }
   printf("%s\n",stringRev);
   return 0;
}
