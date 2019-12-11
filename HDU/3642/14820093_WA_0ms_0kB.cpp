#include<map>
#include<set>
#include<ctime>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define first fi
#define second se
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 2050;
const int maxm = 305;
using namespace std;

int n, m, tol, T;
struct Node {
	int l, r, h, f;
	bool operator < (Node a) const {
		return h < a.h;
	}
};
Node node[maxn];
struct Edge {
	int x1, y1, z1;
	int x2, y2, z2;
};
Edge edge[maxn];
int Z[maxn];
int a[maxn];
int cnt[maxn << 2];
int sum1[maxn << 2];
int sum2[maxn << 2];
int sum3[maxn << 2];

void init() {
	m = 1;
	memset(cnt, 0, sizeof cnt);
	memset(sum1, 0, sizeof sum1);
	memset(sum2, 0, sizeof sum2);
	memset(sum3, 0, sizeof sum3);
	memset(node, 0, sizeof node);
}

void pushup(int left, int right, int root) {
	if(cnt[root] >= 3) {
		sum1[root] = sum2[root] = sum3[root] = a[right+1] - a[left];
	} else if(cnt[root] == 2) {
		sum2[root] = sum1[root] = a[right+1] - a[left];
		if(left == right) sum3[root] = 0;
		else	sum3[root] = sum2[root << 1] + sum2[root << 1 | 1];
	} else if(cnt[root] == 1) {
		sum1[root] = a[right+1] - a[left];
		if(left == right) {
			sum2[root] = sum3[root] = 0;
		} else {
			sum2[root] = sum1[root << 1] + sum1[root << 1 | 1];
			sum3[root] = sum2[root << 1] + sum2[root << 1 | 1];
		}
	} else {
		sum1[root] = sum1[root << 1] + sum1[root << 1 | 1];
		sum2[root] = sum2[root << 1] + sum2[root << 1 | 1];
		sum3[root] = sum3[root << 1] + sum3[root << 1 | 1];
	}
}

void update(int left, int right, int prel, int prer, int val, int root) {
	if(prel <= left && right <= prer) {
		cnt[root] += val;
		pushup(left, right, root);
		return ;
	}
	int mid = (left + right) >> 1;
	if(prel <= mid)		update(left, mid, prel, prer, val, root << 1);
	else	update(mid+1, right, prel, prer, val, root << 1 | 1);
	pushup(left, right, root);
}

int main() {
	int T;
	scanf("%d", &T);
	int cas = 1;
	while(T--) {
		memset(edge, 0, sizeof edge);
		memset(Z, 0, sizeof Z);
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			edge[i].x1 = x;
			edge[i].y1 = y;
			edge[i].z1 = z;
			Z[2*i-1] = z;
			scanf("%d%d%d", &x, &y, &z);
			edge[i].x2 = x;
			edge[i].y2 = y;
			edge[i].z2 = z;
			Z[2*i] = z;
		}
		sort(Z+1, Z+1+2*n);
		int zz = unique(Z+1, Z+1+2*n) - (Z+1);
		ll ans = 0;
		for(int i=1; i<zz; i++) {
			init();
			for(int j=1; j<=n; j++) {
				if(edge[j].z1 <= Z[i] && Z[i+1] <= edge[j].z2) {
					node[m].l = edge[j].x1;
					node[m].r = edge[j].x2;
					node[m].h = edge[j].y1;
					node[m].f = 1;
					a[m++] = edge[j].x1;
					node[m].l = edge[j].x1;
					node[m].r = edge[j].x2;
					node[m].h = edge[j].y2;
					node[m].f = -1;
					a[m++] = edge[j].x2;
				}
			}
			m--;
			sort(node+1, node+1+m);
			sort(a+1, a+1+m);
			int nn = unique(a+1, a+1+m) - (a+1);
			for(int j=1; j<m; j++) {
				int l = lower_bound(a+1, a+1+nn, node[j].l) - a;
				int r = lower_bound(a+1, a+1+nn, node[j].r) - a;
				update(1, m, l, r-1, node[j].f, 1);
				ans += sum3[1] * (node[j+1].h - node[j].h) * (Z[i+1] - Z[i]);
			}
		}
		printf("Case %d: %lld\n", cas++, ans);
	}
	return 0;
}
