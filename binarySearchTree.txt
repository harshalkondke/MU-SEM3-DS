#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *left,*right;
}BST;
BST *parent;
void insert(BST*,BST*),delete(BST*),inorder(BST*);
BST *search(BST*,int);
void main()
{
	int choice,key;
	BST *root,*newnode,*temp;
	root=NULL;
	system("clear");
	while(1)
	{
		printf("\n 1. Insert element");
		printf("\n 2. Search element");
		printf("\n 3. Delete a element");
		printf("\n 4. Display a element");
		printf("\n 5. Exit");
		printf("\n Enter choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: newnode=(BST*)malloc(sizeof(BST));
			        printf("\n Enter element");
			        scanf("%d",&newnode->data);
					newnode->left=NULL;
					newnode->right=NULL;
					if(root==NULL)
			   			root=newnode;
					else
					insert(root,newnode);
					break;
			
			case 2: printf("\n Enter element to be searched");
					scanf("%d",&key);
					temp=search(root,key);
					if(temp==NULL)
					printf("\n Element not found");
					else
					printf("\n Element found");
					break;
			case 3: delete(root);
					break;
			case 4: inorder(root);
					break;
			case 5: exit(0);
			default : printf("\n Invalid choice");						
			
		}
	}
}
void insert(BST *root,BST *newnode)
{
	if((newnode->data)<(root->data))
	{
		if(root->left==NULL)
		   root->left=newnode;
		else
		   insert(root->left,newnode);
	}
	else
	{
		if(root->right==NULL)
		   root->right=newnode;
		else
		   insert(root->right,newnode);
	}
}
BST *search(BST *root,int key)
{
	BST *temp;
	temp=root;
	while(temp!=NULL)
	{
		if(key==temp->data)
		   return temp;
		parent=temp;
		if(key<(temp->data))
		  temp=temp->left;
		else
	 	  temp=temp->right;	   
	}
	return NULL;
}
 void inorder(BST *temp)
 {
	
 	if(temp!=NULL)
 	{
 		inorder(temp->left);
 		printf("\n %d",temp->data);
 		inorder(temp->right);
	 }
 }
void delete(BST *root)
{
	BST *temp,*succ;
	int key;
	printf("\n Enter element to be deleted");
	scanf("%d",&key);
	temp=search(root,key);
	if(temp==NULL) 
	printf("\n Element not found");
	else
	{
		/* deleting a node having 2 children */
		if(temp->left!=NULL && temp->right!=NULL)
		{
			parent = temp;
			succ = temp->right;
			while(succ->left!=NULL)
			{
				parent=succ;
				succ=succ->left;
			}
			temp->data=succ->data;
			temp=succ;
		}
	}
	/* deleting a node having no children */
	if(temp->left==NULL && temp->right==NULL)
	{
		if(parent->left==temp)
		   parent->left=NULL;
		else
		   parent->right=NULL;   
	}
	/* deleting a node having only lefft child */
	if((temp->left!=NULL)&&(temp->right==NULL))
	{
		if(parent->left==temp)
		   parent->left=temp->left;
		else
		   parent->right=temp->left;   
	}
		/* deleting a node having only right child */
	if(temp->left==NULL && temp->right!=NULL)
	{
		if(parent->left==temp)
		   parent->left=temp->right;
		else
		   parent->right=temp->right;   
	}
}

