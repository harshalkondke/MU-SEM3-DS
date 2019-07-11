#include<stdio.h>
void main()
{
	int i,n,first,last,middle,search,array[100];
	printf("\nEnter no of element");
	scanf("%d",&n);
	printf("\nEnter %d Integers :\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&array[i]);
	printf("\nEnter the value to find : ");
	scanf("%d",&search);
	first=0;
	last=n-1;
	middle = (first+last)/2;
	while(first<=last)
	{
		if(array[middle] < search)
			first = middle+1;
		else if(array[middle]==search)\
			{
				printf("\n%d found at location %d\n",search,middle+1);
				break;
			}
		else 
			last = middle - 1 ;
		middle = (first + last)/2;
	}
	if(first>last)
		printf("\nNot Found : %d isn't present in the list",search);
}
