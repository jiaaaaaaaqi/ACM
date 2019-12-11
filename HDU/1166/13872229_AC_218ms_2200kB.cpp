#include<map>
#include<queue>
#include<string>
#include<vector>
#include<math.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define inf 0x3f3f3f3f

typedef long long int ll;
using namespace std;

const int maxn = 50005 * 4;

int n;
int node[maxn];

void init() {
	memset(node, 0, sizeof(node));
}

void build(int l, int r, int root) {
	if(l == r) {
		scanf("%d", &node[root]);
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, root * 2);
	build(mid + 1, r, root * 2 + 1);
	node[root] = node[root * 2] + node[root * 2 + 1];
}

void update(int pos, int val, int l, int r, int root) {
	if(l == r) {
		node[root] += val;
		return ;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid)
		update(pos, val, l, mid, root * 2);
	else
		update(pos, val, mid + 1, r, root * 2 + 1);
	node[root] = node[root * 2] + node[root * 2 + 1];
}

int query(int be, int ed, int l, int r, int root) {
	if(be <= l && ed >= r) {
		return node[root];
	}
	int mid = (l + r) >> 1;
	int ans = 0;
	if(be <= mid) 
		ans += query(be, ed, l, mid, root * 2);
	if(ed > mid)
		ans += query(be, ed, mid + 1, r, root * 2 + 1);
	return ans;
}

int main() {
	int T;
	int cas = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		build(1, n, 1);
		printf("Case %d:\n", cas++);
		while(1) {
			char str[10];
			scanf("%s", str);
			if(str[0] == 'E') {
				break;
			} else if(str[0] == 'A') {
				int pos, val;
				scanf("%d%d", &pos, &val);
				update(pos, val, 1, n, 1);
			} else if(str[0] == 'S') {
				int pos, val;
				scanf("%d%d", &pos, &val);
				update(pos, -val, 1, n, 1);				
			} else if(str[0] == 'Q') {
				int be, ed;
				scanf("%d%d", &be, &ed);
				int ans = query(be, ed, 1, n, 1);
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}