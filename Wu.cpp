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
        printf("��������µ���:");
        fflush(stdin);
        scanf("%d",&in);
        if(in==n)
        {
            printf("\n��ϲ��¶���!\n");
            getchar();
            exit(0);
        }
        else if(in>n)
        {
            printf("\n̫��");
            getchar(); 
        }
        else if(in<n)
        {
            printf("\n̫С");
            getchar();
        }
        count--;
        printf(" ---�㻹��%d�λ���\n\n",count);
    }
    printf("\n5�λ�������\n");
    getchar();
    return 0;
}