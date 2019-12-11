/*************************************************************** 
	> File Name		: L.cpp
	> Author		: Jiaaaaaaaqi
	> Created Time	: Thu 14 Nov 2019 07:02:03 PM CST
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

struct E {
	int v, d;
} e[maxn];
struct Node {
	int min, max, ans;
};
int Min[15][maxn<<2], Max[15][maxn<<2];
int ans[15][maxn<<2];

void pushup(int id, int rt) {
	Min[id][rt] = min(Min[id][rt<<1], Min[id][rt<<1|1]);
	Max[id][rt] = max(Max[id][rt<<1], Max[id][rt<<1|1]);
	if(id<7) 
		ans[id][rt] = max({ans[id][rt<<1], ans[id][rt<<1|1], Max[id][rt<<1|1]-Min[id][rt<<1]});
	else	
		ans[id][rt] = max({ans[id][rt<<1], ans[id][rt<<1|1], Max[id][rt<<1]-Min[id][rt<<1|1]});
}

void build(int id, int l, int r, int rt) {
	Min[id][rt] = inf, Max[id][rt] = 0;
	ans[id][rt] = 0;
	if(l == r)	return ;
	int mid = l+r>>1;
	build(id, l, mid, rt<<1);
	build(id, mid+1, r, rt<<1|1);
	pushup(id, rt);
}

void update(int id, int l, int r, int p, int v, int rt) {
	if(l == r) {
		Min[id][rt] = Max[id][rt] = v;
		return ;
	}
	int mid = l+r>>1;
	if(p <= mid)	update(id, l, mid, p, v, rt<<1);
	else	update(id, mid+1, r, p, v, rt<<1|1);
	pushup(id, rt);
}

Node bind(int id, Node a, Node b) {
	Node ans = Node{inf, 0, 0};
	ans.min = min(a.min, b.min);
	ans.max = max(a.max, b.max);
	if(id<7) 
		ans.ans = max({a.ans, b.ans, b.max-a.min});
	else	
		ans.ans = max({a.ans, b.ans, a.max-b.min});
	return ans;
}

Node query(int id, int l, int r, int pl, int pr, int rt) {
	if(pl<=l && r<=pr)	return Node{Min[id][rt], Max[id][rt], ans[id][rt]};
	int mid = l+r>>1;
	Node ans = {inf, 0, 0};
	if(pl<=mid) {
		Node res = query(id, l, mid, pl, pr, rt<<1);
		ans = bind(id, ans, res);
	}
	if(pr>mid) {
		Node res = query(id, mid+1, r, pl, pr, rt<<1|1);
		ans = bind(id, ans, res);
	}
	return ans;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &n);
	for(int i=1; i<=n; i++)	scanf("%d%d", &e[i].v, &e[i].d);
	for(int d=0; d<7; d++) {
		{
			int day = d;
			build(d, 1, n, 1);
			for(int i=1; i<=n; i++) {
				int v = e[i].v;
				if(day==2 || day==6)	v += e[i].d;
				if(day==3 || day==5)	v += 2*e[i].d;
				if(day==4)	v += 3*e[i].d;
				update(d, 1, n, i, v, 1);
				day = (day+1)%7;
			}
		}
		{
			int day = d;
			build(d+7, 1, n, 1);
			for(int i=n; i>=1; i--) {
				int v = e[i].v;
				if(day==2 || day==6)	v += e[i].d;
				if(day==3 || day==5)	v += 2*e[i].d;
				if(day==4)	v += 3*e[i].d;
				update(d+7, 1, n, i, v, 1);
				day = (day+1)%7;
			}
		}
	}
	int q;
	scanf("%d", &q);
	while(q--) {
		int l, r, d;
		scanf("%d%d", &l, &r);
		if(l<=r) {
			d = 2-l;
			d = (d%7+7)%7;
		} else {
			d = 2-(n-l+1);
			d = (d%7+7)%7+7;
			swap(l, r);
		}
		int ans = query(d, 1, n, l, r, 1).ans;
		printf("%d\n", ans);
	}
	return 0;
}

