#include<stdio.h>
 void towers(int, char, char, char);
 int main()
 {
     int num;
     printf("Enter the number of disks:");
     scanf("%d",&num);
     printf("The sequences of moves involved in the tower of hanoi are:\n");
     towers(num, 'A','C','B');
     return 0;
 }
 void towers(int num, char frompeg, char topeg, char auxpeg)
 {
     if(num==1)
     {
         printf("\n Move disk 1 from peg %c to peg %c",frompeg,topeg);
         return;
     }
     towers(num-1, frompeg,topeg,auxpeg);
     printf("\n Move disk %d from PEG %c to peg %c",num,frompeg,topeg);
     towers(num-1,auxpeg,frompeg,topeg);
 }
