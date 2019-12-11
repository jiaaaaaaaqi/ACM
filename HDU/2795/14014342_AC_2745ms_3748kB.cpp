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

const int maxn = 200005;

int n, w, h;
int node[maxn << 2];

void pushup(int root) {
	node[root] = max(node[root << 1], node[root << 1 | 1]);
}

void build(int left, int right, int root) {
	if(left == right) {
		node[root] = w;
		return ;
	}
	int mid = (left + right) >> 1;
	build(left, mid, root << 1);
	build(mid + 1, right, root << 1 | 1);
	pushup(root);
}

int query(int left, int right, int val, int root) {
	if(left == right) {
		node[root] -= val;
		return left;
	}
	int mid = (left + right) >> 1;
	int ans;
	if(node[root << 1] >= val) 
		ans = query(left, mid, val, root << 1);
	else
		ans = query(mid + 1, right, val, root << 1 | 1);
	pushup(root);
	return ans;
}

int main() {
	while(~scanf("%d%d%d", &h, &w, &n)) {
		if(h > n)
			h = n;
		build(1, h, 1);
		while(n--) {
			int val;
			scanf("%d", &val);
			if(node[1] < val) {
				printf("-1\n");
			} else {
				int ans = query(1, h, val, 1);
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}
