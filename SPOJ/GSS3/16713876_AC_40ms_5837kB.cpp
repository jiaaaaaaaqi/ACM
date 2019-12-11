#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
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
const int    maxn = 50000 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Node {
	int lmx, rmx, smx, sum;
} node[maxn<<2];

void pushup(int rt) {
    node[rt].sum = node[rt<<1].sum + node[rt<<1|1].sum;
    node[rt].lmx = max(node[rt<<1].lmx, node[rt<<1].sum + node[rt<<1|1].lmx);
    node[rt].rmx = max(node[rt<<1|1].rmx, node[rt<<1|1].sum + node[rt<<1].rmx);
    node[rt].smx = max(node[rt<<1].rmx+node[rt<<1|1].lmx, max(node[rt<<1].smx, node[rt<<1|1].smx));
}

void build(int l, int r, int rt) {
    if(l == r) {
        scanf("%d", &node[rt].sum);
        node[rt].rmx = node[rt].lmx = node[rt].smx = node[rt].sum;
        return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, rt<<1);
    build(mid+1, r, rt<<1|1);
    pushup(rt);
}

void update(int l, int r, int p, int v, int rt) {
	if(l ==r) {
		node[rt].rmx = node[rt].lmx = node[rt].smx = node[rt].sum = v;
		return ;
	}
	int mid = (l + r) >> 1;
	if(p <= mid)
		update(l, mid, p, v, rt<<1);
	else
		update(mid+1, r, p, v, rt<<1|1);
	pushup(rt);
}

Node query(int l, int r, int pl, int pr, int rt) {
	if(pl <= l && r <= pr) 
		return node[rt];
	int mid = (l + r) >> 1;
	Node nl, nr, ans;
	int fl, fr;
	fl = fr = 0;
	if(pl <= mid) {
		nl = query(l, mid, pl, pr, rt<<1);
		fl = 1;
	}
	if(pr > mid) {
		nr = query(mid+1, r, pl, pr, rt<<1|1);
		fr = 1;
	}
	if(fl && fr) {
		ans.sum = nl.sum + nr.sum;
		ans.lmx = max(nl.lmx, nl.sum + nr.lmx);
		ans.rmx = max(nr.rmx, nr.sum + nl.rmx);
		ans.smx = max(nl.rmx + nr.lmx, max(nl.smx, nr.smx));
		return ans;
	} else if(fl) {
		return nl;
	} else {
		return nr;
	}
}

int main() {
    scanf("%d", &n);
    build(1, n, 1);
    scanf("%d", &m);
    while(m--) {
        int id, l, r;
        scanf("%d%d%d", &id, &l, &r);
        if(id == 1)
            printf("%d\n", query(1, n, l, r, 1).smx);
        else
            update(1, n, l, r, 1);
    }
    return 0;
}
