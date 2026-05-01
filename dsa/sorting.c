#include<stdio.h>
#include<stdlib.h>
#define size 20
int i,j,temp,low,high;
void quicks(int a[],int low,int high);
int partition(int a[],int low,int high);
void main(){
    int a[size],n,choice,key;
    //function declaration
    void bubbles(int [],int );
    void insertions(int [],int );
    void selections(int [],int );
    system("cls");
    printf("enter the size of the array");
    scanf("%d",&n);
    printf("enter elements");
    /*input*/
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
       }
    low=0;
    high=n-1;
        /*------for display array-----*/
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    /*----------for choise-----------*/
    printf("\n1.bubble sort\n2.insertion sort\n3.selection sort\n4.quick sort\n");
    printf("enter whice method you want to apply for sorting \n");
    scanf("%d",&choice);
    switch(choice){
       case 1:/*-------for bubble------*/
           bubbles(a, n);
            break;
       case 2:
      /*----------for insertion sort-------*/
        insertions(a,n);
            break;
       case 3:/*----------for selection sort-------*/
           selections(a,n);
            break;
       case 4:/*----------for quick sort-------*/
            quicks(a,low,high);
            break;
       default:
              printf("\ninvalid enter");
              break;
       }

        /*-------for display------------*/
       printf("the sorted array is\n");
       for(i=0;i<n;i++)
       printf("%d ",a[i]);
    getchar();
}
/*------------for bubble--------------*/
void bubbles(int a[],int n){
 for(i=0;i<n-1;i++){
             for(j=0;j<n-i-1;j++){
                 if(a[j]>a[j+1]){
                     temp=a[j];
                     a[j]=a[j+1];
                     a[j+1]=temp;     
                 }
             }
         }
}

/*-----------for insertion sort---------*/
void insertions(int a[],int n){
     for(i=1;i<n;i++){
          int key=a[i];
            j=i-1;
            while(j>=0 && key<a[j]){
                a[j+1]=a[j];
                j--;
            }
            a[j+1]=key;
         }
}
/*-------for selection sort---------*/
void selections(int a[],int n){
    for(i=0;i<n;i++){
           int m=i;
            for ( j = i+1; j < n; j++)
            {
              if(a[j]<a[m])
                 m=j;
            }
            temp=a[i];
            a[i]=a[m];
            a[m]=temp; 
         }
}
/*---------------------for quick sort--------------------*/
void quicks(int a[],int low,int high){
    int x;
    if(low<high){
        x=partition(a,low,high);
        quicks(a,low,x-1);
        quicks(a,x+1,high);
    }
}
/*---------------for partition---------------*/
int partition(int a[],int low,int high){
    int left=low,right=high;
     int key=a[low];
    while(left < right){
        while(a[right] > key){
            right--;
        }
        while(a[left] < key){
            left++;
        }
        if(left < right){
             temp=a[left];
            a[left]=a[right];
            a[right]=temp;
        }
    }
    return right;
}