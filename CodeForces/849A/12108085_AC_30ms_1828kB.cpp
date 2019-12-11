#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i; 
		int sum=0;
		int num[200]={0};
		for(i=0; i<n; i++)
			scanf("%d",&num[i]);
		int flag=0;
		int a=0;
		int time;
		if(num[0]%2==1&&num[n-1]%2==1)
		{
			for(i=0; i<n; i++)
			{
				time=0;
				int j=i;
				while(num[j++]%2==0)
					time++;
				if(time)
					for(int z=i; z<n; z++)
						num[z]=num[z+time];
			}
			for(sum=0; num[sum]!=0; sum++);
		}
		if(sum%2)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0; 
}