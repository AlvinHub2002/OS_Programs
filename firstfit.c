#include<stdio.h>
void firstfit(int bs[], int ps[], int nb, int np)
{
   int i,j;
   int allocation[np];
   for(i=0;i<np;i++)
   {
    allocation[i]=-1;
   }
   for(i=0;i<np;i++)
   {
    for(j=0;j<nb;j++)
    {
        if(bs[j]>=ps[i])
        {
            allocation[i]=j;
            bs[j]=bs[j]-ps[i];
            break;
        }
    }

   }
   printf("\nprocess no.\tprocess size\tblock no");
   for(i=0;i<np;i++)
   {
    printf("\n%d\t\t%d\t\t",i+1,ps[i]);
    if(allocation[i]!=-1)
    {
        printf("%d",allocation[i]+1);
    }
    else{
        printf("not allocated");
    }
   }
}
int main()
{
    int nb,np,i;
    printf("enter the number of blocks : ");
    scanf("%d",&nb);
    printf("enter the size of :\n");
    int bs[nb];
    for(i=0;i<nb;i++)
    {
     printf("block %d: ",i+1);
     scanf("%d",&bs[i]);
    }
     printf("enter the number of processes : ");
    scanf("%d",&np);
    printf("enter the size of :\n");
    int ps[np];
    for(i=0;i<np;i++)
    {
     printf("process %d: ",i+1);
     scanf("%d",&ps[i]);
    }
    firstfit(bs,ps,nb,np);
    return 0;

}