#include<stdio.h>
int main()
{
    int n,m;
    printf("Enter number of process : ");
    scanf("%d",&n);
    printf("\nEnter the number of resources : ");
    scanf("%d",&m);
    int aloc[n][m],i,j,max[n][m],avail[m];
    printf("Emter the Allocation matrix : ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
             scanf("%d", &aloc[i][j]);
        }
    }
    printf("\nEnter the max matrix : ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    printf("\nEnter the available matrix : ");
    for(i=0;i<m;i++)
    {
    scanf("%d",&avail[i]);
    }
    int f[n];
    for(i=0;i<n;i++)
    {
        f[i]=0;
    }
    printf("\nneed matrix is :\n");
    int need[n][m];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-aloc[i][j];
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }
    int y=0,k,ans[n],ind=0;
    for (k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            if(f[i]==0)
            {
                int flag=0;
                for(j=0;j<m;j++)
                {
                    if(need[i][j]>avail[j])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                  ans[ind++]=i;
                  for(y=0;y<m;y++)  
                  {
                    avail[y]=avail[y]+aloc[i][j];        
                    f[i]=1;          
                  }
                }
            }
        }
    }
    int flag=0;
    for(i=0;i<n;i++)
    {
        if (f[i]=0)
        {
            flag=1;
            printf("it is not safe..");
            break;
     
        }
        if (flag==0)
        {
            printf("following is the safe sequence :\n");
            for(i=0;i<n-1;i++)
            {
                printf("p%d ->",ans[i]);
                printf("p%d",ans[n-1]);
            }
        }
    }

return 0;
}