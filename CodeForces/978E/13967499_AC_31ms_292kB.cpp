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

int main() {
	ll n, m;
	while(~scanf("%lld%lld", &n, &m)) {
		ll minnum = inf;
		ll maxnum = -inf;
		ll prenum = 0;
		for(int i=0; i<n; i++) {
			ll x;
			scanf("%lld", &x);
			prenum += x;
			minnum = min(minnum, prenum);
			maxnum = max(maxnum, prenum);
		}
		if(minnum < 0)
			minnum = -minnum;
		else
			minnum = 0;
		if(maxnum < 0)
			maxnum = 0;
		if(minnum > m) {
			printf("0\n");
			continue;
		}
		if(maxnum > m) {
			printf("0\n");
			continue;
		}
		maxnum = m - maxnum;
//		printf("%lld %lld\n", minnum, maxnum);
		ll ans = maxnum - minnum + 1;
		printf("%lld\n", ans > 0 ? ans : 0);
	}
	return 0;
}
