#include<stdio.h>
struct item 
{
int weight,profit;     
float ratio;
};
void sort(struct item items[],int n){
    struct item temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if (items[j].ratio<items[j+1].ratio){
                temp=items[j];
                items[j]=items[j+1];
                items[j+1]=temp;
            }
        }
    }
}
int main(){
int c,n;
printf("enter capacity:");
scanf("%d",&c);
printf("enter the number of items:");
scanf("%d",&n);
struct item itm[n];
for(int i=0;i<n;i++)
{
    printf("enter item %d weight profit:",i+1);
    scanf("%d" "%d",&itm[i].weight,&itm[i].profit);
    itm [i].ratio=(itm[i].profit)/(itm[i].weight);
}
sort(itm,n);
float totalprofit=0.0;
for(int i=0;i<n;i++){
    if(c>=itm[i].weight){
        totalprofit +=itm[i].profit;
        c-=itm[i].weight;}
        else{
            totalprofit +=itm[i].ratio*c;
            break;
        }
}
printf("maximu8m profit=%.2f\n",totalprofit);

return 0;
}
