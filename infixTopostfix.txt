#include<stdio.h>
#include<stdlib.h>
#define MAX 10
char infix[MAX],postfix[MAX],stk[MAX];
int top=-1;
int pop()
{
	char c;
	if(top==-1)
	    {		
		printf("\nStack is Empty");
		exit(1);
	    }
	else{
		c=stk[top];
		top--;
	    }
	return c;
}

void push(char symbol)
{
	if(top==MAX-1)
	{
		printf("\nStack is full");
		exit(1);
	}else{
		top++;
		stk[top]=symbol;
	     }	
}

int empty()
{
	if(top==-1)
		return 1;
	else 
		return 0;
}

int priority(char symbol)
{
	switch(symbol)
	{
		case '(' : return 0;
		case '+' :
		case '-' : return 1;
		case '*' :
		case '/' : return 2;
		case '^' : return 3;
		default  : return 0;
	}
}

void main()
{
	int i,p=0;
	char symbol,next;
	system("clear");
	printf("\nEnter Infix Expression :");
	scanf("%s",infix);
	for(i=0;infix[i]!='\0';i++)
	{
		symbol=infix[i];
		switch(symbol)
		{
			case '(' : push(symbol); break;
			case ')' : while((next=pop())!='(')
					{
						postfix[p]=next;
						p++;
					}
				   break;
			case '+' :
			case '-' :
			case '*' :
			case '/' :
			case '^' : while(!empty() && priority(stk[top]>priority(symbol)))
					{
						postfix[p]=pop();
						p++;
					}
					push(symbol);
					break;
			default : postfix[p]=symbol;
				  p++;
		}	
	}
	while(!empty())
	{
		postfix[p]=pop();
		p++;
	}
	postfix[p]='\0';
	printf("\nPostfix Expression is : %s",postfix);
}
