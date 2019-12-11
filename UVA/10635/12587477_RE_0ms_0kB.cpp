#include<stdio.h>
#include<string.h>
int num1[255]={0};
int num2[255]={0};
int flag[100000000]={0};
int solve(int n)
{
	int len=0;
	int s[255]={0};
	for(int i=1; i<=n; i++)
	{
		if(num2[i]>s[len])
			s[++len]=num2[i];
		else
		{
			int l=1,r=len,mid;
			while(l<=r)
			{
				mid=(l+r)>>1;
				if(s[mid]>num2[i])
					r=mid-1;
				else
					l=mid+1;
			}
			s[l]=num2[i];
		}
	}
	return len;
}
int main()
{
	int T;
	scanf("%d",&T);
	int cas=1;
	while(T--)
	{
		int n,p,q;
		scanf("%d%d%d",&n,&p,&q);
		p++,q++;
		for(int i=1; i<=p; i++)
		{
			scanf("%d",&num1[i]);
			flag[num1[i]]=i;
		}
		for(int i=1; i<=q; i++)
		{
			scanf("%d",&num2[i]);
			num2[i]=flag[num2[i]];
		}
		int ans=solve(q);
		printf("Case %d: %d\n",cas++, ans);
	}
	return 0;
}