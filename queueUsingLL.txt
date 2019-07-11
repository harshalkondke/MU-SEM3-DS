#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data ;
	struct node *next;
}Q;
Q *rear=NULL,*front=NULL;
void insert(),delete(),display();
int empty();

void main()
{
	int choice;
	system("clear");
	while(1)
	{
		printf("\n 1.Insert Element ");
		printf("\n 2.Delete Element ");
		printf("\n 3.Display Element ");
		printf("\n 4.Exit ");
		printf("\n Enter your Choice ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insert();
				break;
			case 2:delete();
				break;
			case 3:display();
				break;
			case 4:exit(0);
			default:printf("\n Invalid Input ");
		}
	}
}

void insert()
{
	Q *newnode;
	newnode=(Q*)malloc(sizeof(Q));
	printf("\n Enter the element ");
	scanf("%d",&newnode->data);
	if(front==NULL)
	{
		front=newnode;
		rear=newnode;
	}
	else
	{
		rear->next=newnode;
		rear=newnode;
	}
}

int empty()
{
	if(front==NULL)
		return 1;
	else
		return 0;
}

void display()
{
	Q *temp;
	if(empty())
		printf("\n Queue is empty ");
	else
	{
		temp=front;
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}

void delete()
{
	if(empty())
		printf("\n Queue is empty ");
	else
	{
		Q *temp;
		printf("\n Element delete is ");
		printf("%d",front->data);
		temp=front;
		front=front->next;
		free(temp);
	}
}


