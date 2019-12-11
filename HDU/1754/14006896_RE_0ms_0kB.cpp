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

const int maxn = 800005;

int n;
int node[maxn];

void init() {
	memset(node, 0, sizeof(node));
}

void build(int left, int right, int root) {
	if(left == right) {
		scanf("%d", &node[root]);
		return ;
	}
	int mid = (left + right) >> 1;
	build(left, mid, root << 1);
	build(mid + 1, right, root << 1 + 1);
	node[root] = max(node[root << 1], node[root << 1 + 1]);
}

void update(int left, int right, int pos, int val, int root) {
	if(left == right) {
		node[root] = val;
		return ;
	}
	int mid = (left + right) >> 1;
	if(pos <= mid) {
		update(left, mid, pos, val, root << 1);
	} else {
		update(mid+1, right, pos, val, root << 1 + 1);
	}
	node[root] = max(node[root << 1], node[root << 1 + 1]);
}

int query(int left, int right, int prel, int prer, int root) {
	if(prel <= left && prer >= right)
		return node[root];
	int mid = (left + right) >> 1;
	int ans = 0;
	if(prel <= mid)
		ans = max(ans, query(left, mid, prel, prer, root << 1));
	else
		ans = max(ans, query(mid + 1, right, prel, prer, root << 1 + 1));
	return ans;
}

int main() {
	int m;
	while(~scanf("%d%d", &n, &m)) {
		init();
		build(1, n, 1);
		while(m--) {
			char str[5];
			int u, v;
			scanf("%s%d%d", str, &u, &v);
			if(str[0] == 'Q') {
				int ans = query(1, n, u, v, 1);
				printf("%d\n", ans);
			}
			if(str[0] == 'U') {
				update(1, n, u, v, 1);
			}
		}
	}
	return 0;
}
