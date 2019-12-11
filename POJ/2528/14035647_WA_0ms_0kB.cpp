#include<map>
#include<queue>
#include<string>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define inf 0x3f3f3f3f

typedef unsigned long long int ull;
typedef long long int ll;
const int maxn = 10002;
using namespace std;

int n, m;
struct Node {
	int l;
	int r;
} node[maxn];
bool vis[maxn];
int num[maxn << 1];
int sum[maxn << 3];

void init() {
	memset(num, 0, sizeof(num));
	memset(sum, 0, sizeof(sum));
	memset(vis, false, sizeof(vis));
}

void pushdown(int root) {
	if(sum[root]) {
		sum[root << 1] = sum[root << 1 | 1] = sum[root];
		sum[root] = 0;
	}
}

void update(int left, int right, int prel, int prer, int val, int root) {
	if(prel <= left && right <= prer) {
		sum[root] = val;
		return ;
	}
	pushdown(root);
	int mid = (left + right) >> 1;
	if(prel <= mid)
		update(left, mid, prel, prer, val, root << 1);
	if(prer > mid)
		update(mid + 1, right, prel, prer, val, root << 1 | 1);
}

void query(int left, int right, int prel, int prer, int root) {
	if(left == right) {
		if(sum[root])
			vis[sum[root]] = true;
		return ;
	}
	pushdown(root);
	int mid = (left + right) >> 1;
	if(prel <= mid)
		query(left, mid, prel, prer, root << 1);
	if(prer > mid)
		query(mid + 1, right, prel, prer, root << 1 | 1);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &m);
		n = 0;
		for(int i=1; i<=m; i++) {
			scanf("%d%d", &node[i].l, &node[i].r);
			num[n++] = node[i].l;
			num[n++] = node[i].r;
		}
		sort(num, num+n);
		n = unique(num, num+n) - num;
		for(int i=1; i<=m; i++) {
			int prel, prer, val;
			prel = lower_bound(num, num+n, node[i].l) - num + 1;
			prer = lower_bound(num, num+n, node[i].r) - num + 1;
			val = i;
			printf("%d %d %d\n", prel, prer, val);
			update(1, n, prel, prer, val, 1);
		}
		query(1, n, 1, n, 1);
		int ans = 0;
		for(int i=1; i<=m; i++) {
			if(vis[i])
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}