#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
}*ptr;
struct node* insert(struct node* ,int);
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
int search(struct node*,int);
struct node* delete(struct node*,int);
struct node* minValueNode(struct node*);
void main()
{
    int ch=1,res;
    ptr=NULL;
    int x;
    while(ch!=5)
    {
        printf("Enter 1 to insert an element\n");
        printf("Enter 2 to delete an element\n");
        printf("Enter 3 to search for an element\n");
        printf("Enter 4 to display\n");
        printf("Enter 5 to exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("enter element :\n");
                    scanf("%d",&x);
                    ptr=insert(ptr,x);
                    break;
            case 2: printf("Enter element to be deleted\n");
                    scanf("%d",&x);
                    res=search(ptr,x);
                    if(res==-1)
                    printf("Element not found\n");
                    else
                    {
                        ptr=delete(ptr,x);
                        printf("Element deleted Successfully\n");
                    }
                    break;
            case 3: printf("Enter element to be searched for\n");
                    scanf("%d",&x);
                    res=search(ptr,x);
                    if(res==-1)
                    printf("Element not found\n");
                    else
                    printf("Element Found\n");
                    break;
            case 4: printf("Inorder Traversal of Resultant Tree\n");
                    inorder(ptr);
                    printf("\n");
                    printf("Preorder Traversal of Resultant Tree\n");
                    preorder(ptr);
                    printf("\n");
                    printf("Postorder Traversal of Resultant Tree\n");
                    postorder(ptr);
                    printf("\n");
                    break;
            case 5: exit(0);
            default:printf("Enter a valid Option\n");
        }
    }
}
struct node* insert(struct node* ptr,int x)
{ 
    if(ptr==NULL)
    {
        ptr=(struct node*)malloc(sizeof(struct node));
        ptr->data=x;
        ptr->left=NULL;
        ptr->right=NULL;
    }
    else if(x<ptr->data)
    {
        ptr->left=insert(ptr->left,x);
    }
    else if(x>ptr->data)
    {
        ptr->right=insert(ptr->right,x);
    }
    else
    printf("no duplicates allowed\n");
    return (ptr);
}
void inorder(struct node* root) 
{    
    if (root == NULL)
    return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void preorder(struct node* root)
{    
    if (root == NULL)
    return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node* root)
{    
    if (root == NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
int search(struct node* root,int x)
{
    int flag=0;
    if(root==NULL)
    {
        if(flag==0)
        return -1;
    }
    else if(root->data==x)
    {
        return 1;
        flag++;
    }
    else
    {
        if(x<root->data)
        search(root->left,x);
        else
        search(root->right,x);
    }
}
struct node *delete(struct node *root, int key) 
{
    if (root == NULL) return root;  
    if (key < root->data)
    root->left = delete(root->left, key);
    else if (key > root->data)
    root->right = delete(root->right, key);
    else
    {
        if (root->left == NULL) 
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) 
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}
struct node *minValueNode(struct node *node) 
{
    struct node *current = node;
    while (current && current->left != NULL)
    current = current->left;
    return current;
}