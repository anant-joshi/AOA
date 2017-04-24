#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int randr(int min, int max){
    double scaled = (double)rand()/RAND_MAX;
    return (max-min+1)*scaled+min;
}

void swap_ints(int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int partition(int *arr, int st, int en){
    //get random index as pivot
    int pivot;
    int pivot_val;
    int i, p;
    pivot = randr(st, en);
    pivot_val = arr[pivot];
    swap_ints(&arr[pivot], &arr[st]);
    for(i = st+1, p=st; i<=en; i++){
        if(arr[i]<=pivot_val){
            p++;
            swap_ints(&arr[i], &arr[p]);
        }
    }
    swap_ints(&arr[p], &arr[st]);
    return p;
}

void quicksort(int *array, int start, int end){
    if(start >= end){
        return;
    }
    int pivot = partition(array, start, end);
    quicksort(array, start, pivot-1);
    quicksort(array, pivot+1, end);
}

int main(int argc, char const *argv[]) {
    int *array, length, i;
    printf("Enter the length of the array: ");
    scanf("%d",&length);
    array = malloc(sizeof(int)*length);

    printf("Enter the array elements\n");
    for(i = 0; i<length; i++){
        scanf("%d",&array[i]);
    }
    //seed the random number generator
    srand((unsigned int) time(NULL));

    //sort the array
    quicksort(array, 0, length-1);

    //display the result
    printf("The sorted array is\n");
    for(i = 0; i<length; i++){
        printf("%d  ",array[i]);
    }
    printf("\n");
    return 0;
}
