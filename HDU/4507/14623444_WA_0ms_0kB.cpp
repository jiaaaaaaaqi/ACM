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
const int mod = 1000000007;
using namespace std;

ll n, m, tol;
struct Node{
	ll cnt;
	ll sum;
	ll sqsum;
};
Node dp[20][10][10];
int digit[20];
ll po[20];

void init() {
	for(int i=0; i<20; i++) {
		for(int j=0; j<10; j++) {
			for(int k=0; k<10; k++) {
				dp[i][j][k].cnt = -1;
				dp[i][j][k].sum = 0;
				dp[i][j][k].sqsum = 0;
			}
		}
	}
}

void handle() {
	po[0] = 1;
	for(int i=1; i<20; i++) {
		po[i] = po[i - 1] * 10 % mod;
	}
}

Node dfs(int pos, int sum, int num, bool limit) {
	if(pos == 0) {
		Node tmp;
		tmp.cnt = (sum == 0 || num == 0) ? 0 : 1;
		tmp.sqsum = tmp.sum = 0;
		return tmp;
	}
	if(!limit && dp[pos][sum][num].cnt != -1)	return dp[pos][sum][num];
	Node ans;
	ans.cnt = ans.sum = ans.sqsum = 0;
	int up = limit ? digit[pos] : 9;
	for(int i=0; i<=up; i++) {
		if(i == 7)	continue;
		Node tmp = dfs(pos-1, (sum+i)%7, (num*10+i)%7, limit && i == digit[pos]);
		ans.cnt += tmp.cnt;
		ans.cnt %= mod;
		ans.sum += (tmp.sum %mod + (i * po[pos-1]) % mod * tmp.cnt % mod);
		ans.sum %= mod;
		ans.sqsum += ((tmp.sqsum % mod) + ((2 * i * ((po[pos-1] % mod) * (tmp.sum % mod)) % mod) % mod) + (((i * po[pos-1] % mod) * (i * po[pos-1] % mod) % mod * tmp.cnt) % mod) % mod);
		ans.sqsum %= mod; 
	}
	if(!limit)	dp[pos][sum][num] = ans;
	return ans;
}

ll solve(ll x) {
	int pos = 1;
	while(x) {
		digit[pos++] = x % 10;
		x /= 10;
	}
	return dfs(pos-1, 0, 0, true).sqsum;
}

int main() {
	int T;
	scanf("%d", &T);
    init();
    handle();
	while(T--) {
		scanf("%lld%lld", &n, &m);
        ll ans = solve(m) - solve(n-1);
        ans = (ans + mod) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}
