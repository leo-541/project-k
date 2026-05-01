#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node *next;
};
struct queue
{
    struct node *f;
    struct node *r;
};
struct queue *p;
struct node *g;
/*---------start main----------*/
void main()
{
    int x, c, r;
    char ans, ag;
    /*function declaration*/
    void addq(struct queue *, int);
    void display(struct queue *);
    int removeq(struct queue *);
    p = (struct queue *)malloc(sizeof(struct queue));
    p->f = '\0';
    p->r = '\0';
    system("cls");
    do
    {
        printf("enter what you want to do\n 1.add queue\n2.display queue\n3.remove queue\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            /* elmnt insert in queue */
            do
            {
                printf("enter the number to add in  queue\n");
                scanf("%d", &x);
                addq(p, x);
                printf("can you add more ele enter y/n\n");
                scanf(" %c", &ans);
            } while (ans == 'y' || ans == 'Y');
            break;
        case 2:
            /*display the queue*/
            printf("the queue is\n");
            display(p);
            break;
        case 3:
            /*delete elmt from queue*/
            r = removeq(p);
            if (r == 999)
                printf("nothing to delete\n");
            else
                printf("the deleted elments is %d", r);
            break;
        default:
            printf("invalid enter");
            break;
        }

        printf("\ncan you do again more operation y/n\n");
        scanf(" %c", &ag);
    } while (ag == 'y' || ag == 'Y');
    getchar();
}
// function of add q
void addq(struct queue *q, int n)
{
    g = (struct node *)malloc(sizeof(struct node));
    g->val = n;
    g->next = '\0';
    if (q->r == '\0')
    {
        q->f = g;
        q->r = g;
        return;
    }
    else
    {
        q->r->next = g;
        q->r = g;
    }
}
// for display
void display(struct queue *q)
{
    if (q->f == '\0')
    {
        printf(" queue is empty");
        return;
    }
    else
    {
        g = (struct node *)malloc(sizeof(struct node));
        g = q->f;
        while (g != '\0')
        {
            printf("%d ", g->val);
            g = g->next;
        }
    }
}
// for remove
int removeq(struct queue *q)
{
    int x;
    if (q->f == '\0')
    {
        printf("queue is empty\n");
        return 999;
    }
    else
    {
        g = (struct node *)malloc(sizeof(struct node));
        g = q->f;
        x = g->val;
        q->f = g->next;
        free(g);
        return x;
    }
}
