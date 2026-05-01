#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node *prev;
    struct node *next;
};
struct node *p;

/*start main function*/

void main()
{
    int x, ps, del, c;
    char choice, rpt;

    p = (struct node *)malloc(sizeof(struct node));
    p->prev = '\0';
    /*function declaration*/
    void creatdll(struct node *);
    void displaydll(struct node *);
    void insertdll_r(struct node *, int, int);
    void insertdll_l(struct node *, int, int);
    int removedll(struct node *, int);
    do
    {
        printf("want to operation on doubly linked list press\n1.creat \n2.display \n3.insert \n4.delete \n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            /*to creat a dll*/
            printf("enter elmnt in dll at the end press 00\n");
            creatdll(p);
            break;
        case 2:
            /*----------------to display the dll-----------*/
            displaydll(p);
            break;
        case 3:
            /*-------------to insert elmnt in dll--------------*/
            printf("\nenter the elemnt and the ps where you want to insert \n");
            scanf("\n%d%d", &x, &ps);
            printf("\nwhere you want to insert left or right enter l/r");
            scanf(" %c", &choice);
            if (choice == 'r' || choice == 'R')
            {
                insertdll_r(p, x, ps);
            }
            else
            {
                insertdll_l(p, x, ps);
            }
            break;
        case 4:
            /*-----------to delete elmt--------------*/
            printf("\nenter whice elemnt you want to delete");
            scanf("\n%d", &del);
            int n;
            n = removedll(p, del);
            printf("\nthe deleted elmnt is %d", n);
            break;
        default:
            printf("invalid enter");
            break;
        }
        /*------------for repeating-----------*/
        printf("\ndo you want to do more operation y\n");
        scanf(" %c", &rpt);
    } while (rpt == 'y' || rpt == 'Y');
    getchar();
}

/*-------function defination------------------*/

// creat function
void creatdll(struct node *q)
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
        creatdll(q->next);
        q->next->prev = q;
    }
}
// display function
void displaydll(struct node *q)
{
    while (q->val != 00)
    {
        printf("%d ", q->val);
        q = q->next;
    }
}
// insert function for right
void insertdll_r(struct node *q, int x, int ps)
{
    struct node *g;
    if (q->val == ps)
    {
        g = (struct node *)malloc(sizeof(struct node));
        g->val = x;
        g->prev = q;
        g->next = q->next;
        q->next->prev = g;
        q->next = g;
    }
    else
    {
        q = q->next;
        insertdll_r(q, x, ps);
    }
}
// ------insert function for left
void insertdll_l(struct node *q, int x, int ps)
{
    struct node *g;
    if (q->val == ps)
    {
        g = (struct node *)malloc(sizeof(struct node));
        g->val = x;
        g->prev = q->prev;
        g->next = q;
        if (q->prev != '\0')
        {
            q->prev->next = g;
            q->prev = g;
        }
        else
        {
            p = g;
        }
    }
    else
    {
        q = q->next;
        insertdll_l(q, x, ps);
    }
}
// remove function
int removedll(struct node *q, int del)
{
    int r;
    struct node *g;
    if (q->val == del)
    {
        g = q;
        r = g->val;
        g->next->prev = q->prev;
        if (q->prev != '\0')
            g->prev->next = q->next;
        else
            p = q->next;
        free(g);
        return r;
    }
    else
    {
        q = q->next;
        removedll(q, del);
    }
}