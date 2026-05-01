#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node *next;
};
/*----for last ele----*/
struct l_node
{
    int val;
    struct node *next;
    char last;
};
struct node *p;
struct l_node *g;
// main function----------
void main()
{
    p = (struct node *)malloc(sizeof(struct node));
    void creat(struct node *);
    void display(struct node *);
    system("cls");
    printf("enter ele in circuler ll and at the end give dot (.)\n");
    creat(p);
    printf("to display the list");
    display(p);
}
// --------function definition--------
void creat(struct node *q)
{
    char l, lst;
    scanf("%d", &q->val);
    scanf("%c", &l);
    if (l == '.')
    {
        q->next = '\0';
        
    }
    else
    {
        q->next = (struct node *)malloc(sizeof(struct node));
        creat(q->next);
    }
    while (q->next == '\0')
    {
        q->next = p;
    }
}

// for display
void display(struct node *q)
{
    if (q->next == p)
    {
        return;
    }
    else
    {
        printf("%d ", q->val);
        display(q->next);
    }
    
}