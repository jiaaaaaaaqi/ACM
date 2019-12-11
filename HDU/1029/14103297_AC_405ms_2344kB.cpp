#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
const int inf = 0x3f3f3f3f;
const int maxn = 10005;
const int mod = 10007;

int num[1000005];
map<ll, int> vis;

int main() {
	int n;
	while(~scanf("%d", &n)) {
		vis.clear();
		int time = (n + 1) / 2;
		ll ans;
		for(int i=0; i<n; i++) {
			ll x;
			scanf("%d", &x);
			vis[x]++;
			if(vis[x] >= time)
				ans = x;
		}
		printf("%lld\n", ans);
	}
	return 0;
}