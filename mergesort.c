#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int st, int en1, int end){
        int *b, i, l;
        int p1, p2;
        if(st>=end) {
                return;
        }else{
                l = end-st+1;
                b = malloc(sizeof(int)*l);
                p1 = st;
                p2 = en1+1;
                for(i = 0; i<l; i++) {
                        if(p1<=en1 && p2<=end) {
                                b[i] = (arr[p1]<arr[p2]) ? arr[p1++] : arr[p2++];
                                continue;
                        }else if(p1 > en1) {
                                b[i] = arr[p2++];
                        }else{
                                b[i] = arr[p1++];
                        }
                }
                for(i = 0; i<l; i++) {
                        arr[st+i] = b[i];
                }
                free(b);
        }
}

void mergesort(int *array, int start, int end){
        if(start>=end)
                return;
        int mid = (int) (start+end)/2;
        mergesort(array, start, mid);
        mergesort(array, mid+1, end);
        merge(array, start, mid, end);
}

int main(int argc, char const *argv[]) {
        int *array, length, i;
        printf("Enter the length of the array: ");
        scanf("%d", &length);
        printf("Enter the array elements\n");
        for(i = 0; i<length; i++) {
                scanf("%d",&array[i]);
        }
        mergesort(array, 0, length-1);

        printf("Sorted Array: \n");
        for(i=0; i<length; i++) {
                printf("%d ",array[i]);
        }
        printf("\n");
        return 0;
}
