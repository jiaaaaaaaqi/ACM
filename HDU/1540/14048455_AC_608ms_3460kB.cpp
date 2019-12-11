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

int n, m;
int maxsum[maxn << 2];
int minsum[maxn << 2];
int des[maxn];

void init() {
	memset(des, 0, sizeof(des));
	memset(maxsum, 0, sizeof(maxsum));
	memset(minsum, 0, sizeof(minsum));
}

void pushup_max(int root) {
	maxsum[root] = max(maxsum[root << 1], maxsum[root << 1 | 1]);
}

void pushup_min(int root) {
	minsum[root] = min(minsum[root << 1], minsum[root << 1 | 1]);
}

void build(int left, int right, int root) {
	if(left == right) {
		maxsum[root] = 0;
		minsum[root] = n + 1;
		return ;
	}
	int mid = (left + right) >> 1;
	build(left, mid, root << 1);
	build(mid + 1, right, root << 1 | 1);
	pushup_max(root);
	pushup_min(root);
}

void update_max(int left, int right, int pos, int val, int root) {
	if(left == right) {
		maxsum[root] = val;
		return ;
	}
	int mid = (left + right) >> 1;
	if(pos <= mid)
		update_max(left, mid, pos, val, root << 1);
	else
		update_max(mid + 1, right, pos, val, root << 1 | 1);
	pushup_max(root);
}

void update_min(int left, int right, int pos, int val, int root) {
	if(left == right) {
		minsum[root] = val;
		return ;
	}
	int mid = (left + right) >> 1;
	if(pos <= mid)
		update_min(left, mid, pos, val, root << 1);
	else
		update_min(mid + 1, right, pos, val, root << 1 | 1);
	pushup_min(root);
}

int query_max(int left, int right, int prel, int prer, int root) {
	if(prel <= left && right <= prer) {
		return maxsum[root];
	}
	int mid = (left + right) >> 1;
	int ans = 0;
	if(prel <= mid)
		ans = max(ans, query_max(left, mid, prel, prer, root << 1));
	if(prer > mid)
		ans = max(ans, query_max(mid + 1, right, prel, prer, root << 1 | 1));
	return ans;
}

int query_min(int left, int right, int prel, int prer, int root) {
	if(prel <= left && right <= prer) {
		return minsum[root];
	}
	int mid = (left + right) >> 1;
	int ans = n + 1;
	if(prel <= mid)
		ans = min(ans, query_min(left, mid, prel, prer, root << 1));
	if(prer > mid)
		ans = min(ans, query_min(mid + 1, right, prel, prer, root << 1 | 1));
	return ans;
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		init();
		build(1, n, 1);
		int tol = 0;
		while(m--) {
			char str[5];
			scanf("%s", str);
			if(str[0] == 'D') {
				int pos;
				scanf("%d", &pos);
				des[tol++] = pos;
				update_max(1, n, pos, pos, 1);
				update_min(1, n, pos, pos, 1);
			} else if(str[0] == 'Q') {
				int pos;
				scanf("%d", &pos);
				int ans1 = query_max(1, n, 1, pos, 1);
				int ans2 = query_min(1, n, pos, n, 1);
//				printf("ans1 = %d ans2 = %d\n", ans1, ans2);
				if(ans1 == ans2)
					printf("0\n");
				else
					printf("%d\n", ans2 - ans1 - 1);
			} else {
				int pos = des[--tol];
				update_max(1, n, pos, 0, 1);
				update_min(1, n, pos, n + 1, 1);
			}
		}
	}
	return 0;
}
