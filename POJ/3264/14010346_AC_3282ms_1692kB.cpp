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
int ans1, ans2;
int maxnode[maxn];
int minnode[maxn];

void init() {
	memset(maxnode, 0, sizeof(maxnode));
	memset(minnode, 0, sizeof(minnode));
}

void pushup(int root) {
	maxnode[root] = max(maxnode[root << 1], maxnode[root << 1 | 1]);
	minnode[root] = min(minnode[root << 1], minnode[root << 1 | 1]);
}

void build(int left, int right, int root) {
	if(left == right) {
		scanf("%d", &maxnode[root]);
		minnode[root] = maxnode[root];
		return ;
	}
	int mid = (left + right) >> 1;
	build(left, mid, root << 1);
	build(mid + 1, right, root << 1 | 1);
	pushup(root);
}

void query(int left, int right, int prel, int prer, int root) {
	if(prel <= left && prer >= right) {
		ans1 = max(ans1, maxnode[root]);
		ans2 = min(ans2, minnode[root]);
		return ;
	}
	int mid = (left + right) >> 1;
	if(prel <= mid) 
		query(left, mid, prel, prer, root << 1);
	if(prer > mid)
		query(mid + 1, right, prel, prer, root << 1 | 1);
	return ;
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		build(1, n, 1);
		while(m--) {
			ans1 = -inf;
			ans2 = inf;
			int prel, prer;
			scanf("%d%d", &prel, &prer);
			query(1, n, prel, prer, 1);
			printf("%d\n", ans1 - ans2);
		}
	}
	return 0;
}
