#include<stdio.h>
#include<string.h>
double num1[4];
double num2[1001];
int main()
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		memset(num1,0,sizeof(num1));
		memset(num2,0,sizeof(num2));
		double ans=0;
		int flag=1;
		int p,i,j;
		int temp;
		for(i=0; i<4; i++)
			scanf("%lf",&num1[i]);
		for(i=0; i<N; i++)
			scanf("%lf",&num2[i]);
		if(N<4)	flag=0;
		if(N>=4)
		{	
		
			for(i=0; i<N-1; i++)
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
			
			int time=1;
			for(i=0; i<4; i++)
			{
				int flag2=0;
				for(j=0; j<N; j++)
				{
					if(num2[j]>=num1[i])
					{
						num2[j]=0;
						flag2=1;
						break;
					}
				}
				if(flag2==0)
				{
					num1[i]=num1[i]-num2[N-time];
					num2[N-time]=0;
					time++;
					if(time>N)
					{
						i--;
						flag=0;
						break;
					}
					i=i-1;
					continue;
				}		
			}
			if(i==3)
				flag=1;
			if(flag)
			{
			ans=0;
			for(i=0; i<N; i++)
				ans+=num2[i];
			}
		}
		if(flag==1)
			printf("YES %.0lf",ans);
		if(flag==0)
			printf("NO");
		printf("\n");
	}
	return 0;
} 