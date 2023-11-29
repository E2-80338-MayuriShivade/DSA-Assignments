#include<stdio.h>
#define SIZE 6
#define SWAP(a,b){int t=a;a=b;b=t;}
void selection_sort(int arr[]);
void display(int arr[]);

int main()
{
    int arr[SIZE]={30,50,20,10,40,60};
    printf("\nBefore sort : \n");
    display(arr);
    selection_sort(arr);
    printf("After sort : \n");
    display(arr);

    return 0;
}
void selection_sort(int arr[])
{
    for(int sel_pos=0;sel_pos<SIZE-1;sel_pos++)
    {
        for(int pos=sel_pos+1;pos<SIZE;pos++)
        {
            if(arr[sel_pos] > arr[pos])
            {
                SWAP(arr[sel_pos],arr[pos]);

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