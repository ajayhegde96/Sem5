#include <stdio.h>
#include <stdlib.h>
 
int sum(int arr[],int n)
{
    int sum =0;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    return sum;
}
 
void display(int arr[] ,int c)
{
    int j;
    for(j=0;j<c;j++)
        if(arr[j])
            printf("%d ",arr[j]);
    printf("\n");
}
 
int main()
{
    //int set[]={1,2,3,4,5,9};
    int set[] = {1,2,3,5,4,9};
    int size = sizeof(set)/sizeof(int);
    int psize = 1<<size;
    int i,j;
    int s = sum(set,size);
    if(s%2!=0)
        printf("Partition not possible\n");
    else
    {
        int part_sum = s/2;
        int pow_set[psize][size];

 		
        for(i=0;i<psize;i++)
        {
            for(j=0;j<size;j++)
            {
               pow_set[i][j]=0;
            }
            
        }
        for(i=0;i<psize;i++)
        {
            for(j=0;j<size;j++)
            {
                if(i & (1<<j))
                    pow_set[i][j] = set[j];
            }
            int d = psize-i-1;
            if(sum(pow_set[d],size)==part_sum)
            {
                printf("SUM = %d\n",sum(pow_set[d],size));
                printf("SET 1\n");
                display(pow_set[d],size);
                printf("SET 2\n");
                display(pow_set[i],size);
            }
        }
    }
    return 0;
}
