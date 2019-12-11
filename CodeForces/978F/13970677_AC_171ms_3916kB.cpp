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

typedef long long int ll;
using namespace std;

const int maxn = 200005;

struct Node {
	int num;
	int id;
	int cnt;
	bool operator < (Node b) const {
		if(num == b.num)
			return id < b.id;
		return num < b.num;
	}
};
Node node[maxn];
int ans[maxn];
int pre[maxn];

void init() {
	memset(pre, 0, sizeof(pre));
	memset(ans, 0, sizeof(ans));
	memset(node, 0, sizeof(node));
}

int main() {
	init();
	int n, m;
	while(~scanf("%d%d", &n, &m)) {
		for(int i=1; i<=n; i++) {
			scanf("%d", &node[i].num);
			node[i].id = i;
		}
		sort(node+1, node+1+n);
		node[1].cnt = 0;
		for(int i=2; i<=n; i++) {
			if(node[i-1].num < node[i].num) {
				node[i].cnt = i - 1;
			} else {
				node[i].cnt = node[i-1].cnt;
			}
		}
		for(int i=1; i<=n; i++) {
			ans[node[i].id] = node[i].cnt;
		}
		/*
		for(int i=1; i<=n; i++) {
			printf("id = %d cnt = %d\n", node[i].id, node[i].cnt);
		}
		*/
		memcpy(pre, ans, sizeof(ans));
		for(int i=0; i<m; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			if(pre[x] == pre[y])
				continue;
			else if(pre[x] < pre[y])
				ans[y]--;
			else
				ans[x]--;
		}
		for(int i=1; i<=n; i++) {
			printf("%d%c", ans[i], i==n ? '\n' : ' ');
		}
	}
	return 0;
}