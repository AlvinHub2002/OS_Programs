#include<stdio.h>
int main()
{
    int i,nop,ct=0,quantum,counter;
    int totwt=0,tottat=0,arrival[10],bt[10],rt[10];
    printf("enter total number of processes : ");
    scanf("%d",&nop);
    counter=nop;
    printf("\nenter arrival and burst time of : ");
    for(i=0;i<nop;i++)
    {
        printf("\narrival time of  p[%d] : ",i+1);
        scanf("%d",&arrival[i]);
        printf("\nburst time of p[%d] : ",i+1);
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
    }
    printf("\nenter the time quantum : ");
    scanf("%d",&quantum);
    printf("\nprocess\tburst time\tturnaround time\twaiting time");
    for(ct=0,i=0;counter!=0;)
    {
        if(rt[i]<quantum && rt[i]>0)
        {
            ct=ct+rt[i];
            rt[i]=0;
            counter--;
            int tat=ct-arrival[i];
            int wt=tat-bt[i];
            printf("\n%d\t\t%d\t\t%d\t\t%d",i+1,bt[i],tat,wt);

        }
        else if(rt[i]>0)
        {
            rt[i]=rt[i]-quantum;
            ct=ct+quantum;
        }
        if(i==nop-1)
        {
            i=0;
        }
        else if (arrival[i+1]<=ct)
        {
            i++;
        }
        else{
            i=0;
        }
    }
}