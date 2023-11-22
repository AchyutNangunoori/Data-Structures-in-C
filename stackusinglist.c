#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node *top;
void push(int);
void pop();
void display();
void main()
{
	int op, x;
	while(1)
	{
		printf("Enter 1 to push\n");
		printf("Enter 2 to pop\n");
		printf("Enter 3 to display\n");
		printf("Enter 4 to exit\n");
		printf("Enter your choice\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1: printf("Enter element to be added\n");
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
	struct node* newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x;
	if(top==NULL)
	{
		newnode->next=NULL;
		top=newnode;
	}
	else
	{
		newnode->next=top;
		top=newnode;
	}
}
void pop()
{
	struct node* newnode;
	newnode=top;
	if(top==NULL)
	{
		printf("Stack Underflow\n");
	}
	else
	{
		printf("The deleted elemented is: %d\n",newnode->data);
		top=newnode->next;
		free(newnode);
	}
}
void display()
{
	struct node* newnode;
	newnode=top;
	if(top==NULL)
	printf("Stack is empty\n");
	else
	{
		while(newnode!=NULL)
		{
			printf("%d\n",newnode->data);
			newnode=newnode->next;
		}
	}
}
