#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char stack[100];
int top=-1;
void push(char);
char pop();
int check(char);
void main()
{
    char exp[100];
    char ch;
    printf("Enter the expression you want to convert\n");
    scanf("%s",exp);
    int n=strlen(exp);
    //printf("Length: %d\n",n);
    char op[10];
    int index=0;
    for(int i=0;i<=n;i++)
    {
        if(i==n)
        {
            do
            {
                ch=pop();
                //printf("%c",ch);
                op[index]=ch;
                index++;
            } while(top>=0);
            break;
        }
        if(exp[i]>=65&&exp[i]<=90||exp[i]>=97&&exp[i]<=122||exp[i]>=48&&exp[i]<58)
        {
            //printf("Input symbol: %c\n",exp[i]);
            //printf("%c",exp[i]);
            op[index]=exp[i];
            index++;
            //printf("Character added to output is: %c\n",exp[i]);
        }
        else
        {
            if(top<0)
            push(exp[i]);
            else
            {
                if(exp[i]=='(')
                push(exp[i]);
                else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'||exp[i]=='%'||exp[i]=='^')
                {
                    //printf("Next Char: %c\n",exp[i]);
                    int res1=check(exp[i]);
                    int res2=check(stack[top]);
                    if(res1>res2)
                    push(exp[i]);
                    else
                    {
                        do
                        {
                            ch=pop();
                            //printf("%c",&ch);
                            op[index]=ch;
                            index++;
                            //printf("Character added to output is: %c\n",ch);
                            res1=check(exp[i]);
                            res2=check(stack[top]);
                        }while (res1<=res2);
                        push(exp[i]);
                    }
                }
                else
                {
                    ch=pop();
                    while(ch!='(')
                    {
                        //printf("%c",ch);
                        op[index]=ch;
                        index++;
                        //printf("Character added to output is: %c\n",ch);
                        ch=pop();
                    }
                }
            }
        }
    }
    printf("Postfix Notation: ");
    op[index]='\0';
    printf("%s",op);
}
void push(char c)
{
    if(top==99)
    printf("Overflow\n");
    else
    {
        top++;
        stack[top]=c;
        //printf("Element Pushed into stack is: %c\n",c);
    }
}
char pop()
{
    if(top<0)
    printf("Underflow\n");
    else
    {
        int temp=top;
        top--;
        //printf("Element popped from stack is: %c\n",stack[temp]);
        return(stack[temp]);
    }
}
int check(char c)
{
    if(c=='('||c==')')
    return(0);
    if(c=='+'||c=='-')
    return(1);
    if(c=='*'||c=='/'||c=='%')
    return(2);
    if(c=='^')
    return(3);
}