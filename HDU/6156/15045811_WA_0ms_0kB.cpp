#include<map>
#include<set>
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
const int maxn = 100005;
const int maxm = 1000005;
const int mod = 10007;
using namespace std;

int T, tol;
ll n, m;
int digit[20];
ll tmp[100];
ll dp[40][100][100];

ll dfs(int pos, int st, int k, bool lead, bool limit) {
	if(pos == 0)	return	st ? 1 : 0;
	if(dp[k][st][pos] != -1 && !limit)	return dp[k][st][pos];
	ll ans = 0;
	int up = limit ? digit[pos] : k-1;
	for(int i=0; i<=up; i++) {
		tmp[pos] = i;
		if(lead && i == 0)	ans += dfs(pos-1, st-1, k, lead, limit && i==digit[pos]);
		else if(pos > st/2)	ans += dfs(pos-1, st, k, 0, limit && i==digit[pos]);
		else	ans += dfs(pos-1, i==tmp[st-pos+1] ? st : 0, k, 0, limit && i== digit[pos]);
	}
	if(!limit)	dp[k][st][pos] = ans;
	return ans;
}

ll solve(ll n, int k) {
	memset(digit, 0, sizeof digit);
	int pos = 1;
	while(n) {
		digit[pos++] = n % k;
		n /= k;
	}
	return dfs(pos-1, pos-1, k, 1, 1);
}

int main() {
	int cas = 1;
	scanf("%d", &T);
	memset(dp, -1, sizeof dp);
	while(T--) {
		int l, r;
		scanf("%I64d%I64d%d%d", &m, &n, &l, &r);
		m--;
		ll ans = 0;
		for(int i=l; i<=r; i++) {
			ll cnt1 = solve(n, i);
			ll cnt2 = solve(m, i);
			ans += (cnt1 - cnt2)*i + (n-m+cnt2-cnt1);
		}
		printf("Case #%d: %I64d\n",cas++, ans);
	}
    return 0;
}
