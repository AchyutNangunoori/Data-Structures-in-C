#include<stdio.h>
void hanoi(int, char, char, char);
void main()
{
    int disks;
    printf("Enter number of disks\n");
    scanf("%d",&disks);
    hanoi(disks,'A','B','C');
}
void hanoi(int disks, char A, char B, char C)
{
    if(disks==1)
    {
        printf("Move Disk %d from %c to %c\n",disks,A,C);
    }
    else
    {
        hanoi(disks-1,A,C,B);
        printf("Move disk %d from %c to %c\n",disks,A,C);
        hanoi(disks-1,B,A,C);
    }
}