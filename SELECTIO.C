#include <stdio.h>

int main()
{
    int arr[20],temp;
    int i,j,smallestind,n,k,passes=0,comp=0;
    printf("enter n: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
	printf("enter element %d : ",i+1);
	scanf("%d",&arr[i]);
    }
    printf("\nARRAY ENTERED IS ");
    for(i=0;i<n;i++)
	printf("%d ",arr[i]);
    for(i=0;i<n-1;i++)
    {
	smallestind=i;
	for(j=i+1;j<n;j++)
	{
	    //printf("%d<%d  ",arr[j],arr[smallestind]);
	    if(arr[j]<arr[smallestind])
		smallestind=j;
	    comp+=1;
	}
	passes+=1;
	temp=arr[smallestind];
        arr[smallestind]=arr[i];
        arr[i]=temp;
        printf("\npass %d \n",i+1);
        for(k=0;k<n;k++)
            printf("%d ",arr[k]);
        printf("\n");
    }
    printf("\nFINAL SORTED SEQUENCE: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    printf("\nNumber of passes %d",passes);

    printf("\nNumber of comparisons %d",comp);
    return 0;
}




