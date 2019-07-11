#include<stdio.h>
#include<stdlib.h>

int partition(int a[],int firstno,int lastno)
{
	int v,i,j,temp;
	v=a[firstno];
	i=firstno;
	j=lastno+1;
	do{
		do
			i++;
		while(a[i]<v && i<= lastno);
		
		do
			j--;
		while(v<a[j]);
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}while(i<j);
	a[firstno]=a[j];
	a[j]=v;
	return j;
}

void quickSort(int a[],int firstno,int lastno)
{
	int j;
	if(firstno < lastno)
	{
		j=partition(a,firstno,lastno);
		quickSort(a,firstno,j-1);
		quickSort(a,j+1,lastno);
	}
}

void main()
{
	int a[30],n,i;
	printf("\nEnter no of element : ");
	scanf("%d",&n);
	printf("\nEnter array element : \n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	quickSort(a,0,n-1);
	printf("\nSorted elements are : \n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
