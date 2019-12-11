/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年06月06日 星期四 00时14分49秒
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
const int    maxn = 3e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m, K;
int cas, tol, T;

struct Sam {
	struct Node {
		int next[30];
		int fa, len;
		void init() {
			mes(next, 0);
			fa = len = 0;
		}
	} node[maxn<<1];
	int dp[maxn<<1];
	int sz, last, K;
	ll ans = 0;
	void init(int KK) {
		sz = last = 1;
		K = KK;
		ans = 0;
		mes(dp, 0);
		node[sz].init();
	}
	void insert(int k) {
		int p = last, np = last = ++sz;
		node[np].init();
		node[np].len = node[p].len+1;
		for(; p&&!node[p].next[k]; p=node[p].fa)
			node[p].next[k] = np;
		if(p == 0) {
			node[np].fa = 1;
		} else {
			int q = node[p].next[k];
			if(node[q].len == node[p].len+1) {
				node[np].fa = q;
			} else {
				int nq = ++sz;
				node[nq] = node[q];
				node[nq].len = node[p].len+1;
				node[np].fa = node[q].fa = nq;
				for(; p&&node[p].next[k]==q; p=node[p].fa)
					node[p].next[k] = nq;
			}
		}
	}
	void update(int p) {
		while(p != 1) {
			dp[p]++;
			if(dp[p]==K)	ans++;
			p = node[p].fa;
		}
	}
} sam;
char s[maxn];

int main() {
	scanf("%d%d%d", &n, &m, &K);
	scanf("%s", s+1);
	int len = strlen(s+1);
	sam.init(K);
	for(int i=1; i<=len; i++) {
		sam.insert(s[i]-'a'+1);
		sam.update(sam.last);
	}
	while(m--) {
		int id;
		scanf("%d", &id);
		if(id == 1) {
			char ss[5];
			scanf("%s", ss+1);
			sam.insert(ss[1]-'a'+1);
			sam.update(sam.last);
		} else {
			printf("%lld\n", sam.ans);
		}
	}
	return 0;
}

