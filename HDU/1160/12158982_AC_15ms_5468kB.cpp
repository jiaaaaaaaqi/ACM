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

int flag[1005][1005]={0};
int dp[2][1005]={0};
int a[1005]={0};
int b[1005]={0};
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
	struct mouse m[1005];
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
	
	int t=1;
	for(i=1; i<=n; i++)
	{
		t=1-t;
		for(j=1; j<=n; j++)
		{
			if(a[i]==b[j])
			{
				dp[t][j]=dp[1-t][j-1]+1;
				flag[i][j]=0;
			}
			else
			{
				if(dp[1-t][j]>dp[t][j-1])
				{
					dp[t][j]=dp[1-t][j];
					flag[i][j]=1;
				}
				else
				{
					dp[t][j]=dp[t][j-1];
					flag[i][j]=-1;
				}
			}
		}
	}
	printf("%d\n",dp[t][n]);
	print(n, n);
	return 0;
}