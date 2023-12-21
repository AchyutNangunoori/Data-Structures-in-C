#include<stdio.h>
#include<stdlib.h>
void push(int);
void pop();
void display();
int stack[100];
int top=-1;
void main()
{
    int ch=0, x;
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
                    push(x);
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("Invalid Choice\n");
        }
    }
}
void push(int x)
{
    if(top==99)
    {
        printf("Stack Overflow\n");
        printf("Element cannot be inserted\n");
    }
    else
    {
        top++;
        stack[top]=x;
        printf("Element inserted successfully\n");
    }
}
void pop()
{
    if(top<0)
    {
        printf("Stack Underflow\n");
        printf("No element to delete\n");
    }
    else
    {
        printf("Deleted Element is %d\n",stack[top]);
        top--;
    }
}
void display()
{
    if(top<0)
    {
        printf("Stack Underflow\n");
        printf("Nothing to display\n");
    }
    else
    {
        for(int i=top;i>=0;i--)
        {
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
}