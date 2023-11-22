#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node *front;
struct node *rear;
void enqueue(int);
void dequeue();
void display();
void main()
{
	int op, x;
	while(1)
	{
		printf("Enter 1 to enqueue\n");
		printf("Enter 2 to dequeue\n");
		printf("Enter 3 to display\n");
		printf("Enter 4 to exit\n");
		printf("Enter your choice\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1: printf("Enter element to be added\n");
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
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode -> next = NULL;
    if(front == NULL)
    front = rear = newNode;
    else
    {
        rear -> next = newNode;
        rear = newNode;
    }
}
void dequeue()
{
    if(front == NULL)
    printf("\nQueue is Empty!!!\n");
    else
    {
        struct node *temp = front;
        front = front -> next;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
    }
}
void display()
{
    if(front == NULL)
    printf("\nQueue is Empty!!!\n");
    else
    {
        struct node *temp = front;
        while(temp!= NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}