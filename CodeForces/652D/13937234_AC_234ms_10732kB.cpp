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

const int maxn = 1e5 * 4 + 5;
const int maxm = 1e5 * 2 + 5;

struct Node {
	int l;
	int r;
	int id;
} node[maxm];
int num[maxn];
int sum[maxn];
int ans[maxn];
int maxpos, n;
int nss;
void init() {
	maxpos = 0;
	memset(sum, 0, sizeof sum);
	memset(ans, 0, sizeof ans);
	memset(node, 0, sizeof node);
}

bool cmp(Node a, Node b) {
	if(a.l == b.l)
		return a.r < b.r;
	return a.l > b.l;
}

int lowbit(int x) {
	return x & (-x);
}

void update(int pos, int val) {
	while(pos <= nss) {
		sum[pos] += val;
		pos += lowbit(pos);
	}
}

int query(int pos) {
	int ans = 0;
	while(pos > 0) {
		ans += sum[pos];
		pos -= lowbit(pos);
		//printf("* %d\n",pos);
	}
	return ans;
}

int main() {
	while(~scanf("%d", &n)) {
		init();
		nss=0;
		int tol = 0;
		for(int i=1; i<=n; i++) {
			scanf("%d%d", &node[i].l, &node[i].r);
			num[tol++] = node[i].l;
			num[tol++] = node[i].r;
			node[i].id = i;
		}
		sort(node+1, node+n+1, cmp);
		sort(num, num+tol);
		int tol1 = unique(num, num+tol) - num;
		for(int i=1; i<=n; i++) {
			node[i].l = lower_bound(num, num+tol1, node[i].l) - num + 1;
			node[i].r = lower_bound(num, num+tol1, node[i].r) - num + 1;
			nss = max(nss, node[i].r);
		}
		/*
		for(int i=1; i<=n; i++) {
			printf("%d  %d\n", node[i].l, node[i].r);
		}
		*/
		for(int i=1; i<=n; i++) {
			int res = query(node[i].r);
//			printf("%d %d   %d\n",node[i].l,node[i].r,res);
			ans[node[i].id] = res;
			update(node[i].r, 1);
		}

		for(int i=1; i<=n; i++) {
			printf("%d\n", ans[i]);
		}

	}
	return 0;
}