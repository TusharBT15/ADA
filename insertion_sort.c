#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void insertionSort(int n, int a[]);

void main()
{
    int a[15000],n,i,j,ch,temp;
    clock_t start,end;
    while(1)
    {
        printf("\n 1. For manual entry of N value and array elements ");
        printf("\n 2. To display time taken for sorting number of elements N in the range 500 to 14500 ");
        printf("\n 3. To exit ");
        printf("\n Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1 :  printf("\n Enter the number of elements : ");
                  scanf("%d",&n);
                  printf("\n Enter the array elements : ");
                  for(i=0;i<n;i++)
                        scanf("%d",&a[i]);

                  start = clock();
                  insertionSort(n,a);
                   for(j=0;j<50000000;j++)
                      temp = 38/600;
                  end=clock();

                    printf("\n Sorted array is : ");
                  for(i=0;i<n;i++)
                        printf("%d \t",a[i]);

                  printf("\n Time taken to sort %d elements is %1.10f seconds. \n",n , (((double)(end - start))/CLOCKS_PER_SEC));
                  break;

          case 2 :  n = 500;
                  while(n <= 14500)
                  {
                    for(i=0;i<n;i++)
                        a[i] = rand()%1000;

                    start = clock();
                    insertionSort(n,a);
                    for(j=0;j<500000;j++)
                      temp = 38/600;
                    end = clock();

                    printf("\n Time taken to sort %d elements is %f seconds. \n",n , (((double)(end - start))/CLOCKS_PER_SEC));
                    n = n + 1000;
                  }
                  break;

        case 3 : exit(0);
        }
        getchar();
    }
}
void insertionSort(int n, int a[])
{
  for(int step = 1; step < n; step++)
   {
    int key = a[step];
    int j = step - 1;
    while (key < a[j] && j >= 0)
    {
      a[j + 1] = a[j];
      --j;
    }
    a[j + 1] = key;
  }
}
