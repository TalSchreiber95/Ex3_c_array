#include <stdio.h>
#include "isort.h"
/*
    Main of isort.c
*/
#define Len 50 //size of arr scan
void printArr(int arr[],int len){
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
        scanf(" %d",&charScan);
        *(arr+i) = charScan;
    }
    printf("Arr before calling insertion sort\n");  
    int len=sizeof(arr)/sizeof(int);
    printArr(arr,len);
    insertion_sort(arr,len);
    printf("Arr after calling insertion sort\n");
    printArr(arr,len);
    // for(int y =0;y<Len-1;y++){
    //     printf("%d,", *(arr+y) );
    // }

    // printf("%d\n" , *(arr+49));

    return 0;
}