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
const int maxn = 100005;

int n, m;
ll sum[maxn << 2];

void init() {
	memset(sum, 0, sizeof(sum));
}

void pushup(int root) {
	sum[root] = sum[root << 1] + sum[root << 1 | 1];
}

void build(int left, int right, int root) {
	if(left == right) {
		scanf("%lld", &sum[root]);
		return ;
	}
	int mid = (left + right) >> 1;
	build(left, mid, root << 1);
	build(mid + 1, right, root <<1 | 1);
	pushup(root);
}

void update(int left, int right, int prel, int prer, int root) {
	if(sum[root] == (right - left + 1))
		return ;
	if(left == right) {
		sum[root] = sqrt(1.0 * sum[root]);
		return ;
	}
	int mid = (left + right) >> 1;
	if(prel <= mid)
		update(left, mid, prel, prer, root << 1);
	if(prer > mid)
		update(mid + 1, right, prel, prer, root << 1 | 1);
	pushup(root);
}

ll query(int left, int right, int prel, int prer, int root) {
	if(prel <= left && right <= prer) {
		return sum[root];
	}
	int mid = (left + right) >> 1;
	ll ans = 0;
	if(prel <= mid)
		ans += query(left, mid, prel, prer, root << 1);
	if(prer > mid)
		ans += query(mid + 1, right, prel, prer, root << 1 | 1);
	return ans;
}

int main() {
	int cas = 1;
	while(~scanf("%d", &n)) {
		printf("Case #%d:\n", cas++);
		init();
		build(1, n, 1);
		scanf("%d", &m);
		while(m--) {
			int x;
			scanf("%d", &x);
			if(x == 0) {
				int prel, prer;
				scanf("%d%d", &prel, &prer);
				if(prel > prer)	swap(prel, prer);
				update(1, n, prel, prer, 1);
			} else if(x == 1) {
				int prel, prer;
				scanf("%d%d", &prel, &prer);
				if(prel > prer)	swap(prel, prer);
				ll ans = query(1, n, prel, prer, 1);
				printf("%lld\n", ans);
			}
		}
		printf("\n");
	}
	return 0;
}
