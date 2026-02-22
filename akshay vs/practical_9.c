#include<stdio.h>
#include<stdlib.h>
void main(){
    int n,x,i,a[20];
    int r=1;
    // void notfound(int);
    system("cls");
    printf("enter the size of an array");
    scanf("%d",&n);
    printf("enter elenets in asending order");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    //for display the array
    printf("the elements are\n");
     for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    int c;
    printf("\nchoice 1.liner search or 2.binary search");
    scanf("%d",&c);
    switch (c){
          case 1://linear search
              printf("\nenter the elements whice you want to search");
              scanf("%d",&x);
              for(i=0;i<n;i++){
                if(a[i]==x){
                   printf("the elements is found at %d position",i+1);
                   r=0; 
                }
              }
                if(r==1)
                  printf("number not found");
            // notfound(r);
               break;
          case 2: 
         // binary search   
              int p;
              printf("\nenter the elements whice you want to searceh");
              scanf("%d",&p);
              int beg=0,end=n,mid;
              while(beg<=end){
                mid=(beg+end)/2;
                 if(a[mid]==p){
                   printf("the elements is found at %d position",mid+1);
                   r=0;
                   break;
                }
                else if(x<a[mid]){
                     end=mid-1;
                }
                else{
                  beg=mid+1;
                }
             }
           if(r==1)
            printf("number not found");
            break;
          default:
             printf("you enter invalid choise");
             break;
    }
  getchar(); 
}
