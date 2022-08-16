#include<stdio.h>
#include<conio.h>

void prims();
int c[10][10], n;

void main() {
    int i, j;
    printf("\n Enter the num of vertices: \t");
    scanf("%d", &n);
    printf("\n Enter the cost matrix: \n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
        }
    }
    prims();
    getch();
}

void prims() {
    int i, j, u, v, min;
    int ne = 0, mincost = 0;
    int elec[10];
    for(i = 1; i <= n; i++) {
        elec[i] = 0;
    }
    elec[1] = 1;
    while(ne != n - 1) {
        min = 9999;
        for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            if(elec[i] == 1) {
                if(c[i][j] < min) {
                    min=c[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        }
        if(elec[v] != 1) {
            printf("\n%d-----> %d = %d\n", u, v, min);
            elec[v] = 1;
            ne = ne + 1;
            mincost = mincost + min;
        }
        c[u][v] = c[v][u] = 9999;
    }
    printf("\n mincost = %d", mincost);
}


/*
OUTPUT:

Enter the num of vertices: 	6

Enter the cost matrix: 
9999 3 9999 9999 6 5
3 9999 1 9999 9999 4
9999 1 9999 6 9999 4
9999 6 6 9999 8 5
6 9999 9999 8 9999 2
5 4 4 5 2 9999

1-----> 2 = 3

2-----> 3 = 1

2-----> 6 = 4

6-----> 5 = 2

6-----> 4 = 5

mincost = 15
*/
