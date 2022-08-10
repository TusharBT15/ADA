#include <stdio.h>
#include <time.h>

int i,j,temp;
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int a[], int N, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < N && a[left] > a[largest]){
         largest = left;
    }
    if (right < N && a[right] > a[largest]){
        largest = right;
    }
    if (largest != i) {
        swap(&a[i], &a[largest]);
        heapify(a, N, largest);
    }
}
void heapSort(int a[], int N){
    for ( i = N / 2 - 1; i >= 0; i--){
     heapify(a, N, i);
    }
    for ( i = N - 1; i >= 0; i--) {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}
void main()
{
    int a[10000];
    clock_t start,end;
    int N = sizeof(a) / sizeof(a[0]);
    int n=1000;
    while(n<=10000){
        for(i=0;i<n;i++){a[i] = rand();}
        start = clock();
        heapSort(a, N);
        for(j=0;j<500000000;j++){temp = 38/600;}
        end = clock();
        printf("\n Time taken to sort %d elements is %f seconds. \n",n , (((double)(end - start))/CLOCKS_PER_SEC));
        n = n + 1000;
    }
}
