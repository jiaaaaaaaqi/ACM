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

char ss[maxn][10];
char s[maxn];
int type[maxn];
struct AC {
	int node[maxn*7][27], cnt[maxn*7], fail[maxn*7];
	int ans[maxn*7][2], l[maxn*7], last[maxn*7], id[maxn*7];
	int root, sz;
	int newnode() {
		mes(node[++sz], 0);
		cnt[sz] = 0;
		ans[sz][0] = ans[sz][1] = 0;
		l[sz] = last[sz] = 0;
		return sz;
	}
	void init() {
		sz = 0;
		root = newnode();
	}
	void insert(char *s, int iid) {
		int len = strlen(s+1);
		int rt = root;
		for(int i=1; i<=len; i++) {
			int k = s[i]-'a'+1;
			if(!node[rt][k]) {
				node[rt][k] = newnode();
			}
			rt = node[rt][k];
		}
		cnt[rt]++;
		l[rt] = len;
		id[iid] = rt;
	}
	void build() {
		queue<int> q;
		while(!q.empty())	q.pop();
		fail[root] = root;
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
	void calc(int rt, int i) {
		while(rt != root) {
			if(cnt[rt]) {
				ans[rt][0]++;
				if(last[rt]+l[rt]-1<i) {
					ans[rt][1]++;
					last[rt] = i;
				}
			}
			rt = fail[rt];
		}
	}
	void solve(char *s) {
		int len = strlen(s+1);
		int rt = root;
		for(int i=1; i<=len; i++) {
			int k = s[i]-'a'+1;
			rt = node[rt][k];
			calc(rt, i);
		}
	}
} ac;

int main() {
	cas = 1;
	while(~scanf("%s", s+1)) {
		ac.init();
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			scanf("%d%s", &type[i], ss[i]+1);
		}
		for(int i=1; i<=n; i++) {
			ac.insert(ss[i], i);
		}
		ac.build();
		ac.solve(s);
		printf("Case %d\n", cas++);
		for(int i=1; i<=n; i++) {
			printf("%d\n", ac.ans[ac.id[i]][type[i]]);
		}
		printf("\n");
	}
	return 0;
}
