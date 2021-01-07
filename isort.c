#include "isort.h"
#include <stdio.h>
// {1,3,-2,4} arr point to 1 and i=2 should return
// {1,3,3,-2}
void shift_element(int* arr, int i) {
    int temp1 = *(arr);
    for (int j = 1; j <= i; j++) {
        int temp2 = *(arr + j);
        *(arr + j) = temp1;
        temp1 = temp2;
    }
}
void insertion_sort(int* arr , int len) {
    for (int i = 0; i < len; i++) {
        int currentNumber = *(arr + i);
        int count = 0;
        int countDown = i;
        while (countDown > 0 && currentNumber < *(arr + countDown - 1)) {
            count++;
            countDown--;
        }
        if (count > 0) {
            shift_element((arr+i - count), count);
            *(arr+i - count) = currentNumber;
        }
    }
}
