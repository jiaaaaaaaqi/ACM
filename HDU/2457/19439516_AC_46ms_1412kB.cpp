
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
const int    maxn = 1e3 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct AC {
	int node[maxn][5], cnt[maxn], fail[maxn];
	int dp[maxn][maxn];
	int root, sz;
	int newnode() {
		mes(node[++sz], -1);
		cnt[sz] = 0;
		return sz;
	}
	void init () {
		sz = 0;
		root = newnode();
	}
	int getid(char c) {
		if(c == 'A')	return 1;
		if(c == 'T')	return 2;
		if(c == 'C')	return 3;
		if(c == 'G')	return 4;
	}
	void insert(char *s) {
		int len = strlen(s+1);
		int rt = root;
		for(int i=1; i<=len; i++) {
			int k = getid(s[i]);
			if(node[rt][k] == -1) {
				node[rt][k] = newnode();
			}
			rt = node[rt][k];
		}
		cnt[rt] = 1;
	}
	void build() {
		queue<int> q;
		while(!q.empty())	q.pop();
		for(int i=1; i<=4; i++) {
			if(node[root][i] == -1) {
				node[root][i] = root;
			} else {
				fail[node[root][i]] = root;
				q.push(node[root][i]);
			}
		}
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			if(cnt[fail[u]])
				cnt[u] = 1;
			for(int i=1; i<=4; i++) {
				if(node[u][i] == -1) {
					node[u][i] = node[fail[u]][i];
				} else {
					fail[node[u][i]] = node[fail[u]][i];
					q.push(node[u][i]);
				}
			}
		}
	}
	int query(char *s) {
		int len = strlen(s+1);
		int flag = 0;
		dp[0][1] = 0;
		for(int i=2; i<=sz; i++)
			dp[0][i] = inf;
		for(int i=1; i<=len; i++) {
			flag = !flag;
			for(int j=1; j<=sz; j++) {
				dp[flag][j] = inf;
			}
			int id = getid(s[i]);
			for(int j=1; j<=sz; j++) {
				if(dp[!flag][j] == inf)	continue;
				int st = node[j][id];
				for(int k=1; k<=4; k++) {
					int nst = node[j][k];
					if(cnt[nst])	continue;
					if(nst == st) {
						dp[flag][nst] = min(dp[flag][nst], dp[!flag][j]);
					} else {
						dp[flag][nst] = min(dp[flag][nst], dp[!flag][j]+1);
					}
				}
			}
		}
		int ans = inf;
		for(int i=1; i<=sz; i++)
			ans = min(ans, dp[flag][i]);
		return ans;
	}
} ac;
char s[maxn];

int main() {
	cas = 1;
	while(scanf("%d", &n), n) {
		ac.init();
		for(int i=1; i<=n; i++) {
			scanf("%s", s+1);
			ac.insert(s);
		}
		ac.build();
		scanf("%s", s+1);
		int ans = ac.query(s);
		if(ans == inf)	ans = -1;
		printf("Case %d: %d\n", cas++, ans);
	}
	return 0;
}
