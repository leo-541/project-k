#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node *next;
};
struct node *p;
int count = -1, pos, flag = 0;
void main()
{
    p = (struct node *)malloc(sizeof(struct node));
    void create(struct node *);
    void display(struct node *);
    int search(struct node *, int);
    printf("enter the elmt in ll at the end press 00\n");
    create(p);
    display(p);
    printf("\nenter whice elmt is want to search");
    int x;
    scanf("%d", &x);
    pos = search(p, x);
    printf("\nthe searched elmt is found at %d position", pos+1);
}
void create(struct node *q)
{
    scanf("%d", &q->val);
    if (q->val == 00)
    {
        q->next = '\0';
        return;
    }
    else
    {
        q->next = (struct node *)malloc(sizeof(struct node));
        create(q->next);
    }
}
// for desplay
void display(struct node *q)
{
    while (q->val != 00)
    {
        printf("[%d]->", q->val);
        q = q->next;
    }
}
// search
int search(struct node *q, int x)
{
   
    while(q->val != 00)
    {
        count=count+1;
       while(q->val==x){
        flag=1;
        // return count;
       }
       q=q->next;
        
    }

    
        if(flag==1){
            flag=0;
            return count;
        }
        else{
            return -999;
        }
    
}
