#include<stdio.h>
#include<string.h> 
long long int len[100005]={0};
long long int max_(long long int a, long long int b)
{
	return a>b ? a:b; 
}
int main()
{
	int n;
	while(scanf("%d",&n), n)
	{
		int i,j;
		for(i=1; i<=n; i++)
			scanf("%lld", &len[i]);
		int l=0,r=0;
		long long int h=0;
		long long int max=0;
		for(i=1; i<=n; i++)
		{
			if(len[i]>=len[i-1])
			{
				if((r-l+1)*len[i-1]>=len[i])
					r=i;
				else
					l=i-1,r=i,h=len[i];
			}
			else
			{
				if(h<=len[i])
				{ 
					int area1=(r-l)*h+h;
					int area2=len[i];
					if(area1>=area2)
						r=i;
					else
						l=i-1,r=i,h=len[i];
				}
				else
				{
					r=i;
					h=len[i];
				} 
			}
			max=max_(max, (r-l)*h);
		}
		printf("%lld\n",max);
	}
	return 0;
}