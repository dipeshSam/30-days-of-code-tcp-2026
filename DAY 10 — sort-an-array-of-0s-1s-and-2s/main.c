#include <stdio.h>

void swapInts(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void segregate(int arr[], int size){
    int left = 0, mid = 0, right = size - 1;

    while(mid <= right)
        if(arr[mid] == 0)
            swapInts(&arr[mid++], &arr[left++]);
        else if(arr[mid] == 1)
            mid++;
        else           // arr[mid] == 2
            swapInts(&arr[mid], &arr[right--]);

}


int main(){
    int arr[] = {1, 1, 2, 0, 2, 0, 2, 1, 1, 0, 1, 0, 0, 2, 0, 1, 2, 0, 1, 2};
    int size = sizeof(arr)/sizeof(arr[0]);

    segregate(arr, size);

    for(size_t i = 0; i < size; i++)
        printf("%d ", arr[i]);


    return 0;
}