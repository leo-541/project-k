// #include<stdio.h>
// #include<conio.h>
// // #include <math.h>
// void main()
// {
// //     char sk[]= "akshay+surabhi";
// //    printf("length = %lu\n",strlen(sk));-string header file ka strlen() function e.g
//  /* char sk[]= "surabhi";
//    system("cls");
//    char ak[20];
//    strcpy(ak,sk);
//    printf("strcpy: %s\n", ak);
//    char ak2[30];
//    strncpy(ak2,sk,4);................mane copy koriba pari kintu ata ata word hisape 
//    ak2[4]='\0';...-- ate blg blg no dili 0 r thait blg emoji ahe
//    printf("strncpy: %s\n",ak2);
//    */
//   // loop
//   // assignment no 8
  
// }
#include<stdio.h>
#define size 20
void Quicksort(int[], int, int); 
int partition(int[], int, int);

int main() {
    int a[size], n, i, l, u;
    printf("Enter no. of elements you want to enter in the array:");
    scanf("%d", &n);
    printf("Enter the elements in the array:");
    for( i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    l = 0;
    u = n-1;
     Quicksort(a, l, u);
    printf("The sorted array is:\n");
    for( i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    
    return 0;
}

void Quicksort(int a[], int l, int u){
    int x;
    if(l < u){
        x = partition(a, l, u);
        Quicksort(a, l, x-1);
        Quicksort(a, x+1, u);
    }
}

int partition(int a[],int l, int u){
    int key = a[l];
    int left = l;
    int right = u;
    int temp;
    while(left<right){
        while(left<right && a[right]>key){
            right--;
        }
        while(left<right && a[left] < key){
            left++;
        }
        if(left < right){   
            temp = a[left];
            a[left] = a[right];
            a[right] = temp;  
        }
    }
    return right;
}