#include<stdio.h>
#define SIZE 6
#include <string.h>


void insertion_sort(char arr[100]);
void display(char arr[]);

// int main(){
//     // int arr[SIZE]={55,22,44,11,33,77,66};
//     char arr[SIZE] = {'M','A','Y','U','R','I'};
//     printf(" Before sort \n");
//     display(arr);
//     printf("After sort \n");
//     insertion_sort(arr);
//     display(arr);
//     return 0;
// }

// void insertion_sort(char arr[])
// {
//     int i,j;
//     char temp;
//     for(i=1;i<SIZE;i++)
//     {
//         temp=arr[i];
//         for(j=i-1;j>=0 && arr[j] > temp;j--)
//         {
//             arr[j+1]=arr[j];
//         }
//         arr[j+1]=temp;
//     }
// }

// void display(char arr[])
// {
//     for(int i = 0; i < SIZE; i++)
//     {
//        printf("%4c",arr[i]); 
//     }
//     printf("\n");
    
// }


void insertionSort(char *arr[], int n) {
    int i, j;
    char *key;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && strcmp(arr[j], key) > 0) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    char *strings[] = {"banana", "apple", "date", "cherry", "blueberry"};
    int n = sizeof(strings) / sizeof(strings[0]);

    insertionSort(strings, n);

    printf("Sorted strings: \n ");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}