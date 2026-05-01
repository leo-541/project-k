#include <stdio.h>
int a[30], i, j;
void main()
{
    int n, c, pos;
    // char again;
    printf("Enter the size of an array:");
    scanf("%d", &n);
    // for input the array
    printf("Enter the elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    // for display the array
    printf("[");
    for (i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
    printf(" ]");
  
        //  for user choice
        printf("\nWhat you want to do in this array \n 1.insert elements\n 2.delete elements\n3.reversing\n4.marge: ");
        int choice;
        scanf("%d", &choice);
        int x;
        switch (choice)
        {

            // --------------insert elt-----------
        case 1:
            printf("\nEnter the elements for insert in your array:");
            scanf("%d", &x);
            printf("\nEnter the number of position where you want to insert that number:");
            scanf("%d", &pos);
            int upd1[10];
            for (i = 0; i < n+1; i++)
            {
                if (i < pos - 1)
                {
                    upd1[i] = a[i];
                }
                else if (i == pos - 1)// 2 8 4 9 3 7--6 at 4
                {
                    upd1[i] = x;
                }
                else
                {
                    upd1[i] = a[i - 1];
                }
            }
            printf("The updated array is: ");
            printf("[ ");
            for (i = 0; i < n + 1; i++)
            {
                // a[i] = upd1[i];
                printf("%d ", upd1[i]);
            }
            printf("]");

            break;

            /*-------- delete the elemt---------------*/
        case 2:
            printf("Enter the position of that  elements whice you want to delete:");
            int d;
            scanf("%d", &d);
            int upd2[10];
            for (i = 0; i < n; i++)
            {
                if (i < d - 1)
                {
                    upd2[i] = a[i];
                }
                else if (i == d - 1)
                {
                    upd2[i] = a[i + 1];
                }
                else
                {
                    upd2[i] = a[i + 1];
                }
            }
            printf("The updated array is:");
            printf("[ ");
            for (i = 0; i < n - 1; i++)
            {
                // a[i] = upd2[i];
                printf("%d ", upd2[i]);
            }
            printf("]");

            break;

            // -----------------reversing the array--------
        case 3:
            printf("The reverse array is:\n");
            for (j = n - 1; j >= 0; j--)
            {
                printf("%d\t", a[j]);
            }
            break;

        //------------------ marging two array--------
        case 4:
            // taking input of 2nd array
            int b[20], n2;
            printf("Enter the size of the 2nd array:\n");
            scanf("%d", &n2);
            printf("Enter elt:");
            for (j = 0; j < n2; j++)
            {
                scanf("%d", &b[j]);
            }
            // main logic part
            for (i = n, j = 0; i < n + n2; i++, j++)
            {
                a[i] = b[j];
            }
            // display the updated ARR
            printf("Updated array is:");
            for (i = 0; i < n + n2; i++)
            {
                printf("%d  ", a[i]);
            }

            break;

        default:
            printf("not result");

            break;
        }
}
