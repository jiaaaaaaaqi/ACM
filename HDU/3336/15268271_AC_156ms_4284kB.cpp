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
const int maxn = 200050;
const int maxm = 1e11;
const int mod = 10007;
using namespace std;

int n, m;
int T, tol;
char s[maxn];
int nex[maxn];
ll dp[maxn];

void init() {
	memset(nex, 0, sizeof nex);
	memset(dp, 0, sizeof dp);
}

void make_next_table() {
	nex[0] = -1;
	int i = 1;
	int j = 0;
	while(i < n) {
		if(j == -1 || s[i] == s[j]) {
			nex[++i] = ++j;
		} else {
			j = nex[j];
		}
	}
}

int main() {
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d", &n);
		scanf("%s", s);
		make_next_table();
		for(int i=1; i<=n; i++)	dp[i] = 1;
		ll ans = 0;
		for(int i=1; i<=n; i++) {
			dp[i] = dp[nex[i]]+1;
			dp[i] %= mod;
		}
		for(int i=1; i<=n; i++)	ans = (ans + dp[i]) % mod;
		printf("%I64d\n", ans);
	}
    return 0;
}
