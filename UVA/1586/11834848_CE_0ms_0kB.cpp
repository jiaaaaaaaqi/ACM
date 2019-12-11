#include<stdio.h>
#include<string.h>
float ele(char a)
{
	float x;
	if(a=='C')	x=12.01;
	if(a=='H')	x=1.008;
	if(a=='O')	x=16.00;
	if(a=='N')	x=14.01; 
	return x;
}
int main()
{
	int N;
	scanf("%d",&N);
	getchar();
	while(N--)
	{
		int i,j;
		float sum=0,x,y;
		char mo[1000];
		gets(mo);
		if(strlen(mo)==1)
		{
			sum=ele(mo[0]);
		}
		else
		{
			for(i=0; mo[i]!='\0'; i++)
			{
				int num=0;
				y=0,j=i,x=ele(mo[i]);
				if((mo[j+1]<='9'&&mo[j]>='0')||mo[j+1]=='\0')
				{
				while(mo[i+1]<='9'&&mo[i+1]>='0')
				{
					y=y*10+x*(mo[i+1]-48);
					i++;
					num++;
				}
				}
				if((mo[j+1]>='A'&&mo[i]<='Z')||mo[j+1]=='\0')
				{
					y=x;
					num++; 
				}
				sum+=y;					
			}
		}
	printf("%.3f\n",sum);
	}
} 