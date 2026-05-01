#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
// struct declaration
struct node
{
    int value;
    struct node *next;
};
int r;
// function declaration
void creat(struct node *);
void display(struct node *);
void insert(struct node *, int, int);
int delt(struct node *, int);
struct node *p;
void main()
{
    p = (struct node *)malloc(sizeof(struct node));
    // for creat
    printf("enter the elements in ll at end press 00\n");
    creat(p);
    display(p);
    int num, pos;
    // for choise
    printf("\nchoise whice you want to do with this linked list\n1.insert\n2.deletion.");
    int choise;
    scanf("%d", &choise);
    switch (choise)
    {

    case 1:
        printf("\nenter the elements and enter the elements after whice you insert a new elements");
        scanf("%d%d", &num, &pos);
        insert(p, num, pos);
        printf("the updated ll is");
        display(p);
        break;
    default:
        printf("\nenter the elements after whice you want to be delete");
        int dnum;
        scanf("%d", &dnum);
        r = delt(p, dnum);
        printf("the updated ll is");
        display(p);
        break;
    }
}
// function defination for creat
void creat(struct node *q)
{
    scanf("%d", &q->value);
    if (q->value == 00)
    {
        q->next = '\0';
        return;
    }
    else
    {
        q->next = (struct node *)malloc(sizeof(struct node));
        creat(q->next);
    }
}
// for desplay
void display(struct node *q)
{
    while (q->value != 00)
    {
        printf("%d ", q->value);
        q = q->next;
    }
}
// for insert
void insert(struct node *q, int x1, int ps)
{
    struct node *g;
    if (q->value == ps)
    {
        g = (struct node *)malloc(sizeof(struct node));
        g->value = x1;
        g->next = q->next;
        q->next = g;
    }
    else
    {
        insert(q->next, x1, ps);
    }
}
// for deletion
int delt(struct node *q, int ps)
{
    struct node *g;
    g = (struct node *)malloc(sizeof(struct node));
    if (q->value == ps)
    {
        g = q->next;
        r = g->value;
        q->next= g->next;
        return r;
        free(g);
    }
    else
    {
        r = delt(q->next, ps);
        return r;
    }
}