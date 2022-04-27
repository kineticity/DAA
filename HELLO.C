#include <stdio.h>
int main()
{
    float limit_weight;
    int greatestind;
    int n;
    float total_weight=0,total_profit=0;
    float x[10],w[10],p[10],pw[10];
    int i,j;
    float temp,temp1,temp2;
    float knapsack[100];
    printf("Enter n:");
    scanf("%d",&n);


    printf("Enter limit weight : ");
    scanf("%f",&limit_weight);

    for(i=0;i<n;i++)
    {
	printf("Enter profit and weight of object %d : ",i+1);
	scanf("%f",&p[i]);
	scanf("%f",&w[i]);
	pw[i]=p[i]/w[i];
    }

    printf("RATIO ARRAY : ");
    for(i=0;i<n;i++)
    {
	printf("%f ",pw[i]);
    }
    printf("\n");
    for(i=0;i<n-1;i++)
    {
	greatestind=i;
	for(j=i+1;j<n;j++)
	{
	    if(pw[j]>pw[greatestind])
		greatestind=j;
	}
	temp=pw[greatestind];
	pw[greatestind]=pw[i];
	pw[i]=temp;

	temp1=p[greatestind];
	p[greatestind]=p[i];
	p[i]=temp1;
	temp2=w[greatestind];
	w[greatestind]=w[i];
	w[i]=temp2;
    }
    printf("Sorted ratio array : ");
    for(i=0;i<n;i++)
	printf("%f ",pw[i]);
    printf("\n");
    /*
    printf("Sorted weight array : ");
    for(int i=0;i<n;i++)
	printf("%f ",w[i]);
    printf("\n");
    printf("Sorted profit array : ");
    for(int i=0;i<n;i++)
	printf("%f ",p[i]);
    printf("\n");*/
    for(i=0;i<n;i++)
    {
	x[i]=0;
    }
    for(i=0;i<n;i++)
    {
	if(total_weight+w[i]<=limit_weight)
	{
	    x[i]=1;
	    total_weight=total_weight+w[i];
	}
	else
	{
	    x[i]=(limit_weight-total_weight)/w[i];
	    total_weight=limit_weight;
	    break;
	}
    }
    printf("RATIO OF OBJECTS ADDED TO KNAPSACK:\n");
    for(i=0;i<n;i++)
    {
	printf("%f  ",x[i]);
	total_profit+=x[i]*p[i];
    }
    printf("\nTOTAL PROFIT=%f",total_profit);
return 0;
}
