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

typedef unsigned long long int ull;
typedef long long int ll;
const int inf = 0x3f3f3f3f;
const int maxn = 8003;
using namespace std;

int n, m, last;
int sum[maxn << 2];
int ans[maxn];

void init() {
	memset(sum, 0, sizeof(sum));
	memset(ans, 0, sizeof(ans));
}

void pushup(int root) {
	if(sum[root << 1] != 0 && sum[root << 1 | 1] != 0 && sum[root << 1] == sum[root << 1 | 1])
		sum[root] = sum[root << 1];
	else
		sum[root] = 0;
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
	pushup(root);
}

void query(int left, int right, int prel, int prer, int root) {
	if(left == right) {
		if(sum[root] && sum[root] != last)
			ans[sum[root]]++;
		last = sum[root];
		return ;
	}
	pushdown(root);
	int mid = (left + right) >> 1;
	if(prel <= mid)
		query(left, mid, prel, prer, root << 1);
	if(prer > mid)
		query(mid + 1, right, prel, prer, root << 1 | 1);
	pushup(root);
}

int main() {
	while(~scanf("%d", &m)) {
		init();
		n = 8000;
		while(m--) {
			int prel, prer, val;
			scanf("%d%d%d", &prel, &prer, &val);
			if(prel < prer)
				update(1, n, prel+1, prer, val+1, 1);
		}
		last = 0;
		query(1, n, 1, n, 1);
		for(int i=1; i<=n+1; i++) {
			if(ans[i]) {
				printf("%d %d\n", i-1, ans[i]);
			}
		}
		printf("\n");
	}
	return 0;
}