/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年05月23日 星期四 00时06分46秒
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

struct SAM {
	struct Node{
		int next[27];
		int fa, len;
		int left, right;
		void init() {
			mes(next, 0);
			fa = len = left = right = 0;
		}
	} node[maxn<<1];
	vector<int> vv[maxn<<1];
	int sz, last;
	void init() {
		sz = last = 1;
		node[sz].init();
	}
	void insert(int k, int id) {
		int p = last, np = last = ++sz;
		node[np].init();
		node[np].len = node[p].len + 1;
		node[np].left = node[np].right = id;
		for(; p&&!node[p].next[k]; p=node[p].fa)
			node[p].next[k] = np;
		if(p == 0) {
			node[np].fa = 1;
		} else {
			int q = node[p].next[k];
			if(node[q].len == node[p].len + 1) {
				node[np].fa = q;
			} else {
				int nq = ++sz;
				node[nq] = node[q];
				node[nq].len = node[p].len+1;
				node[nq].left = node[q].left;
				node[nq].right = node[q].right;
				node[np].fa = node[q].fa = nq;
				for(; p&&node[p].next[k]==q; p=node[p].fa)
					node[p].next[k] = nq;
			}
		}
	}
	void dfs(int u) {
		for(auto v : vv[u]) {
			dfs(v);
			node[u].right = max(node[u].right, node[v].right);
		}
	}
	void build() {
		for(int i=1; i<=sz; i++)	vv[i].clear();
		for(int i=2; i<=sz; i++) {
			vv[node[i].fa].push_back(i);
		}
		dfs(1);
	}
	int DFS(int u) {
		int ans = 0;
		for(int i=1; i<=26; i++) {
			int v = node[u].next[i];
			if(v == 0)	continue;
			ans += DFS(v);
			int l = node[v].left, r = node[v].right;
			if(r-l >= node[u].len) {
				ans += min(node[v].len, r-l) - node[u].len;
			}
		}
		return ans;
	}
	int solve() {
		return DFS(1);
	}
} sam;
char s[maxn];

int main() {
	while(scanf("%s", s+1)) {
		if(s[1] == '#')	break;
		sam.init();
		int len = strlen(s+1);
		for(int i=1; i<=len; i++) {
			sam.insert(s[i]-'a'+1, i);
		}
		// for(int i=1; i<=sam.sz; i++) {
		//     printf("%d left = %d right = %d\n", i, sam.node[i].left, sam.node[i].right);
		// }
		// cout << endl;
		sam.build();
		// for(int i=1; i<=sam.sz; i++) {
		//     printf("%d left = %d right = %d\n", i, sam.node[i].left, sam.node[i].right);
		// }
		int ans = sam.solve();
		printf("%d\n", ans);
	}
	return 0;
}

