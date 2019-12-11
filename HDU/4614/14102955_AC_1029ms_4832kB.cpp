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
const int maxn = 50005;
const int mod = 10007;

int n, m;
ll sum[maxn << 2];
ll lazy[maxn << 2];

void init() {
	memset(sum, 0, sizeof(sum));
	memset(lazy, 0, sizeof(lazy));
}

void pushup(int root) {
	sum[root] = sum[root << 1] + sum[root << 1 | 1];
}

void build(int left, int right, int root) {
	lazy[root] = -1;
	if(left == right) {
		sum[root] = 0;
		return ;
	}
	int mid = (left + right) >> 1;
	build(left, mid, root << 1);
	build(mid + 1, right, root << 1 | 1);
	pushup(root);
	return ;
}

void pushdown(int root, int lnum, int rnum) {
	if(lazy[root] >= 0) {
		lazy[root << 1] = lazy[root << 1 | 1] = lazy[root];
		sum[root << 1] = lnum * lazy[root];
		sum[root << 1 | 1] = rnum * lazy[root];
		lazy[root] = -1;
	}
	return ;
}

void update(int left, int right, int prel, int prer, int root, int val) {
	if(prel <= left && right <= prer) {
		lazy[root] = val;
		sum[root] = (right - left + 1) * val;
		return ;
	}
	int mid = (left + right) >> 1;
	pushdown(root, mid - left + 1, right - mid);
	if(prel <= mid)
		update(left, mid, prel, prer, root << 1, val);
	if(prer > mid)
		update(mid + 1, right, prel, prer, root << 1 | 1, val);
	pushup(root);
	return ;
}

ll query(int left, int right, int prel, int prer, int root) {
	if(prel <= left && right <= prer) {
		return sum[root];
	}
	int mid = (left + right) >> 1;
	pushdown(root, mid - left + 1, right - mid);
	ll ans = 0;
	if(prel <= mid)
		ans += query(left, mid, prel, prer, root << 1);
	if(prer > mid)
		ans += query(mid + 1, right, prel, prer, root << 1 | 1);
	return ans;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d%d", &n, &m);
		build(1, n, 1);
		while(m--) {
			int id;
			scanf("%d", &id);
			if(id == 1) {
				int pos, num;
				scanf("%d%d", &pos, &num);
				pos++;
				int t = query(1, n, pos, n, 1);
				if(t == n - pos + 1) {
					printf("Can not put any one.\n");
					continue;
				}
				int l = pos, r = n;
				num = min(num, n - pos + 1 - t);
				while(l < r) {
					int m = (l + r) >> 1;
					int t1 = query(1, n, l, m, 1);
					if(t1 == m - l + 1)
						l = m + 1;
					else
						r = m;
				}
				printf("%d ", l - 1);
				l = pos, r = n;
				while(l < r) {
					int m = (l + r) >> 1;
					int t1 = query(1, n, pos, m, 1);
					if(m - pos + 1 - t1 >= num)
						r = m;
					else
						l = m + 1;
				}
				printf("%d\n", l - 1);
				update(1, n, pos, l, 1, 1);
			} else if(id == 2) {
				int prel, prer;
				scanf("%d%d", &prel, &prer);
				prel++;
				prer++;
				ll ans = query(1, n, prel, prer, 1);
				printf("%lld\n", ans);
				update(1, n, prel, prer, 1, 0);
			}
		}
		printf("\n");
	}
	return 0;
}