#include<stdio.h>
#define SIZE 6
#define SWAP(a,b){int t=a;a=b;b=t;};

void bubble_sort(int arr[]);
void display(int arr[]);

int main()
{
   int arr[SIZE]={30,20,40,10,60,50};
   printf("\n Before sort :");
   display(arr);
   bubble_sort(arr);
   printf("After sort :");
   display(arr);
   return 0;

}
void bubble_sort(int arr[])
{
  for(int it=0;it<SIZE-1;it++)
  {
    for(int pos=0;pos < SIZE; pos++)
    {
        if(arr[pos] > arr[pos+1])
        {
            SWAP(arr[pos],arr[pos+1]);
        }
    }
  }
}

void display(int arr[])
{
    for(int i=0;i<SIZE;i++)
    {
        printf("%4d",arr[i]);
    }
    printf("\n");
}