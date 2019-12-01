#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int  getRand();           
void getUserInput();      
void getUserAgainInput(); 
void initSystemNum();     
void detection();         
void initGame();          
bool detectionWin();      
void gameStart();         
void putResult();         
//void putSystemNum();      

int  systemNum[4] = {};
int  userNum[4];
char result[5];
int  totalTimes = 0;      

int main()
{
	gameStart();
	printf("恭喜你全部猜对, 总共猜了%d次\n", totalTimes);
    printf("按enter键退出游戏\n");
    getchar();
    system("pause");
}

void gameStart()
{
	initGame();    
	detection();   
	int flag = 1;
	while(flag)    
	{
		if(detectionWin()) break;
		putResult();   
		getUserAgainInput(); 
		detection();   
	}
}

void initGame()
{
	initSystemNum();
	getUserInput();
}

int getRand()
{
	int x ;
	srand(time(NULL));
	x=rand()%10;
	return x;
}

void initSystemNum()
{
	int randNum; 
	bool flag=1;
	systemNum[0]=getRand();
	for(int i = 0 ; i<3 ; i++)
	{
		flag = 1;
		while(flag)
		{
		randNum = getRand();
			for(int g = 0 ;g <= i ; g++ )
			{
				if(systemNum[g]==randNum) break; 
				if(g==i) { flag=0 ; break ;}     
			}
		}
		systemNum[i+1]=randNum;          
	}
}

void getUserInput()
{
	totalTimes++;
	printf("请输入4个数：");
	for(int i = 0 ; i<4 ; i++) 
	{
		scanf("%d",&userNum[i]);
} 

} 

void getUserAgainInput()
{
	totalTimes++;
	printf("未能通过！请再次输入四个数：");
	for(int i = 0 ; i<4 ; i++) 
	{
		scanf("%d",&userNum[i]);
	} 
}

void detection()
{
	for(int x = 0 ; x < 4 ; x++)
	{
		for(int y = 0 ; y < 4 ; y++ )
		{
			if(userNum[x]==systemNum[y]) 
			{
				if(x==y) 
				{
					result[x] = 'A'; 
					break;
				}
				else 
				{
					result[x] ='B';
					break;
				}
			}
		}
	}
}

bool detectionWin()
{
	for(int x = 0 ; x < 4 ; x++)
	{
		if(result[x] =='B') break;
		if(x==3) return 1;
	}
	return 0;
}

void putResult()
{
	for(int a = 0 ; a < 4 ; a++)
	{
		printf("%c",result[a]); 
	}               
	printf("\n");
}

//void putSystemNum()
//{
//	for(int a = 0 ; a < 4 ; a++)
//	{
//		printf("%d ", systemNum[a]);
//	}
//	printf("\n");
//}
