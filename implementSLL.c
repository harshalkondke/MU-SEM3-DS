#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}list;
list *head,*temp;
list *search(int);
void insert(),delete(),reverse(),count(),display();
int empty();
void main()
{
	int choice,n;
	system("clear");
	head=(list*)malloc(sizeof(list));
	head->next=NULL;
	while(1)
	 {
	   printf("\n 1.Insert an element ");
	   printf("\n 2.Delete an element ");
	   printf("\n 3.Search an element ");
	   printf("\n 4.Count an element ");
	   printf("\n 5.Reverse the list ");
	   printf("\n 6.Display the list ");
	   printf("\n 7.Exit ");
	   printf("\n Enter the choice ");
	   scanf("%d",&choice);

	   switch(choice)
	    {
		case 1: insert();
		        break;
      		case 2: if(!empty())
			 delete();
			 break;
		case 3: if(!empty())
			 {
			   printf("\n Enter the element to be searched ");
			   scanf("%d",&n);
			   temp=search(n);
			   if(temp==NULL)
				printf("\n Element not found ");
			   else
				printf("\n Element found ");
			 }
			 break;
		case 4: if(!empty())
			count();
			break;
		case 5: if(!empty())
			reverse();
			break;
		case 6: if(!empty())
			display();
			break;
		case 7: exit(0);
		default:printf("\n Invalid input ");
	    }
	 }
}

list *search(int n)
{
	temp=head->next;
	while(temp!=NULL)
	 {
	   if(temp->data==n)
		break;
	   temp=temp->next;
	 }
	 return(temp);
}

void insert()
{
	int option,n;
	list *newnode;
	newnode=(list*)malloc(sizeof(list));
	newnode->next=NULL;
	printf("\n Enter the element ");
	scanf("%d",&newnode->data);
	if(head->next==NULL)
	  head->next=newnode;
	else
	 {
	   printf("\n 1.Insert at beginning ");
	   printf("\n 2.Insert at middle ");
	   printf("\n 3.Insert at end ");
	   printf("\n Enter your choice ");
	   scanf("%d",&option);
	   switch(option)
	     {
		case 1: newnode->next=head->next;
			newnode->next=newnode;
			break;
		case 2: printf("\n Insert after which element ");
			scanf("%d",&n);
			temp=search(n);
			if(temp==NULL)
			  printf(" Not found ");
			else
			  {
			    newnode->next=temp->next;
			    temp->next=newnode;
			  }
			break;
		case 3: temp=head->next;
			while(temp->next!=NULL)
			  temp=temp->next;
			temp->next=newnode;
			break;
		default:printf("\n Invalid input ");
	     }
	  }
}

void delete()
{
	int n;
	list *prev;
	printf("\n Enter element to be deleted ");
	scanf("%d",&n);
	temp=search(n);
	if(temp==NULL)
	  printf("\n Element not found ");
	else
	 {
	    prev=head;
	    while(prev->next!=temp) 
	      	prev=prev->next;
	    prev->next=temp->next;
	    free(temp);
	 }
}
	
void count()
{
	int counter=0;
	temp=head->next;
	while(temp!=NULL)
	 {
	   counter++;
	   temp=temp->next;
	 }
	printf("\n Number of elements are %d ",counter);
}

void display()
{
	temp=head->next;
	printf("\n Elements are ");
	while(temp!=NULL)
	 {
	   printf("%d ",temp->data);
	   temp=temp->next;
	 }
}

void reverse()
{
	list *temp1,*temp2,*temp3;
	temp1=head;
	temp2=NULL;
	while(temp1!=NULL)
	 {
	    temp3=temp2;
	    temp2=temp1;
	    temp=temp1->next;
	    temp->next=temp3;
	 }
	 head->next=temp2;
	 printf("\n List is reversed ");
}

int empty()
{
	if(head->next==NULL)
		return 1;
	else
		return 0;
}
