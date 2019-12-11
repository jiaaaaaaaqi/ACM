/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Mon 23 Sep 2019 02:01:34 PM CST
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
#include <unordered_map>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pb         push_back
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

int pri[maxn];
bool ispri[maxn];
int block;
int cnt[maxn], a[maxn];
bool res[maxn];
struct Node {
	int l, r;
	int id, d;
	bool operator < (Node a) const {
		return l/block==a.l/block ? r<a.r : l/block<a.l/block;
	}
} node[maxn];
vector< pii > vv[maxn];

void handle() {
	int mx = 1e5;
	tol = 0;
	mes(pri, 0), mes(ispri, 1);
	for(int i=2; i<=mx; i++) {
		if(ispri[i])	pri[++tol] = i;
		for(int j=1; j<=tol && pri[j]*i<=mx; j++) {
			ispri[i*pri[j]] = false;
			if(i%pri[j] == 0)	break;
		}
	}
	for(int t=1; t<=100000; t++) {
		vv[t].clear();
		int x = t;
		for(int i=1; i<=tol&&pri[i]*pri[i]<=x; i++) {
			if(x%pri[i] == 0) {
				int cnt = 0;
				while(x%pri[i] == 0) {
					x /= pri[i];
					cnt++;
				}
				vv[t].pb(make_pair(pri[i], cnt));
			}
		}
		if(x>1)	vv[t].pb(make_pair(x, 1));
	}
}

void add(int p) {
	for(auto i : vv[a[p]]) {
		cnt[i.fi] += i.se;
	}
}

void del(int p) {
	for(auto i : vv[a[p]]) {
		cnt[i.fi] -= i.se;
	}
}

bool ok(int x) {
	for(auto i : vv[x]) {
		if(cnt[i.fi] < i.se)	return false;
	}
	return true;
}

int main() {
	// freopen("in", "r", stdin);
	handle();
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		block = (int)sqrt(1.0*n);
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
		}
		for(int i=1; i<=m; i++) {
			scanf("%d%d%d", &node[i].l, &node[i].r, &node[i].d);
			node[i].id = i;
		}
		mes(cnt, 0);
		sort(node+1, node+1+m);
		int L = 1, R = 0;
		for(int i=1; i<=m; i++) {
			int l = node[i].l, r = node[i].r;
			while(L>l)	add(--L);
			while(L<l)	del(L++);
			while(R<r)	add(++R);
			while(R>r)	del(R--);
			res[node[i].id] = ok(node[i].d);
		}
		for(int i=1; i<=m; i++) {
			res[i] ? puts("Yes") : puts("No");
		}
	}
	return 0;
}

