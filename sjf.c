#include<stdio.h>
int main()
{
    int bt[20],n,i;
    printf("enter the number of processes : ");
    scanf("%d",&n);
    int p[n],wt[n],tat[n];
    printf("\nenter the burst time of :");
    for(i=0;i<n;i++)
    {
        printf("p[%d] : ",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }
    int j,pos,temp;
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
            {
                pos=j;
            }
        }
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    wt[0]=0;
    int totwt=0,tottat=0;
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
        {
            wt[i]=wt[i]+bt[j];
            totwt=totwt+wt[i];
        }
    }
    for(i=0;i<n;i++)
    {
        tat[i]=wt[i]+bt[i];
        tottat=tottat+tat[i];
    }
    printf("\nprocess\tburst time\twaiting time\tturnaround time\n");
    for(i=0;i<n;i++)
    {
    printf("\n%d\t\t%d\t\t%d\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
    float avgwt=(float)totwt/n;
    float avgtat=(float)tottat/n;
    printf("\naverage waiting time is : %f",avgwt);
    printf("\naverage turnatound time is : %f", avgtat);
    return 0;
}