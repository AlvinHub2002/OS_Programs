#include<stdio.h>
#include<stdlib.h>
int main(){
    int i,n,THM=0,RQ[30],initial,size,move,temp=0,j;
    printf("Enter the number of request: ");
    scanf("%d",&n);
    printf("Enter the request sequence: ");
    for(i=0;i<n;i++){
        scanf("%d",&RQ[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d",&initial);
    printf("Enter the disk size: ");
    scanf("%d",&size);
    printf("Enter the direction[1.high][0.low]: ");
    scanf("%d",&move);
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(RQ[j]>RQ[j+1]){
                temp = RQ[j];
                RQ[j] = RQ[j+1];
                RQ[j+1] = temp;
            }
        }
    }
    int index;
    for(i=0;i<n;i++){
        if(initial<RQ[i]){
            index=i;
            break;
        }
    }
    if(move==1){
        for(i=index;i<n;i++){
            THM=THM+abs(RQ[i]-initial);
            initial=RQ[i];
        }
        THM=THM+abs(size-RQ[i-1]-1);
        initial=size-1;
        for(i=index-1;i>=0;i--){
            THM=THM+abs(RQ[i]-initial);
            initial=RQ[i];
        }
    }
    else{
        for(i=index-1;i>=0;i--){
            THM=THM+abs(RQ[i]-initial);
            initial=RQ[i];
        }
        THM=THM+abs(RQ[i+1]-0);
        initial=0;
        for(i=index;i<n;i++){
            THM=THM+abs(RQ[i]-initial);
            initial=RQ[i];
        }
    }
    printf("Total Head Moment: %d",THM);
    return 0;
}