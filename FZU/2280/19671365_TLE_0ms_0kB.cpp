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
const int    maxn = 1e6 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

char s[1005][1005], t[1005];
int node[maxn][27], w[1005];
int val[maxn], id[maxn];
int sz, root;

int newnode() {
	mes(node[++sz], 0);
	val[sz] = id[sz] = inf;
	return sz;
}

void init() {
	sz = 0;
	root = newnode();
}

void insert(char *s, int w, int p) {
	int len = strlen(s+1);
	int rt = root;
	for(int i=1; i<=len; i++) {
		int k = s[i]-'a'+1;
		if(node[rt][k] == 0) {
			node[rt][k] = newnode();
		}
		rt = node[rt][k];
	}
	int u = rt;
	while(node[rt][0] != 0) {
		rt = node[rt][0];
	}
	if(u != rt) {
		node[rt][0] = newnode();
		rt = node[rt][0];
	}
	val[rt] = w;
	id[rt] = p;
}

void update(char *s, int w, int p) {
	int len = strlen(s+1);
	int rt = root;
	for(int i=1; i<=len; i++) {
		int k = s[i]-'a'+1;
		rt = node[rt][k];
	}
	while(id[rt] != p) {
		rt = node[rt][0];
	}
	val[rt] = w;
}

ll dfs(int rt, int w) {
	ll ans = 0;
	if(val[rt] <= w)	ans = 1;
	for(int i=0; i<=26; i++) {
		int nst = node[rt][i];
		if(nst == 0)	continue;
		ans += dfs(nst, w);
	}
	return ans;
}

ll query(char *s, int w) {
	int len = strlen(s+1);
	int rt = root;
	for(int i=1; i<=len; i++) {
		int k = s[i]-'a'+1;
		rt = node[rt][k];
	}
	return dfs(rt, w);
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			scanf("%s%d", t+1, &w[i]);
			int len = strlen(t+1);
			for(int j=1; j<=len; j++) {
				s[i][j] = t[len-j+1];
			}
			s[i][len+1] = '\0';
			insert(s[i], w[i], i);
		}
		scanf("%d", &m);
		while(m--) {
			int d;
			scanf("%d", &d);
			if(d == 1) {
				int x, y;
				scanf("%d%d", &x, &y);
				w[x] = y;
				update(s[x], y, x);
			} else {
				int x;
				scanf("%d", &x);
				ll ans = query(s[x], w[x]);
				printf("%lld\n", ans);
			}
		}
	}
	return 0;
}
