// Johnson and Trotter algorithm.
#include<stdio.h>
int LEFT_TO_RIGHT = 1;
int RIGHT_TO_LEFT = 0;
int searchArr(int a[], int n, int mobile)    // Utility functions for finding the position of largest mobile integer in a[].
{
for (int i = 0; i < n; i++)
if (a[i] == mobile)
return i + 1;
}

int getMobile(int a[], int dir[], int n)     // To carry out step 1 of the algorithm i.e. to find the largest mobile integer.
{
int mobile_prev = 0, mobile = 0;
for (int i = 0; i < n; i++)
{

if (dir[a[i]-1] == RIGHT_TO_LEFT && i!=0)    // direction 0 represents RIGHT TO LEFT.
{
if (a[i] > a[i-1] && a[i] > mobile_prev)
{
mobile = a[i];
mobile_prev = mobile;
}
}

if (dir[a[i]-1] == LEFT_TO_RIGHT && i!=n-1)  // direction 1 represents LEFT TO RIGHT.
{
if (a[i] > a[i+1] && a[i] > mobile_prev)
{
mobile = a[i];
mobile_prev = mobile;
}
}
}

if (mobile == 0 && mobile_prev == 0)
return 0;
else
return mobile;
}

int printOnePerm(int a[], int dir[], int n)  // Prints a single permutation
{
int mobile = getMobile(a, dir, n);
int pos = searchArr(a, n, mobile);

if (dir[a[pos - 1] - 1] == RIGHT_TO_LEFT)    // swapping the elements according to the direction i.e. dir[].// swap(a[pos-1], a[pos-2]);
{  
  printf("\n");
  int temp;
  temp = a[pos-1] ;
  a[pos-1] = a[pos-2];
  a[pos-2]=  temp;
}

else if (dir[a[pos - 1] - 1] == LEFT_TO_RIGHT)    // swap(a[pos], a[pos-1]);
{   
  printf("\n");
  int temp;
  temp = a[pos] ;
  a[pos] = a[pos-1];
  a[pos-1]=  temp;
}
printf("\n");

for (int i = 0; i < n; i++)   // changing the directions for elements greater than largest mobile integer.
{
if (a[i] > mobile)
{
if (dir[a[i] - 1] == LEFT_TO_RIGHT)
dir[a[i] - 1] = RIGHT_TO_LEFT;
else if (dir[a[i] - 1] == RIGHT_TO_LEFT)
dir[a[i] - 1] = LEFT_TO_RIGHT;
}
}

for (int i = 0; i < n; i++)
printf(" %d", a[i]);
}

int fact(int n)// To end the algorithm for efficiency it ends at the factorial of n because number of permutations possible is just n!.
{
int res = 1;
int i;
for (i = 1; i <= n; i++)
res = res * i;
return res;
}

void printPermutation(int n)// This function mainly calls printOnePerm() one by one to print all permutations.
{
int a[n];// To store current permutation
int dir[n];// To store current directions //printf("\n"); // storing the elements from 1 to n and printing first permutation.
for (int i = 0; i < n; i++)
{
a[i] = i + 1;
printf(" %d", a[i]);
}

for (int i = 0; i < n; i++)// initially all directions are set to RIGHT TO LEFT i.e. 0.
dir[i] = RIGHT_TO_LEFT;

for (int i = 1; i < fact(n); i++)// for generating permutations in the order.
printOnePerm(a, dir, n);//printf("\n");
}

int main()
{
int n;
printf("Enter n");
scanf("%d",&n);
printPermutation(n);
return 0;
}
