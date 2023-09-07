#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int stack[100];
int top=-1;
void push(int);
int pop();
void main()
{
    char n1,n2;
    int res=0;
    char exp[100];
    char ch;
    printf("Enter a valid postfix notation that you want to evaluate\n");
    scanf("%s",exp);
    int n=strlen(exp);
    exp[n]='\0';
    //int result=0;
    for(int i=0;i<n;i++)
    {
        if(exp[i]>=48&&exp[i]<58)
        {
            int a=exp[i]-48;
            push(a);
        }
        else
        {
            n1=pop();
            n2=pop();
            switch(exp[i])
            {
                case '+': res=(n2)+(n1);
                          push(res);
                          break; 
                case '-': res=(n2)-(n1);
                          push(res);
                          break;      
                case '*': res=(n2)*(n1);
                          push(res);
                          break;      
                case '/': res=(n2)/(n1);
                          push(res);
                          break;      
                case '%': res=(n2)%(n1);
                          push(res);
                          break;      
                case '^': res=(n2)^(n1);
                          push(res);
                          break;    
                default: printf("Invalid expression encountered\n");                                
            }
        }
    }
    printf("Result: %d\n",res);
}
void push(int ch)
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
int pop()
{
    if(top<0)
    {
        printf("Underflow\n");
    }
    else
    {
        int ch=stack[top];
        top--;
        return(ch);
    }
}