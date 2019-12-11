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
#define  INOPEN     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e5 + 10;
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
	int node[2100][2], fail[2100], cnt[2100];
	int nex[2100][10];
	ll dp[220][2100];
	int bit[220];
	int root, sz;
	int newnode() {
		mes(node[++sz], 0);
		cnt[sz] = 0;
		return sz;
	}
	void init() {
		sz = 0;
		mes(dp, -1);
		root = newnode();
	}
	void insert(char *s) {
		int len = strlen(s+1);
		int rt = root;
		for(int i=1; i<=len; i++) {
			int k = s[i]-'0';
			if(!node[rt][k])	node[rt][k] = newnode();
			rt = node[rt][k];
		}
		cnt[rt] = 1;
	}
	void build() {
		fail[root] = root;
		queue<int> q;
		while(!q.empty())	q.pop();
		for(int i=0; i<=1; i++) {
			if(node[root][i] == 0) {
				node[root][i] = root;
			} else {
				fail[node[root][i]] = root;
				q.push(node[root][i]);
			}
		}
		while(!q.empty()) {
			int u = q.front();
			cnt[u] |= cnt[fail[u]];
			q.pop();
			for(int i=0; i<=1; i++) {
				if(node[u][i] == 0) {
					node[u][i] = node[fail[u]][i];
				} else {
					fail[node[u][i]] = node[fail[u]][i];
					q.push(node[u][i]);
				}
			}
		}
	}
	int find(int x, int y) {
		int cc[10];
		for(int i=4; i>=1; i--) {
			cc[i] = y&1;
			y >>= 1;
		}
		if(cnt[x])	return -1;
		for(int i=1; i<=4; i++) {
			x = node[x][cc[i]];
			if(cnt[x])	return -1;
		}
		return x;
	}
	void handle() {
		for(int i=1; i<=sz; i++) {
			for(int j=0; j<=9; j++) {
				nex[i][j] = find(i, j);
			}
		}
	}
	ll dfs(int pos, int st, bool lead, bool limit) {
		if(pos == 0)	return 1;
		if(!lead && !limit && dp[pos][st] != -1)	return dp[pos][st];
		ll ans = 0;
		int up = limit ? bit[pos] : 9;
		for(int i=0; i<=up; i++) {
			if(lead==1 && i==0) {
				ans += dfs(pos-1, 1, lead&&i==0, limit&&i==up);
			} else {
				if(nex[st][i] == -1)	continue;
				ans += dfs(pos-1, nex[st][i], lead&&i==0, limit&&i==up);
			}
			ans %= mod;
		}
		if(!lead && !limit)	dp[pos][st] = ans;
		return ans;
	}
	int solve(char *s) {
		int len = strlen(s+1);
		for(int i=1; i<=len; i++) {
			bit[i] = s[len-i+1]-'0';
		}
		return dfs(len, 1, 1, 1);
	}
} ac;
char s[1000];

int main() {
	scanf("%d", &T);
	while(T--) {
		ac.init();
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			scanf("%s", s+1);
			ac.insert(s);
		}
		ac.build();
		ac.handle();
		ll ans = 0;
		mes(s, 0);
		scanf("%s", s+1);
		int len = strlen(s+1);
		for(int i=len; i>=1; i--) {
			if(s[i] == '0') {
				s[i] = '9';
			} else {
				s[i]--;
				break;
			}
		}
		ans -= ac.solve(s);
		mes(s, 0);
		scanf("%s", s+1);
		ans += ac.solve(s);
		ans = (ans%mod+mod)%mod;
		printf("%lld\n", ans);
	}
	return 0;
}
