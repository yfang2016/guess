#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main(void)
{
    while(1){
        printf("已经生成随机数，请输入猜测数据，4位数");
        int x=rand() % 10000;
        int y;
        while(1){
            int right_number=0;
            scanf("%d",&y);
            if(y%10==x%10)
                right_number++;
            if(y/10%10==x/10%10)
                right_number++;
            if(y/100%10==x/100%10)
                right_number++;
            if(y/1000%10==x/1000%10)
                right_number++;
            if(right_number==4)
            {
                printf("恭喜，猜对了%d",x);
                getchar();
                printf("重新生成随机数");
                break;
            }
            printf("输入正确数字数目%d\n",right_number);
        }
         
    }
     
}
