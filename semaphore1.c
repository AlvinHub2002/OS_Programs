#include<stdio.h>
#include<stdlib.h>
int mutex =1;
int full=0;
int empty=10;
int x=0;
void wait(int *s)
{
 while (s<=0);
 (*s)--;
}
void signal(int *s)
{
    (*s)++;
}
void producer()
{
    wait(&empty);
    wait(&mutex);
    x++;
    printf("\n Producer produces item : %d",x);
    signal(&full);
    signal(&mutex);
}
void consumer()
{
   wait(&full);
   wait(&mutex);
   printf("\nConsumer consumes item : %d",x);
   x--;
   signal(&empty);
   signal(&mutex);
}
int main()
{
    int n;
    printf("\n1.PRODUCER\n2.CONSUMER\n3.EXIT");
    do{
        printf("\nEnter your choice : ");
        scanf("%d",&n);
        switch(n)
        {
            case 1 : if((mutex==1)&&(empty!=0))
                     {
                        producer();
                     }
                     else{
                        printf("Buffer is full..");
                     }
                break;
            case 2 : if((mutex==1)&&(full!=0))
                      {
                        consumer();
                      }
                    else{
                        printf("Buffer is empty..");
                    }
                break;
            case 3 :
               exit(0);
               break;
            default : printf("wrong choice..");
            break;
        }

    }
    while(n!=3);
    return 0;
}