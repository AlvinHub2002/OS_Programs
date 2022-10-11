#include<stdio.h>
void bestfit(int bs[], int ps[], int nb, int np)
{
   int i,j,minblock,flag,minindex;
    printf("\nprocess no.\tprocess size\tblock no");
   for(i=0;i<np;i++)
   {
    flag=0;
    for(j=0;j<nb;j++)
    {
        if(bs[j]>=ps[i])
        {
           if(flag==0)
           {
            minblock=bs[j];
            minindex=j;
            flag++;
           }
           else if(bs[j]<minblock)
           {
            minblock=bs[j];
            minindex=j;
           }
        }
    }
    bs[minindex]=bs[minindex]-ps[i];
    printf("\n%d\t\t%d\t\t%d",i+1,ps[i],minindex+1);
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
    bestfit(bs,ps,nb,np);
    return 0;

}  