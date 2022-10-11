#include<stdio.h>
int main()
{
    int i,j,k,min,rs[20],m[10],count[10],flag[25],n,f,pf=0,next=0;
    printf("enter the length of string : ");
    scanf("%d",&n);
    printf("\nenter  the reference string : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&rs[i]);
        flag[i]=0;

    }
    printf("enter the number of frames : ");
    scanf("%d",&f);
    for(i=0;i<f;i++)
    {
        m[i]=-1;
        count[i]=0;
    }
    for(i=0;i<n;i++)
    {
        for(k=0;k<f;k++)
        {
            if(m[k]==rs[i])
            {
                flag[i]=1;
                count[j]=next;
                next++;
            }
        }
        if(flag[i]==0)
        {
            if(i<f)
            {
                m[i]=rs[i];
                count[i]=next;
                next++;
            }
            else{
                min=0;
                for(j=1;j<f;j++)
                if(count[min]>count[j])
                min=j;
                m[min]=rs[i];
                count[min]=next;
                next++;
            }
            pf++;
        }
    }
    printf("\n0page faults : %d",pf);
   return 0;
}