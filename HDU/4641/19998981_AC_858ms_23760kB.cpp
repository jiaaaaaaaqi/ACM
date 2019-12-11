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
const int    maxn = 5e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Sam {
	int node[maxn][27];
	int len[maxn], fa[maxn];
	int dp[maxn];
	int sz, last, K, ans;
	void init() {
		sz = last = 1;
		ans = 0;
		mes(node[1], 0);
		fa[1] = len[1] = 0;
	}
	void insert(int k) {
		int p = last, np = last = ++sz;
		mes(node[np], 0);
		dp[np] = fa[np] = 0;
		len[np] = len[p]+1;
		for(; p&&!node[p][k]; p=fa[p])
			node[p][k] = np;
		if(p==0) {
			fa[np] = 1;
		} else {
			int q = node[p][k];
			if(len[q] == len[p]+1) {
				fa[np] = q;
			} else {
				int nq = ++sz;
				memcpy(node[nq], node[q], sizeof(node[q]));
				dp[nq] = dp[q];
				fa[nq] = fa[q];
				len[nq] = len[p]+1;
				fa[np] = fa[q] = nq;
				for(; p&&node[p][k]==q; p=fa[p])
					node[p][k] = nq;
			}
		}
	}
	void update(int p) {
		for(; p&&dp[p]<K; p=fa[p]) {
			dp[p]++;
			if(dp[p]>=K)	ans+=len[p]-len[fa[p]];
		}
	}
} sam;
char s[50005];

int main() {
	while(~scanf("%d%d%d", &n, &m, &sam.K)) {
		scanf("%s", s+1);
		sam.init();
		int len = strlen(s+1);
		for(int i=1; i<=len; i++) {
			sam.insert(s[i]-'a'+1);
			sam.update(sam.last);
		}
		char ss[5];
		while(m--) {
			int id;
			scanf("%d", &id);
			if(id == 1) {
				scanf("%s", ss+1);
				sam.insert(ss[1]-'a'+1);
				sam.update(sam.last);
			} else {
				printf("%d\n", sam.ans);
			}
		}
	}
	return 0;
}

