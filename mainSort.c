#include "isort.h"
/*
    Main of isort.c
*/

void printArr(int arr[],int len){ // print the array as requested
    int i;
    for(i = 0 ; i < len-1 ;i++){
        printf("%d,",arr[i]);
    }
    printf("%d\n",arr[len-1]);
}

int main(){
    int arr[Len];
    int charScan;
    for(int i  = 0; i<Len;i++){
        scanf("%d",&charScan);
        *(arr+i) = charScan;
    }
    // printf("Arr before calling insertion sort: \n \n");  
    int len=sizeof(arr)/sizeof(int);
    // printArr(arr,len);
    insertion_sort(arr,len);
    printf("Arr after calling insertion sort:\n");
    printArr(arr,len);
    return 0;
}