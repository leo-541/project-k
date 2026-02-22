// operation on a stack
#include <stdio.h>
int top=-1;
void main(){
   void creatst();
   void push(int [],int);
   void display(int []);
   int pop(int []);
   void stfull(int []);
   void stempty(int []); 
   int num,k,x,stack[20];
   printf("enter the element ");
   scanf("%d",&num);
   push(stack,num);
   char c,r;
   do{
      printf("enter 1.push or 2.pop\n");
      scanf("%d",&k);
      switch (k){
      case 1:
       do{
          stfull(stack);
          printf("enter the element ");
          scanf("%d",&num);
          push(stack,num);
          printf("enter y/n if you insert again\n");
          scanf(" %c",&c);
        }
        while(c=='y');
        printf("the stack is :\n");
        display(stack);
        break;
       case 2:
        stempty(stack);
         x=pop(stack);
           top--;
           printf("the stack is: ");
           stempty(stack);
           break;
            display(stack);
        break;
       }
        printf("\ncan you again want to do push or pop enter y/no");
        scanf(" %c",&r);
    }
    while(r=='y');

} 
// for push
void push(int st[5],int new)
{
     top++;
    st[top]=new;
}
// for display
void display(int st[5]){
    for(int i=top;i>=0;i--){
         printf("%d\n",st[i]);
      }
}
// for pop 
int pop(int st[]){
  return st[top];
//   top--;
}
void stfull(int st[]){
    if(top>=20){
        printf("stack is full");
    }
}
void stempty(int st[]){
    if(top<0){
        printf("stack is empty");
    }
}