#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int front=-1,rear=-1,cqueue[MAX];

int empty()
{
	if(front==-1&&rear==-1)
		return 1;
	else return 0;
}

int full()
{
	if(front==0 && rear == MAX-1 || front==rear+1)
		return 1;
	else return 0;
}


void insert()
{
	if(full())
		printf("\nQueue is Full");
	else{
		if(front==-1)
			front=0;
		if(rear==MAX-1)
			rear=0;
		else{
			rear++;
			printf("\nEnter the Element : ");
			scanf("%d",&cqueue[rear]);
		}

	}
}

void delete()
{
	if(empty())
		printf("\nQueue is Empty ");
	else {
		printf("\nThe Deleted element is : %d",cqueue[front]);
		
		if(front==rear)
			front=rear=-1;
		else
			if(front==MAX-1)
				front=0;
			else 
				front++;
	}
}

void display()
{
	int i;
	if(empty())
		printf("\nQueue is Empty");
	else {
		printf("\nQueue is : \n");
		if(front<=rear)
			for(i=front;i<=rear;i++)
			{
				printf("%d ",cqueue[i]);
			}
		else{
			for(i=front;i<MAX;i++)
				printf("%d ",cqueue[i]);
			for(i=0;i<=rear;i++)
				printf("%d ",cqueue[i]);
		}
	}
}


void main()
{
	int choice,i;
	while(1)
	{	
		system("clear");
	        printf("\n 1.Insert the element");
		printf("\n 2.Delete the element");
		printf("\n 3.Display the queue");
		printf("\n 4. Exit");
		printf("\n 5.Enter the choice ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:	
				display();
				break;
			case 4: exit(0);
			default : printf("\nInvalid Choice");
		}
	}
}

