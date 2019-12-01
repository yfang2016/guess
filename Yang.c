#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int get[4],read[4],n,times=0,a,b,c,i;
short num[10]={0},re[10]={0};
void ready()
{
	srand(time(0));
	n=rand()%10000;
	get[0]=n/1000;
	get[1]=n%1000/100;
	get[2]=n%100/10;
	get[3]=n%10;
	for (i=0;i<4;++i)
		num[get[i]]++;
	return;
}
void readin()
{
	char ch=getchar();
	while (ch<'0'||ch>'9')
		ch=getchar();
	i=0;
	while (ch>='0'&&ch<='9'){
		read[i++]=ch-'0';
		ch=getchar();
	}
	c=i!=4;
	return;
}
void check_a()
{
	for (i=0;i<4;++i)
		if (get[i]==read[i]){
			++a;
			++re[get[i]];
			--num[get[i]];
		}
	return;
}
void check_b()
{
	for (i=0;i<4;++i)
		if (get[i]!=read[i]&&num[read[i]]){
			++b;
			++re[read[i]];	
			--num[read[i]];	
		}
	return;
}
void back()
{
	for (i=0;i<10;++i){
		num[i]+=re[i];
		re[i]=0;
	}
	return;
}
void guess()
{
	while (1)
	{
		a=0;
		b=0;
		++times;
		
		
		readin();
		while (c){
			printf("Wrong\n%d:\tn=",times);
			readin();
		}						//get the readin number
		
		check_a();				//get the A
		
		if (a==4) break;		//check for right
		
		check_b();				//get the B
		
		back();					//reback the num
		
		printf("%dA%dB\n",a,b);
		printf("%d:\tn=",times+1);			//once again
	}
	return;
}
int main()
{
	ready();					//get the random number

	printf("Readin:\n1:\tn=");
	
	guess();					//start to guess
	
	printf("Bingo\nYou had tried %d times\n",times);
	
	getchar();
	return 0;
}