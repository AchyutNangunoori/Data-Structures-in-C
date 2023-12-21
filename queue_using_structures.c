#include<stdio.h>
#include<stdlib.h>
int size=100;
struct queue
{
    int list[100];
    int front, rear;
};
void enqueue(struct queue*, int);
int dequeue(struct queue*);
void display(struct queue);
void main()
{
    struct queue q;
    q.front=0;
    q.rear=-1;
    int op, x, n;
    while(1)
    {
        printf("Enter 1 for enqueue\n");
        printf("Enter 2 for dequeue\n");
        printf("Enter 3 for display\n");
        printf("Enter 4 for exit\n");
        printf("Enter your choice\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:printf("Enter Value to be added\n");
                   scanf("%d",&x);
                   enqueue(&q,x);
                   printf("Element added successfully\n");
                   break;
            case 2:n=dequeue(&q);
                   printf("Deleted Element: %d\n",n);
                   break;   
            case 3:display(q);
                   break;
            case 4:exit(0);
            default:printf("Invalid Choice\n");                      
        }
    }
}
void enqueue(struct queue* qp, int x)
{
    if(qp->rear==(size-1))
    printf("overflow\n");
    else
    {
        int temp=qp->rear+1;
        qp->list[temp]=x;
        qp->rear++;
    }
}
int dequeue(struct queue* qp)
{
    if(qp->front>qp->rear)
    printf("Underflow\n");
    else
    {
        int temp=qp->front;
        qp->front++;
        return(qp->list[temp]);
    }
}
void display(struct queue q)
{
    printf("Printing Elements\n");
    for(int i=q.front;i<=q.rear;i++)
    {
        printf("%d\n",q.list[i]);
    }
}
