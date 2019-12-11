/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年04月28日 星期日 10时53分19秒
 ***************************************************************/

#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <cfloat>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pii        pair<int, int>

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e3+30;
const int    maxm = 1e5 + 10;
const ll     mod  = 20090717;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m, K;
int cas, tol, T;

struct AC {
	ll dp[2][260][maxn];
	int node[260][27], cnt[260], fail[260];
	int sz, root;
	int newnode() {
		mes(node[++sz], 0);
		cnt[sz] = 0;
		return sz;
	}
	void init() {
		sz = 0;
		root = newnode();
	}
	void insert(char *s, int id) {
		int len = strlen(s+1);
		int rt = root;
		for(int i=1; i<=len; i++) {
			int k = s[i]-'a'+1;
			if(node[rt][k] == 0) {
				node[rt][k] = newnode();
			}
			rt = node[rt][k];
		}
		cnt[rt] |= (1<<(id-1));
	}
	void build() {
		queue<int> q;
		fail[root] = root;
		while(!q.empty())	q.pop();
		for(int i=1; i<=26; i++) {
			if(node[root][i] == 0) {
				node[root][i] = root;
			} else {
				fail[node[root][i]] = root;
				q.push(node[root][i]);
			}
		}
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for(int i=1; i<=26; i++) {
				if(node[u][i] == 0) {
					node[u][i] = node[fail[u]][i];
				} else {
					fail[node[u][i]] = node[fail[u]][i];
					q.push(node[u][i]);
				}
			}
		}
	}
	void solve() {
		int flag = 0;
		int mx = (1<<n)-1;
		for(int j=0; j<=sz; j++) {
			for(int k=0; k<=mx; k++) {
				dp[0][j][k] = 0;
				dp[1][j][k] = 0;
			}
		}
		dp[0][1][0] = 1;
		for(int i=1; i<=m; i++) {
			flag = !flag;
			for(int j=0; j<=sz; j++) {
				for(int k=0; k<=mx; k++) {
					dp[flag][j][k] = 0;
				}
			}
			for(int j=1; j<=sz; j++) {
				for(int k=0; k<=mx; k++) {
					if(dp[!flag][j][k] == 0)	continue;
					for(int o=1; o<=26; o++) {
						int nst = node[j][o];
						dp[flag][nst][k|cnt[nst]] += dp[!flag][j][k];
						dp[flag][nst][k|cnt[nst]] %= mod;
					}
				}
			}
		}
		ll ans = 0;
		for(int j=1; j<=sz; j++) {
			for(int k=0; k<=mx; k++) {
				if(__builtin_popcount(k) >= K) {
					ans = (ans + dp[flag][j][k])%mod;
				}
			}
		}
		printf("%lld\n", ans);
	}
} ac;
char s[15];

int main() {
	while(scanf("%d%d%d", &m, &n, &K), (n||m||K)) {
		ac.init();
		for(int i=1; i<=n; i++) {
			scanf("%s", s+1);
			ac.insert(s, i);
		}
		ac.build();
		ac.solve();
	}
	return 0;
}

