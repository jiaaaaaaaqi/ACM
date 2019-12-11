#include<map>
#include<ctime>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 10050;
const int maxm = 100000;
using namespace std;

int ans[maxn];

int main() {
	int cas = 1;
	int n;
	int T;
	scanf("%d", &T);
	while(T--) {
		memset(ans, 0, sizeof(ans));
		scanf("%d", &n);
		int res = 0;
		for(int i=1; i<=n; i++) scanf("%d", &ans[i]);
		for(int i=1; i<=n; i++)	{
			int x;
			scanf("%d", &x);
			ans[i] += x;
			if(ans[i] > 10)
				res++;
		}
		printf("Case %d: %d\n", cas++, res);
	}
	return 0;
}

