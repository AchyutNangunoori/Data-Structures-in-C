#include<stdio.h>
#include<stdlib.h>
int queue[100];
int rear=-1,front=0;
void enqueue(int);
void dequeue();
void display();
void main()
{
    int ch=0,x;
    while(ch!=4)
    {
        printf("Enter 1 if you want to insert an element\n");
        printf("Enter 2 if you want to delete an element\n");
        printf("Enter 3 to display\n");
        printf("Enter 4 to exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter element you want to insert\n");
                    scanf("%d",&x);
                    enqueue(x);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("Invalid Choice\n");
        }
    }
}
void enqueue(int x)
{
    if(rear==99)
    {
        printf("Queue Overflow\n");
        printf("Element cannot be inserted\n");
    }
    else
    {
        rear++;
        queue[rear]=x;
        printf("Element inserted successfully\n");
    }
}
void dequeue()
{
    if(front>rear)
    {
        printf("Queue underflow\n");
        printf("Nothing to delete\n");
    }
    else
    {
        printf("Deleted element is %d\n",queue[front]);
        front++;
    }
}
void display()
{
    if(front>rear)
    {
        printf("Queue Underflow\n");
        printf("Nothing to display\n");
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}