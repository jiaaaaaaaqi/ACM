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
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 200005;
const int maxm = 40000;
const int mod = 2520;
using namespace std;

ll n, m, tol;
int digit[20];
ll dp[20][50][2500];
int id[2500];

void init() {
	memset(dp, -1, sizeof dp);
	memset(id, 0, sizeof id);
}

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

void handle() {
	tol = 1;
	for(int i=1; i<=mod; i++) {
		if(mod % i == 0) {
			id[i] = tol++;
		}
	}
}

ll dfs(int pos, int presum, int prelcm, int limit) {
	if(pos == 0)	return presum % prelcm == 0 ? 1 : 0;
	if(!limit && dp[pos][id[prelcm]][presum] != -1)	return dp[pos][id[prelcm]][presum];
	int up = limit ? digit[pos] : 9;
	ll ans = 0;
	for(int i=0; i<=up; i++) {
		int nowsum = (presum * 10 + i) % mod;
		int nowlcm = i ? lcm(prelcm, i) : prelcm;
		ans += dfs(pos - 1, nowsum, nowlcm, limit && i == digit[pos]);
	}
	if(!limit)	dp[pos][id[prelcm]][presum] = ans;
	return ans;
}

int solve(ll x) {
	memset(digit, 0, sizeof digit);
	int pos = 1;
	while(x) {
		digit[pos++] = x % 10;
		x /= 10;
	}
	return dfs(pos - 1, 0, 1,true);
}

int main() {
	int T;
	scanf("%d", &T);
	init();
	handle();
	while(T--) {
		scanf("%lld%lld", &n, &m);
		ll ans = solve(m) - solve(n - 1);
		printf("%lld\n", ans);
	}
	return 0;
}
