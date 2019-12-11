#include<stdio.h>
#include<string.h> 
int dp[3000050]={0};
int max_(int a, int b)
{
	return a>b ? a:b;
}
int main()
{
	float v;
	int n;
	while(scanf("%f%d",&v,&n),n)
	{
		int pri[35]={0};
		int sum=(int)(v*100);
		for(int i=1; i<=n; i++)
		{
			int m;
			char s;
			float num;
			float a=0,b=0,c=0,ppri=0;
			scanf("%d",&m);
			int flag;
			while(m--)
			{
				flag=1;
				scanf(" %c:%f",&s,&num);
				if(s=='A')
					a+=num;
				else if(s=='B')
					b+=num;
				else if(s=='C')
					c+=num;
				else 
					flag=0;
			}
			if(flag)
			{
				ppri=a+b+c;
				if(a>600||b>600||c>600||ppri>1000)
					pri[i]=0;
				else
					pri[i]=(int)(ppri*100);
			}
			else
				pri[i]=0;
		}
		for(int i=1; i<=n; i++)
			for(int j=sum; j>=pri[i]; j--)
				dp[j]=max_(dp[j], dp[j-pri[i]]+pri[i]);
		float ans=(float)dp[sum]/100;
		printf("%.2f\n",ans);
		memset(dp, 0, sizeof(dp));
	}
	return 0;
}