#include<stdio.h>

int a[10][10], n;
void floyds();
int min(int,int);

void main() {
  int i, j;
  printf("\nEnter the num of vertices: \t");
  scanf("%d", &n);
  printf("\nEnter the cost matrix: \n");
  for(i = 1; i <= n; i++) {
    for(j = 1; j <= n; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  floyds();
}

void floyds() {
  int i, j, k;
  for(k = 1; k <= n; k++) {
    for(i = 1; i <=n; i++) {
      for(j = 1; j <= n; j++) {
        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
      }
    }
  }

  printf("\nAll pair shortest path matrix is: \n");
  for(i = 1; i <= n; i++) {
    for(j = 1; j <= n; j++) {
      printf("%d\t", a[i][j]);
    }
    printf("\n\n");
    }
}

int min(int x, int y) {
  if(x < y) {
    return x;
  }
  else {
    return y;
  }
}
/*
Enter the num of vertices: 	4

Enter the cost matrix:
9999 9999 3 9999
2 9999 9999 9999
9999 7 9999 1
6 9999 9999 9999

All pair shortest path matrix is:
10	10	3	4

2	12	5	6

7	7	10	1

6	16	9	10
*/
