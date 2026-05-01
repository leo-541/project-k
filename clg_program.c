#include <stdio.h>
#include <stdlib.h>
int i, j, n, temp, low, high;
void quicks(int[], int, int);
int partition(int[], int, int);
void main()
{
    int a[20];
    printf("enter how many elemenys you want to insert");
    scanf("%d", &n);
    low = 0;
    high = n - 1;
    printf("enter elements");
    /*input*/
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    // call function
    quicks(a, low, high);

    printf("the sorted array is");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    getchar();
}
// function
void quicks(int a[], int low, int high)
{
    int x;
    if (low < high)
    {

        x = partition(a, low, high);
        quicks(a, low, x - 1);
        quicks(a, x + 1, high);
    }
}
int partition(int a[], int low, int high)
{
    int left = low, right = high;
    int key = a[low];
    while (left < right)
    {
        while (a[right] > key)
        {
            right--;
        }
        while (a[left] < key)
        {
            left++;
        }
        if (left < right)
        {
            temp = a[left];
            a[left] = a[right];
            a[right] = temp;
        }
    }
    return right;
}