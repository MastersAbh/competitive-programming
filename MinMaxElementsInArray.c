#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,max,min;
	
	printf("Enter array size:");
	scanf("%d",&n);
	
	int* a=(int*)malloc(n*sizeof(int));
	
	printf("Enter array elements :\n",n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}


	
	min=a[0];
	max=a[0];
	
	for(int i=1;i<n;i++)
	{
		if(a[i]<min)
		min=a[i];
		
		if(a[i]>max)
		max=a[i];
		
	}
	
	printf("Minimum array element: %d",min);
	printf("\nMaximum array element: %d",max);
	
	return 0;
	
	
}
