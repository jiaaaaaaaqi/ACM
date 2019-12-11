#include<map>
#include<queue>
#include<string>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define inf 0x3f3f3f3f

typedef long long int ll;
using namespace std;

const int maxn = 200005;

ll sum[maxn];

void init() {
	memset(sum, 0, sizeof(sum));
}

int main() {
	int n, m;
	while(~scanf("%d%d", &n, &m)) {
		init();
		for(int i=0; i<n; i++) {
			ll x;
			scanf("%lld", &x);
			if(i == 0)
				sum[i] = x;
			else
				sum[i] = sum[i-1] + x;
		}
		for(int i=0; i<m; i++) {
			ll x;
			scanf("%lld", &x);
			ll pos = lower_bound(sum, sum+n, x) - sum + 1;
//			printf("%lld %lld\n", pos, sum[pos - 1]);
			ll val = x - sum[pos - 2];
			printf("%lld %lld\n", pos, val);
		}
	}
	return 0;
}
