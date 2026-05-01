#include <stdio.h>
#include <stdlib.h>
struct node
{
  int val;
  struct node *next;
};
struct node *p;
int main()
{
  int x;
  char ans;
  void push(struct node *, int);
  int pop(struct node *);
  void display(struct node *);
  p = (struct node *)malloc(sizeof(struct node));
  p->val = 999;
  p->next = '\0';
  system("cls");
  do
  {
    printf("enter the elements you want to push");
    scanf("%d", &x);
    push(p, x);
    printf("enter to push more elements again y/n");
    scanf(" %c", &ans);
  } while (ans == 'y' || ans == 'Y');
  display(p);
  printf("the poping of stack");
  // pop(p);
  display(p); // problem here
  getchar();
  return 0;
}
void push(struct node *q, int a)
{
  struct node *g;
  g = (struct node *)malloc(sizeof(struct node));
  g->val = a;
  g->next = q;
  // q->next='\0';
  p=g;
}
int pop(struct node *q)
{
  int t;
  t = q->val;
  q = q->next;
  free(q);
  return (t);
}
void display(struct node *q)
{
  if(q->next!='\0'){
  printf("%d ",q->val);
  }
 else{
  display(p->next);
 }
}
