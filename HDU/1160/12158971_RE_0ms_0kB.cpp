#include<stdio.h>
#include<stdlib.h>
struct mouse{
	int w;
	int s;
	int num;
};
int cmp1(const void*a, const void *b)
{
	return (*(mouse*)a).w-(*(mouse*)b).w;
}

int cmp2(const void*a, const void *b)
{
	return (*(mouse*)b).s-(*(mouse*)a).s;
}

int flag[105][105]={0};
int dp[105][105]={0};
int a[105]={0};
int b[105]={0};
void print(int i, int j)
{
	if(i==0||j==0)
		return;
	if(!flag[i][j])
	{
		print(i-1, j-1);
		printf("%d\n",a[i]);
	}
	else if(flag[i][j]==1)
	{
		print(i-1, j);
	}
	else
	{
		print(i, j-1);
	}
}

int main()
{
	struct mouse m[105];
	int i,j,n=1;
	while(scanf("%d%d",&m[n].w, &m[n].s)!=EOF)
	{
		m[n].num=n;
		n++;
	}
	
	n--;

	qsort(m+1, n, sizeof(mouse), cmp1);
	for(i=1; i<=n; i++)
		a[i]=m[i].num;

	qsort(m+1, n, sizeof(mouse), cmp2);
	for(i=1; i<=n; i++)
		b[i]=m[i].num;
	
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			if(a[i]==b[j])
			{
				dp[i][j]=dp[i-1][j-1]+1;
				flag[i][j]=0;
			}
			else
			{
				if(dp[i-1][j]>dp[i][j-1])
				{
					dp[i][j]=dp[i-1][j];
					flag[i][j]=1;
				}
				else
				{
					dp[i][j]=dp[i][j-1];
					flag[i][j]=-1;
				}
			}
		}
	}
	printf("%d\n",dp[n][n]);
	print(n, n);
	return 0;
}