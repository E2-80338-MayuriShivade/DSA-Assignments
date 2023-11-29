#include<stdio.h>
#include<stdlib.h>

#define SIZE 9

void print_array(int arr[], int size);
void merge_sort(int arr[], int left, int right);

int main(void)
{
    int arr[SIZE] = {6, 1, 9, 3, 7, 2, 8, 4, 5};

    printf("Before sort : ");
    print_array(arr, SIZE);
    printf("\n");

    merge_sort(arr, 0, SIZE-1);

    printf("After sort : ");
    print_array(arr, SIZE);

    return 0;
}

void print_array(int arr[], int size)
{
    for(int i = 0 ; i < size ; i++)
        printf("%-4d", arr[i]);
}

void merge_sort(int arr[], int left, int right)
{
    
    if(left == right)
        return;
    
    int mid = (left + right) / 2;
   
    merge_sort(arr, left, mid);
   
    merge_sort(arr, mid + 1, right);
   
    int size = right - left + 1;
    int *temp = (int *)malloc(sizeof(int) * size);
    int i = left, j = mid + 1, k = 0;
    
    while(i <= mid && j <= right)
    {
        
        temp[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
    }
    
    while(i <= mid)
    {
        temp[k++] = arr[i++];
    }
    
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }
    for(int i = 0 ; i < size ; i++)
        arr[left + i] = temp[i];
    free(temp);
}
