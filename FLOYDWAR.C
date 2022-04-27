#include<stdio.h>
#define infinity 999
int i,j,k,n,dist[10][10];
void floyd()
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
                dist[i][j]=0;
            }
            else
            {
                if(dist[i][j]==0)
                {
                    dist[i][j]=infinity;
                }
            }
        }
    }
    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(dist[i][k]+dist[k][j]<dist[i][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
    
}

int main()
{
    int i,j;
    printf("Enter no. of vertices:");
    scanf("%d",&n);
    printf("\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&dist[i][j]);
    floyd();
    printf("\nOutput Shortest Distance Matrix");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",dist[i][j])
        }
        printf("\n");
    }
    return 0;
}