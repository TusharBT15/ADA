#include<stdio.h>
#include<conio.h>

int gcd(int m, int n)
{
int r;
if(n==0)
{
return m;
}
while(n!=0)
{
r=m%n;
m=n;
n=r;
}
return m;
}
int main()
{
int m,n;
printf("Enter two numbers");
scanf("%d %d",&m,&n);
printf("GCD= %d",gcd(m,n));
}
