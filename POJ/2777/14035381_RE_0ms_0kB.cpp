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
const int maxn = 110000;
using namespace std;

int n, m;
int sum[maxn << 2];
int col[maxn << 2];

void init() {
	memset(sum, 0, sizeof(sum));
	memset(col, 0, sizeof(col));
}

void pushdown(int root) {
	if(col[root]) {
		col[root << 1] = col[root << 1 | 1] = col[root];
		sum[root << 1] = sum[root << 1 | 1] = col[root];
		col[root] = 0;
	}
}

void pushup(int root) {
	sum[root] = sum[root << 1] | sum[root << 1 | 1];
}

void build(int left, int right, int root) {
	if(left == right) {
		sum[root] = 1;
		return ;
	}
	int mid = (left + right) >> 1;
	build(left, mid, root << 1);
	build(mid + 1, right, root << 1 | 1);
	pushup(root);
}

void update(int left, int right, int prel, int prer, int val, int root) {
	if(left <= prel && right <= prer) {
		sum[root] = 1 << (val - 1);
		col[root] = 1 << (val - 1);
		return ;
	}
	if(left > prer || right < prel)
		return ;
	pushdown(root);
	int mid = (left + right) >> 1;
//	if(prel <= mid)
	update(left, mid, prel, prer, val, root << 1);
//	if(prer > mid)
	update(mid + 1, right, prel, prer, val, root << 1 | 1);
	pushup(root);
}

int query(int left, int right, int prel, int prer, int root) {
	if(left <= prel && prer <= right) {
		return sum[root];
	}
	if(left > prer || right < prel)
		return 0;
	pushdown(root);
	int mid = (left + right) >> 1;
//	int ans = 0;
//	if(prel <= mid)
//		ans |= query(left, mid, prel, prer, root << 1);
//	if(prer > mid)
//		ans |= query(mid + 1, right, prel, prer, root << 1 | 1);
	int ans = query(left, mid, prel, prer, root << 1) | query(mid + 1, right, prel, prer, root << 1 | 1);
	return ans;
}

int calc(int num) {
	int ans = 0;
	while(num) {
		if(num & 1)
			ans++;
		num >>= 1;
	}
	return ans;
}

int main() {
	int conum;
	while(~scanf("%d%d%d", &n, &conum, &m)) {
		build(1, n, 1);
		while(m--) {
			char str[5];
			scanf("%s", str);
			if(str[0] == 'C') {
				int prel, prer, val;
				scanf("%d%d%d", &prel, &prer, &val);
				if(prel > prer)		swap(prel, prer);
				update(1, n, prel, prer, val, 1);
			} else {
				int prel, prer;
				scanf("%d%d", &prel, &prer);
				if(prel > prer)		swap(prel, prer);
				int ans = query(1, n, prel, prer, 1);
				ans = calc(ans);
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}