#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
  struct node{
    int val;
    struct node *next;
  };
void main(){
    int x;
    char ans;
     struct node *p;
    void puch(struct node *,int *);
    int pop(struct node *);
    void display(struct node *);
    p=(struct node *)malloc(sizeof(struct node));
    p->val=999;
    p->next=NULL;
    do{
        printf("enter the elements you want to push");
        scanf("%d",&x);
        puch(p,&x);
        printf("enter to push more elements again y/n");
        scanf(" %c",&ans);
    }
    while(ans=='y');
    display(p);
    pop(p);
  getchar();
}
void puch(struct node *q,int *a){
    struct node *g;
    g=(struct node *)malloc(sizeof(struct node));
    g->val=*a;
    g->next=q->next;
    q->next=g;
}
int pop(struct node *q){
      int t;
      t=q->val;
      q=q->next;
      free(q);
      return(t);
}
void display(struct node *q){
      q=q->next;
      while(q!=NULL){
        printf("%d",q->val);
        q=q->next;
         printf("\n");
      }
}