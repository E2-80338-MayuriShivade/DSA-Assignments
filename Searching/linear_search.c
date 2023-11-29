#include<stdio.h>
#define SIZE 9
int linear_search(int arr[],int key);

int main()
{
    int arr[SIZE] = {33,55,88,77,44,99,11,66,22};
    int key;
    printf("Enter key to search : ");
    scanf("%d",&key);
    int index = linear_search(arr,key);
    if(index!=-1)
    {
        printf("key is found at index %d\n",index);
    }
    else{
        printf("key is not found !!!\n");
    }
    return 0;
}

int linear_search(int arr[],int key)
{
    for(int i = 0;i<SIZE;i++){
        if(key == arr[i])
           return i;
    }
    return -1;
}