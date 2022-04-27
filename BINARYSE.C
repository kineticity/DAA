#include <stdio.h>
#include<conio.h>


int binary(int arr[],int start,int end,int key)
{
    if(end>=start)
    {
        int mid=(start+end)/2;
        if(arr[mid]==key)
        {
            return mid; //base case
        }
        else if(arr[mid]>key)
        {
            return binary(arr,start,mid-1,key); //search in first half of arr
        }
        else if(arr[mid]<key)
        {
            return binary(arr,mid+1,end,key); //search in second half of arr
        }
        
    }
    return -1; //key not in array
}
int main()
{
    int n,i,key,o,arr[20];
    clrscr();
    printf("Enter no. of elements: ");
    scanf("%d",&n);

    printf("\nENTER SORTED ARRAY\n");
    for(i=0;i<n;i++)
    {
        printf("Enter element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\nARRAY ENTERED IS ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\nEnter value you want to search:");
    scanf("%d",&key);
    o=binary(arr,0,n,key);
    if(o==-1)
    {
        printf("\nThe value entered not in the array");
    }
    else
    {
        printf("\nThe value enetered is at index position %d",o);
    }
    return 0;
}


