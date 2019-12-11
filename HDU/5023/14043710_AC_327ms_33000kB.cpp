#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
const int inf = 0x3f3f3f3f;
const int maxn = 1000005;

int n, m;
int sum[maxn << 2];
int lazy[maxn << 2];

void init() {
	memset(sum, 0, sizeof(sum));
	memset(lazy, 0, sizeof(lazy));
}

void pushup(int root) {
	sum[root] = sum[root << 1] | sum[root << 1 | 1];
}

void pushdown(int root) {
	if(lazy[root]) {
		lazy[root << 1] = lazy[root << 1 | 1] = lazy[root];
		sum[root << 1] = sum[root << 1 | 1] = lazy[root];
		lazy[root] = 0;
	}
}

void build(int left, int right, int root) {
	if(left == right) {
		sum[root] = 2;
		return ;
	}
	int mid = (left + right) >> 1;
	build(left, mid, root << 1);
	build(mid + 1, right, root << 1 |1);
	pushup(root);
}

void update(int left, int right, int prel, int prer, int val, int root) {
	if(prel <= left && right <= prer) {
		lazy[root] = 1 << (val - 1);
		sum[root] = 1 << (val - 1);
		return ;
	}
	pushdown(root);
	int mid = (left + right) >> 1;
	if(prel <= mid)
		update(left, mid, prel, prer, val, root << 1);
	if(prer > mid)
		update(mid + 1, right, prel, prer, val, root << 1 | 1);
	pushup(root);
}

int query(int left, int right, int prel, int prer, int root) {
	if(prel <= left && right <= prer) {
		return sum[root];	
	}
	pushdown(root);
	int mid = (left + right) >> 1;
	int ans = 0;
	if(prel <= mid)
		ans |= query(left, mid, prel, prer, root << 1);
	if(prer > mid)
		ans |= query(mid + 1, right, prel, prer, root << 1 | 1);
	return ans;
}

void calc(int num) {
	int ans[35];
	memset(ans, 0, sizeof(ans));
	int pos = 1;
	int tol = 0;
	while(num) {
		if(num & 1) {
			ans[tol++] = pos;
		}
		pos++;
		num >>= 1;
	}
	sort(ans, ans+tol);
	for(int i=0; i<tol; i++) {
		printf("%d%c", ans[i], i == tol - 1 ? '\n' : ' ');
	}
}

int main() {
	while(scanf("%d%d", &n, &m), n||m) {
		init();
		build(1, n, 1);
		while(m--) {
			char str[5];
			scanf("%s", str);
			if(str[0] == 'P') {
				int prel, prer, val;
				scanf("%d%d%d", &prel, &prer, &val);
				update(1, n, prel, prer, val, 1);
			} else if(str[0] == 'Q') {
				int prel, prer;
				scanf("%d%d", &prel, &prer);
				int ans = query(1, n, prel, prer, 1);
				calc(ans);
			}
		}
	}
	return 0;
}