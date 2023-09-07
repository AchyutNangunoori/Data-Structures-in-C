#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char stack[100];
int top=-1;
void push(char);
char pop();
void main()
{
    char exp[10];
    char ch;
    printf("Enter expression\n");
    scanf("%s",exp);
    int n=strlen(exp);
    for(int i=0;i<=n;i++)
    {
        if(i==n)
        {
            if(top<0)
            printf("Expression is valid\n");
            else
            printf("Expression is invalid\n");
        }
        else if(exp[i]=='{'||exp[i]=='['||exp[i]=='(')
        {
            push(exp[i]);
        }
        else if(exp[i]=='}'||exp[i]==']'||exp[i]==')')
        {
            int res=0;
            ch=pop();
            if(ch=='{'&&exp[i]=='}')
            res=1;
            else if(ch=='['&&exp[i]==']')
            res=1;
            else if(ch=='('&&exp[i]==')')
            res=1;
            else
            res=0;
            if(res==0)
            {
                printf("Expression is invalid\n");
                exit(0);
            }
        }
        else
        {
            printf("Invalid input symbol encountered\n");
            exit(0);
        }
    }
}
void push(char ch)
{
    if(top==99)
    {
        printf("Overflow\n");
    }
    else
    {
        top++;
        stack[top]=ch;
    }
}
char pop()
{
    if(top<0)
    {
        printf("Underflow\n");
    }
    else
    {
        char ch=stack[top];
        top--;
        return(ch);
    }
}