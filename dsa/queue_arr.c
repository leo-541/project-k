// queue using array
#include <stdio.h>
#include <stdlib.h>
#define size 20
int q[size];
int f = 0, r = -1;
void main()
{
    int x, d, choice, n;

    /*function declaration*/

    void addq(int[], int);
    int removeq(int[]);
    void displayq(int[]);
    system("cls");
    do
    {
        printf("\n     menu     ");
        printf("\n1.add\n2.display\n3.remove\n4.exit\n");
        printf("enter your chopice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            /*insert elmt*/
            printf("enter the elements");
            scanf("%d", &x);
            addq(q, x);
            break;
        case 2:
            /*display queue*/
            displayq(q);
            break;
        case 3:
            /*delete queue */
            d = removeq(q);
            printf("deleted elements is %d", d);
            f++;
            break;
        default:
            printf("invalid enter");
            break;
        }
    } while (choice != 4);
}
/*for add function*/
void addq(int q[], int x1)
{
    r++;
    if (r >= size)
        printf("\n queue is overflow");
    else
        q[r] = x1;
}
/*for display function*/
void displayq(int q[])
{
    int i;
    if (f > r)
        printf("\nqueue is empty");
    else
    {
        printf("\nelements of queue are:\n");
        for (i = f; i <= r; i++)
            printf("%d\n", q[i]);
    }
}
/*for remove function*/
int removeq(int q[])
{
    if (f > r)
    {
        printf("\nqueue is empty");
    }
    else
    {
        return q[f];
    }
}