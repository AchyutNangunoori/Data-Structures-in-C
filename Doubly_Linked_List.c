#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head;
void beginsert();
void lastinsert();
void randominsert();
void begin_delete();
void last_delete();
void random_delete();
void search();
void display();
void main()
{
    int choice = 0;
    while(choice != 9)
    {
        printf("Choose one option from the following list ...\n");
        printf("1. Insert at the beginning\n2. Insert at the end\n3. Insert at any random location\n"); 
        printf("4. Delete from the beginning\n5. Delete from the end\n6. Delete node at any random location\n");
        printf("7. Search for an element\n8. Display the list\n9. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: beginsert();
                    break;
            case 2: lastinsert();
                    break;
            case 3: randominsert();
                    break;
            case 4: begin_delete();
                    break;
            case 5: last_delete();
                    break;
            case 6: random_delete();
                    break;
            case 7: search();
                    break;
            case 8: display();
                    break;
            case 9: exit(0);
            default:printf("Please enter a valid choice.\n");
        }
    }
}
void beginsert()
{
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("OVERFLOW\n");
    }
    else
    {
        printf("Enter value: ");
        scanf("%d", &item);
        ptr->data = item;
        if (head == NULL)
        {
            ptr->prev = NULL;
            ptr->next = NULL;
            head = ptr;
        }
        else
        {
            ptr->prev = NULL;
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
        }
        printf("Node inserted\n");
    }
}
void lastinsert()
{
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("OVERFLOW\n");
    }
    else
    {
        printf("Enter value: ");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = NULL;
        if (head == NULL)
        {
            ptr->prev = NULL;
            head = ptr;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
        }
        printf("Node inserted\n");
    }
}
void randominsert()
{
    int i, loc, item;
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("OVERFLOW\n");
    }
    else
    {
        printf("Enter value: ");
        scanf("%d", &item);
        ptr->data = item;
        printf("Enter the location after which you want to insert: ");
        scanf("%d", &loc);
        temp = head;
        for (i = 1; i < loc; i++)
        {
            if (temp == NULL)
            {
                printf("Cannot insert\n");
                return;
            }
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = NULL;
        }
        else
        {
            ptr->next = temp->next;
            ptr->next->prev = ptr;
            temp->next = ptr;
            ptr->prev = temp;
        }
        printf("Node inserted\n");
    }
}
void begin_delete()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        ptr = head;
        if (ptr->next == NULL)
        {
            head = NULL;
            free(ptr);
        }
        else
        {
            head = ptr->next;
            head->prev = NULL;
            free(ptr);
        }
        printf("Node deleted from the beginning\n");
    }
}
void last_delete()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        ptr = head;
        if (ptr->next == NULL)
        {
            head = NULL;
            free(ptr);
        }
        else
        {
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->prev->next = NULL;
            free(ptr);
        }
        printf("Node deleted from the end\n");
    }
}
void random_delete()
{
    struct node *ptr, *temp;
    int loc;
    printf("Enter the location of the node you want to delete: ");
    scanf("%d", &loc);
    ptr = head;
    for (int i = 1; i < loc; i++)
    {
        if (ptr == NULL)
        {
            printf("Cannot delete\n");
            return;
        }
        ptr = ptr->next;
    }
    if (ptr->next == NULL)
    {
        ptr->prev->next = NULL;
        free(ptr);
    }
    else if (ptr == head)
    {
        head = ptr->next;
        head->prev = NULL;
        free(ptr);
    }
    else
    {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
    }
    printf("Deleted node at location %d\n", loc);
}
void search()
{
    struct node *ptr;
    int item, flag = 0;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("Enter the element you want to search for: ");
        scanf("%d", &item);
        ptr = head;
        while (ptr != NULL)
        {
            if (ptr->data == item)
            {
                printf("Item found\n");
                flag = 1;
                break;
            }
            ptr = ptr->next;
        }
        if (flag == 0)
        {
            printf("Item not found\n");
        }
    }
}
void display()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        ptr = head;
        printf("Printing values...\n");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
    printf("\n");
}