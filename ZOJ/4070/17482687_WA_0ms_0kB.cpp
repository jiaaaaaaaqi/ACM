#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int v[11] = {1,0,0,0,1,0,1,0,2,1};

int f(int x)
{
	int ans = 0;
	while(x)
	{
		ans += v[x%10];
		x /= 10;
	}
	return ans;
}

int main()
{	
	int n,k,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		int tmp;
		for(int i = 0 ;i < k;i++)
		{
			tmp = n;
			n = f(n);
			if(n == tmp) break;
		}
		printf("%d\n",n);
	}
	
} 