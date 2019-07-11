#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int stk[MAX],top=-1;

int pop()
{
	int n;
	if(top==-1)
	{
		printf("\nStack is Empty");
		exit(1);
	}else{
		n=stk[top];
		top--;
	}
	return n;
}

void push(int x)
{
	if(top==MAX-1)
	{
		printf("\nStack is Full");
		exit(1);
	}else{
		top++;
		stk[top]=x;
	}
}



void main()
{
	char postfix[MAX];
	int i,op1,op2,result;
	printf("\nEnter Postfix Expression : ");
	scanf("%s",postfix);
	for(i=0;postfix[i]!='\0';i++)
	{
		//if there is a no in expression then push it
		if(postfix[i]>='0' && postfix[i]<='9')
			push(postfix[i]-'0');   //here we sub 0 becuse postfix is array of char and we are dealing with integers... for more info google it ;) 
		else{
			op2=pop();
			op1=pop();
			switch(postfix[i])
			{	
				case '+' : result = op1+op2; break;
				case '-' : result = op1-op2; break;
				case '*' : result = op1*op2; break;
				case '/' : result = op1/op2; break;
				case '^' : result = op1^op2; break;	
			}
			push(result);
		    }//end of else
		
	}//end of for

	result=pop();
	printf("\nThe Result is : %d",result);	
} 

