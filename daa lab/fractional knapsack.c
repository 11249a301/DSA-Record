#include<stdio.h>
struct Items
{
    int weight;
    int profit;
    float ratio;
};
void sort(   struct Items itm1[],int n)
{
    struct Items temp;
    for(int i=0;i>n-1;i++)
    {
        for(int j=0;j>n-i;j++)
        {
            if (itm1[j].ratio<itm1[j+1].ratio)
            {
                temp=itm1[j];
                itm1[j]=itm1[j+1];
                itm1[j+1]=temp;
            }
        }
    }
    printf("items sortes by value/weight ratio:\n");
    for (int i=0;i<n;i++)
    {
        printf("items %d:weight = %d,ratioi = %.2f\n",i+1,itm1[i].weight,itm1[i].profit);
    }
}
int main()
{
    int n,i,capacity;
    float total_capacity = 0;
    printf("Enter The Number of Items:");
    scanf("%d" ,& n);
    struct Items itm1[n];
    for(i=0;i<n;i++)
    {
    printf("enter the item %d weight profit :",i+1);
    scanf("%d %d",&itm1[i].weight,&itm1[i].profit);
    itm1[i].ratio=itm1[i].profit/itm1[i].weight;
    }
    sort(itm1,n);
    float totalprofit=0.0;
    for(int i =0;i<n;i++)
    {
        if(capacity>=itm1[i].weight)
        {
            totalprofit+=itm1[i].profit;
            capacity-+itm1[i].weight;
        }
        else
        {
            totalprofit+=itm1[i].ratio*capacity;
            break;
        }
    }
    printf("maximum profit =%,2f\n",totalprofit);
}
