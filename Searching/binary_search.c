#include<stdio.h>
#define SIZE 9 
int binary_search(int arr[],int key);
int rec_binary_search(int arr[],int key,int left,int right);

int main(){
    int arr[SIZE] = {10,20,30,40,50,60,70,80};
    int key;
    printf("Enter the key to search : ");
    scanf("%d",&key);
    int index = binary_search(arr,key);
    if(index != -1){
        printf("key is found at index %d\n",index);
        }
    else{
        printf("key is not found\n");
        }

    int result = rec_binary_search(arr,key,0,SIZE-1);
    if(result!=-1){
        printf("Recursion : key is found at index %d\n",result);
    }
    else{
        printf("Recursion :  key is not found");
    } 




}

int binary_search(int arr[],int key){
    int left=0,right = SIZE-1,mid;

    while(left<=right)
    {
        mid = (left+right)/2;
        if(key==arr[mid]){
          return mid;
        }
        if(key < arr[mid]){
            right = mid - 1;
        } 
        else
        {
           left = mid+1;
        }
         
    }
    return -1;
}

int rec_binary_search(int arr[],int key,int left,int right){
    int result;
    if(left>right){
        return -1;
    }
    int mid = (left+right)/2;
    if(key == arr[mid]){
        return mid;
    }
    else if (key < arr[mid])
    {/* condition */
        result  = rec_binary_search(arr,key,left,mid-1);
    }
    else
    {
        result  = rec_binary_search(arr,key,mid+1,right);
    }
    return result;
    
    
}