#include<stdio.h>

#define SIZE 9

void print_array(int arr[], int size);
void quick_sort(int arr[], int left, int right);

int main(void)
{
    int arr[SIZE] = {66, 33, 99, 11, 77, 22, 55, 66, 88};

    printf("Before sort : ");
    print_array(arr, SIZE);
    printf("\n");

    quick_sort(arr, 0, SIZE-1);

    printf("After sort : ");
    print_array(arr, SIZE);

    return 0;
}

void print_array(int arr[], int size)
{
    for(int i = 0 ; i < size ; i++)
        printf("%-4d", arr[i]);
}

void quick_sort(int arr[], int left, int right)
{
    if(left >= right)
        return;
    int i = left, j = right;
    while(i < j)
    {
        for( ; arr[i] <= arr[left] ; i++); 
        for( ; arr[j] > arr[left] ; j--);
        if(i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        } 
    }
    
    int temp = arr[j];
    arr[j] = arr[left];
    arr[left] = temp;
   
    quick_sort(arr, left, j - 1);
    quick_sort(arr, j + 1, right);
}
