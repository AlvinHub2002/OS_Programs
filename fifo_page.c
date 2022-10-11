#include<stdio.h>
int main()
{
    int i,j,k,f,pf=0,count=0,rs[20],m[10],n;
    printf("enter the length of reference string : ");
    scanf("%d",&n);
    printf("\nenter the reference string : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&rs[i]);
    }
    printf("enter the number of frames : ");
    scanf("%d",&f);
    for(i=0;i<f;i++)
    {
        m[i]=-1;
    }
    for(i=0;i<n;i++)
    {
        for(k=0;k<f;k++)
        {
            if(m[k]==rs[i])
            {
                break;
            }
        }
        if(k==f)
        {
            m[count++]=rs[i];
            pf++;
        }
        // for(j=0;j<f;j++)
        // {
        //     printf("\t%d",m[j]);
        // }
        // if(k==f)
        // {
        //     printf("\tPF no. %d",pf);
        // }
        // printf("\n");
        if(count==f)
          {
                count=0;
           }    
    }
    printf("\n the number of page faults is : %d",pf);
return 0;
}