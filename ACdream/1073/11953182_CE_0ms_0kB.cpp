#include<stdio.h>
#include<string.h>
int main()
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		int num1[4]={0};	//四个等级的经验 
		int num2[1005]={0};	//N个经验球经验 
		int ans;
		int flag=0;
		int p,i,j;
		int temp;
		for(i=0; i<4; i++)
			scanf("%d",&num1[i]);
		for(i=0; i<N; i++)
			scanf("%d",&num2[i]);
		if(N>=4)
		{	
		
			for(i=0; i<N-1; i++)		//从小到大排经验球 
			{
				p=i;
				for(j=i+1; j<N; j++)
				{
					if(num2[p]>num2[j])
						p=j;
					if(p!=i)
					{
						temp=num2[i];
						num2[i]=num2[p];
						num2[p]=temp;
					}
				}
			}
			
			int flag2;
			int num=0;	 
			int time=1;
			for(i=0; i<4; i++)
			{
				flag2=0;
				for(j=0; j<N; j++)		//搜经验球 找有没有满足条件的经验球 
				{
					if(num2[j]>=num1[i])
					{
						num2[j]=0;		//吃完清0 
						flag2=1;
						num++;
						break;
					}
				}
				if(!flag2)		//要是不能升级 
				{
					num1[i]-=num2[N-time]	//从最后一个往前吃  
					num2[N-time]=0; 		//吃完清0 
					time++;
					if(time>N+1)		//吃到第一个都不能升级  就退出 
					{
						break;
					}
					i=i-1;
				}		
			}
			
			if(num==4)		//升级了4次 
				flag=1;
			if(flag)		// 把经验球经验加起来 
			{
			ans=0;
			for(i=0; i<N; i++)
				ans+=num2[i];
			}
		}
		if(flag)
			printf("YES %d\n",ans);
		if(!flag)
			printf("NO\n");
	}
	return 0;
} 