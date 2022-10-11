#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("enter the number of requests : ");
    scanf("%d",&n);
    int r[n],i,initial;
    printf("\nenter the request sequence : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&r[i]);
    }
    printf("\nenter the head position : ");
    scanf("%d",&initial);
    int totalheadmoment=0;
    for(i=0;i<n;i++)
    {
        totalheadmoment=totalheadmoment+abs(initial-r[i]);
        initial=r[i];
    }
    printf("\ntotal head moment is : %d",totalheadmoment);
    printf("\nseek sequence is : ");
    for(i=0;i<n;i++)
    {
      printf("\n%d",r[i]);
    }

}