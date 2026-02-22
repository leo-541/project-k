// #include <stdio.h>
// #include <conio.h>
// void main(){
//   int a[10],i,n,c;
//   int p;
//   printf("enter the size of an array");
//   scanf("%d",&n);
//   // for input the array
//   printf("enter the elements");
//   for(i=0;i<n;i++){
//       scanf("%d",&a[i]);
//   }
//   // for display the array
//   printf("[");
//    for(i=0;i<n;i++){
//     printf(" %d ",a[i]);
//    }
//    printf(" ]");

//   //  for user choice 

//  printf("\nwhat you want to do in this array \n 1.insert elements\n 2.delete elements ");
//  int choice;
//  scanf("%d",&choice);
//  int x;
//  switch (choice)
//  {
//  case 1:
//    printf("\nenter the elements for insert in your array");
//    scanf("%d",&x);
//    printf("\nenter the number of position where you want to insert that number");
//    scanf("%d",&p);
//    int upd1[10];
//    for(i=0;i<n+1;i++){
//     if(i<p-1){
//         upd1[i]=a[i];
//     }
//     else if(i==p-1){
//         upd1[i]=x;
//     }
//     else{
//         upd1[i]=a[i-1];
//     }
//    }
//    printf("the updated array is ");
//    printf("[ ");
//     for(i=0;i<n+1;i++){
//         printf("%d ",upd1[i]);
//     }
//     printf("]");
//   break;
//   case 2:
//      printf("enter the position of that  elements whice you want to delete");
//      int d;
//      scanf("%d",&d);
//      int upd2[10];
//      for(i=0;i<n;i++){
//         if(i<d){
//             upd2[i]=a[i];
//         }   
//         else if(i==d) {
//            upd2[i]=a[i+1];
//         }
//         else{
//             upd2[i]=a[i+1];
//         }
//     }
//      printf("the updated array is");
//      printf("[ ");
//      for(i=0;i<n-1;i++){
//         printf("%d ",upd2[i]);
//     }
//     printf("]");
     
//   break;
 
//  default:
//      printf("not result");
      
//   break;
//  }
// }
#include <stdio.h>
#include <stdlib.h>
// struct declaration
struct node{
    int value;
    struct node *next;
};
// function declaration
void creat(struct node *q);
void display(struct node *q);
void insert(struct node *q,int x1,int ps);
int del(struct node *q,int x2);
void main(){
struct node *p;  
p=(struct node *)malloc(sizeof(struct node));
// for creat 
printf("enter the elements in ll at end press 00\n");
creat(p);
display(p);
int num,pos;
// for choise 
printf("\nchoise whice you want to do with this linked list\n1.insert\n2.deletion.");
int choise;
scanf("%d",&choise);
switch(choise){

   case 1:printf("\nenter the elements and enter the elements after whice you insert a new elements");
       scanf("%d%d",&num,&pos);
       insert(p,num,pos);
       printf("the updated ll is");
       display(p);
       break;      
   default:printf("\nenter the elements after whice the next elements will be delete");
      int dnum;
      scanf("%d",&dnum);
      int delete=del(p,dnum);
      printf("the deleted number is %d",delete);
      printf("\nthe updated ll is");
      display(p);
      break;
    
   }
}
// function defination for creat
void creat(struct node *q){ 
     scanf("%d",&q->value);
    if(q->value==00){
        q->next='\0';
        return;
    }
    else{
        q->next=(struct node *)malloc(sizeof(struct node));
        creat(q->next);
    }
}
// for desplay
void display(struct node *q){
    while(q->value!=00){
        printf("%d ",q->value);
        q=q->next;
    }
}
// for insert
void insert(struct node *q,int x1,int ps){
     struct node *g;
     if(q->value==ps){
        g=(struct node *)malloc(sizeof(struct node));
        g->value=x1;
        g->next=q->next;
        q->next=g;
     }
     else{
        insert(q->next,x1,ps);
     }

}
// for deletion
int del(struct node *q,int x2){
    struct node *g;
    int x1;
    if(q->value==x2){
      g=q->next;
      x1=g->value;
      q->next=g->next;
      free(g);
     }
    else{
     x1=del(q->next,x2);
    }
    return(x1);
}