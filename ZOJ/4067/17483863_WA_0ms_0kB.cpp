#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e5+7;

int v[maxn];

int check(ll sum,int m,int n)
{
	int cnt = 0; 
	for(int i = 1;i <= n;i++)
	{
		if(sum >= v[i]) sum -= v[i],cnt++;
	}
	if(cnt == m) return 0;
	return cnt > m ? 1 : -1;
}

bool vis[maxn];

int main()
{	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,f0 = 0;
		scanf("%d%d",&n,&m);
		ll l = 0 ,r = 0;
		for(int i = 1 ;i <= n;i++)
		{
			scanf("%d",&v[i]);
			if(v[i] == 0) f0++;
			r += v[i];
		}
		if(m == n)
		{
			printf("Richman\n");
			continue;
		}
		if(f0 > m)
		{
			printf("Impossible\n");
			continue;
		}
		ll mid;
		while(l <= r)
		{
			mid = (l+r) / 2;
			if(check(mid,m,n) <= 0) l = mid +1;
			else r = mid - 1;
		//	printf("%lld %d\n",mid,check(mid,m,n));
		}
	//	printf(" * %lld\n",mid);
		for(ll i = mid;;i--)
		{
			if(check(i,m,n) == 0) 
			{
				printf("%lld\n",i);
				break;	
			}	
		}
		
	}
	
} 