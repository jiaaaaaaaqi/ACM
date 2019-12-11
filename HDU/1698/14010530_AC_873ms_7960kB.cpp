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
using namespace std;

const int maxn = 400005;

int n, m;
ll node[maxn];
ll add[maxn];

void init() {
	memset(add, 0, sizeof(add));
	memset(node, 0, sizeof(node));
}

void pushdown(int root, int num) {
	if(add[root]) {
		add[root << 1] = add[root];
		add[root << 1 | 1] = add[root];
		node[root << 1] = add[root] * (num - (num >> 1));
		node[root << 1 | 1] = add[root] * (num >> 1);
		add[root] = 0;
	}
	return ;
}

void pushup(int root) {
	node[root] = node[root << 1] + node[root << 1 | 1];
}

void build(int left, int right, int root) {
	if(left == right) {
		node[root] = 1;
		return ;
	}
	ll mid = (left + right) >> 1;
	build(left, mid, root << 1);
	build(mid + 1, right, root << 1 | 1);
	pushup(root);
}

void update(int left, int right, int prel, int prer, int val, int root) {
	if(prel <= left && prer >= right) {
		node[root] = (ll)val * (right - left + 1);
		add[root] = (ll)val;
		return ;
	}
	pushdown(root, right - left + 1);
	int mid = (left + right) >> 1;
	if(prel <= mid)
		update(left, mid, prel, prer, val, root << 1);
	if(prer > mid)
		update(mid + 1, right, prel, prer, val, root << 1 | 1);
	pushup(root);
	return ;
}

ll query(int left, int right, int prel, int prer, int root) {
	if(prel <= left && prer >= right)
		return node[root];
	pushdown(root, right - left + 1);
	int mid = (left + right) >> 1;
	ll ans = 0;
	if(prel <= mid)
		ans += query(left, mid, prel, prer, root << 1);
	if(prer > mid)
		ans += query(mid + 1, right, prel, prer, root << 1 | 1);
	return ans;
}

int main() {
	int T;
	int cas = 1;
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d", &n);
		build(1, n, 1);
		scanf("%d", &m);
		while(m--) {
			int prel, prer, val;
			scanf("%d%d%d", &prel, &prer, &val);
			update(1, n, prel, prer, val, 1);
		}
		ll ans = query(1, n, 1, n, 1);
		printf("Case %d: The total value of the hook is %lld.\n", cas++, ans);
	}
	return 0;
}
