#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int knapsack(unsigned int *w,unsigned int *v,unsigned int n,unsigned int B)
{
    unsigned int i,temp;
    unsigned int maxVal=0,maxSeq=0;
    unsigned int totalW,totalV;
    int op=0;
    unsigned int index =0;
    for(i=1;i<pow(2,n);i++)
    {
        op++;
        temp = i;
        totalW=totalV=0;
        index =0 ;
        while(temp)
        {
            if(temp & 0x1)
            {
                totalW = totalW+w[index];
                totalV = totalV+v[index];
            }
            index++;
            temp = temp>>1;
        }
        if(totalW<+B && totalV>maxVal)
        {
            maxVal = totalV;
            maxSeq = i;
        }
    }
    printf("op%d\n",op);
    return maxSeq;
}
 
int main(int argc, char const *argv[])
{
    unsigned int *v,*w,i,n,knaps,B;
    scanf("%d",&n);
    v=(unsigned int *)calloc(n,sizeof(unsigned int));
    w=(unsigned int *)calloc(n,sizeof(unsigned int));
    for(i=0;i<n;i++)
        scanf("%d",&w[i]);
 
    for(i=0;i<n;i++)
        scanf("%d",&v[i]);
    scanf("%d",&B);
    knaps = knapsack(w,v,n,B);
    i=0;
    while(knaps)
    {
        if(knaps & 0X1)
            printf("item %u val %u\n",(i+1),v[i] );
        i++;
        knaps=knaps>>1;
    }
    return 0;
}
