#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main()
{
    srand((unsigned)time(0));
    int count=5;
    int n=rand()%99+1,in;
    while(count>0)
    {
        printf("请输入你猜的数:");
        fflush(stdin);
        scanf("%d",&in);
        if(in==n)
        {
            printf("\n恭喜你猜对了!\n");
            getchar();
            exit(0);
        }
        else if(in>n)
        {
            printf("\n太大");
            getchar(); 
        }
        else if(in<n)
        {
            printf("\n太小");
            getchar();
        }
        count--;
        printf(" ---你还有%d次机会\n\n",count);
    }
    printf("\n5次机会用完\n");
    getchar();
    return 0;
}