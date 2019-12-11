#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e5+7;

int v[maxn],dp[maxn][50];
ll sum[maxn];

void init(int n)
{
	for(int i = 1; i <= n;i++)
		dp[i][0] = v[i];
	for(int j = 1;(1<<j) <= n;j++) 
	{
		for(int i = 1;(i + (1<<j) - 1) <= n;i++)
		{
			dp[i][j] = min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
		}
	}
}

int _get(int l,int r)
{
	if(r < l )return 0;
	int len = r - l + 1;
	int k = log2(len*1.0);
	return min(dp[l][k],dp[r-(1<<k)+1][k]);
}

int main()
{	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		sum[0] = 0;
		for(int i = 1 ;i <= n;i++)
		{
			scanf("%d",&v[i]);
			sum[i] = sum[i-1] + v[i];
		}
		if((sum[m] == 0  && m != 0)|| m > n)
		{
			printf("Impossible\n");
			continue;
		}
		if(m == n)
		{
			printf("Richman\n");
			continue;
		}
		init(n);
		ll ans = sum[m] + _get(m+1,n);
	//	printf("%lld --\n",_get(m+1,n));
		if(ans == 0) printf("Impossible\n");
		else printf("%lld\n",ans-1);
	}
	
} 