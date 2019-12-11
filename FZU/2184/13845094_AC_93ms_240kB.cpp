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

const int maxn = 1005;

int n;
int res[maxn];
int ans[maxn];
int pre[maxn];
bool vis[maxn];

void init() {
	memset(res, 0, sizeof(res));
	memset(ans, 0, sizeof(ans));
	memset(pre, 0, sizeof(pre));
	memset(vis, false, sizeof(vis));
}

int lowbit(int x) {
	return x & (-x);
}

void update(int pos, int val) {
	while(pos <= n) {
		res[pos] += val;
		pos += lowbit(pos);
	}
}

int query(int pos) {
	int ans = 0;
	while(pos > 0) {
		ans += res[pos];
		pos -= lowbit(pos);
	}
	return ans;
}
/*
int find(int val) {
	int left = 1;
	int right = n;
	while(left <= right) {
		int mid = (left + right) >> 1;
		while(vis[mid])
			mid++;
		int x = query(mid);
		if(x == val)
			return mid;
		if(x > val) {
			right = mid - 1;
		} else if(x < val) {
			left = mid + 1;
		}
	}
}
*/

int find(int val) {
	for(int i=1; i<=n; i++) {
		if(vis[i])
			continue;
		int x = query(i);
		if(x == val)
			return i;
	}
}
int main() {
	while(~scanf("%d", &n)) {
		init();
		for(int i=2; i<=n; i++) {
			update(i, 1);
		}
		for(int i=1; i<=n; i++) {
			scanf("%d", &pre[i]);
		}
		for(int i=1; i<=n; i++) {
			int x = find(pre[i]);
			ans[i] = x;
			vis[x] = true;
			update(x, -1);
		}
		for(int i=1; i<=n; i++) {
			printf("%d%c", ans[i], i==n ? '\n' : ' ');
		}
	}
	return 0;
}
