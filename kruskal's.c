#include<stdio.h>
#include<conio.h>
void kruskals();
int c[10][10],n;
void main()
{
int i,j;
printf("enter the no. of vertices:\t");
scanf("%d",&n);
printf("enter the cost matrix:\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d",&c[i][j]);
}
}
kruskals();
getch();
}

void kruskals()
{
int i,j,u,v,a,b,min;
int ne=0,mincost=0;
int parent[10];
for(i=1;i<=n;i++)
{
parent[i]=0;
}
while(ne!=n-1)
{
min=9999;
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
if(c[i][j]<min)
{
min=c[i][j];
u=a=i;
v=b=j;
}
}
}

while(parent[u]!=0)
{
u=parent[u];
}
while(parent[v]!=0)
{
v=parent[v];
}
if(u!=v)
{
printf("\n%d-----%d=%d\n",a,b,min);
parent[v]=u;
ne=ne+1;
mincost=mincost+min;
}
c[a][b]=c[b][a]=9999;
}
printf("mincost=%d",mincost);
}


/*
Enter the num of vertices: 	6
Enter the cost matrix: 
9999 3 9999 9999 6 5 
3 9999 1 9999 9999 4 
9999 1 9999 6 9999 4 
9999 6 6 9999 8 5
6 9999 9999 8 9999 2
5 4 4 5 2 9999

2----->3 = 1

5----->6 = 2

1----->2 = 3

2----->6 = 4

4----->6 = 5

mincost = 15
*/
