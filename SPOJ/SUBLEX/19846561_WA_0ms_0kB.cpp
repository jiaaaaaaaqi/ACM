/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年05月22日 星期三 17时06分12秒
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

struct SAM {
	struct Node{
		int next[27];
		int fa, len;
		void init() {
			mes(next, 0);
			len = fa = 0;
		}
	} node[maxn<<1];
	int sz, last;
	int cnt[maxn<<1];
	void init() {
		sz = last = 1;
		node[sz].init();
		mes(cnt, 0);
	}
	void insert(int k) {
		int p = last, np = last = ++sz;
		node[np].init();
		node[np].len = node[p].len+1;
		for(; p&&!node[p].next[k]; p=node[p].fa)
			node[p].next[k] = np;
		if(p==0) {
			node[np].fa = 1;
		} else {
			int q = node[p].next[k];
			if(node[q].len == node[p].len + 1) {
				node[np].fa = q;
			} else {
				int nq = ++sz;
				node[nq] = node[q];
				node[nq].len = node[p].len + 1;
				node[np].fa = node[q].fa = nq;
				for(; p&&node[p].next[k]==q; p=node[p].fa)
					node[p].next[k] = nq;
			}
		}
	}
	void dfs(int u) {
		if(cnt[u])	return ;
		cnt[u] = 1;
		for(int i=1; i<=26; i++) {
			int v = node[u].next[i];
			if(v) {
				dfs(v);
				cnt[u] += cnt[v];
			}
		}
	}
	char ss[maxn];
	void find(int u, int k, int len) {
		if(k==0) {
			ss[len] = '\0';
			printf("%s\n", ss+1);
			return ;
		}
		for(int i=1; i<=26; i++) {
			int v = node[u].next[i];
			if(v==0)	continue;
			if(cnt[v] < k)	k -= cnt[v];
			else {
				k--;
				ss[len] = 'a'+i-1;
				find(v, k, len+1);
			}
		}
	}
	void solve(int k) {
		find(1, k, 1);
	}
} sam;
char s[maxn];

int main() {
	sam.init();
	scanf("%s", s+1);
	int len = strlen(s+1);
	for(int i=1; i<=len; i++) {
		sam.insert(s[i]-'a'+1);
	}
	sam.dfs(1);
	// for(int i=1; i<=sam.sz; i++) {
	//     printf("cnt[%d] = %d\n", i, sam.cnt[i]);
	// }
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &m);
		sam.solve(m);
	}
	return 0;
}

