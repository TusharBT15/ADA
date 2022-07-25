#include <stdio.h>
#include<time.h>
#include<stdlib.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
  int data[15000], n, i, j, ch, temp;
  clock_t start,end;
  while(1) {
    printf("\n1:For manual entry of N value and array elements");
    printf("\n2:To display time taken for sorting number of elements N in the range 500 to 14500");
    printf("\n3:To exit");
    printf("\nEnter your choice:");
    scanf("%d", &ch);
    switch(ch) {
        case 1: printf("\nEnter the number of elements: ");
        scanf("%d",&n);
        printf("\nEnter array elements: ");

        for(i = 0; i < n; i++) {
            scanf("%d", &data[i]);
        }
        start = clock();
        printf("Unsorted Array\n");
        printArray(data, n);

        partition(data, 0, n-1);
        end = clock();
        printf("\nSorted array is: ");
        quickSort(data, 0, n-1);
        printArray(data, n);

        for(i = 0; i < n; i++)
            printf("%d\t", data[i]);

        printf("\n Time taken to sort %d numbers is %f Secs",n, (((double)(end-start))/CLOCKS_PER_SEC));
        break;

        case 2:
            n = 500;
            while(n <= 14500) {
            for(i = 0; i < n; i++) {
            //a[i]=random(1000);
                data[i] = n - i;
            }
            start = clock();
            partition(data, 0, n - 1);

            //Dummy loop to create delay
            for(j = 0; j < 50000000; j++) {
                temp = 38/600;
            }
            end = clock();
            printf("\n Time taken to sort %d numbers is %f Secs", n, (((double)(end-start))/CLOCKS_PER_SEC));
            n = n + 1000;
            }
        break;

        case 3: exit(0);
    }
getchar();

}

}
