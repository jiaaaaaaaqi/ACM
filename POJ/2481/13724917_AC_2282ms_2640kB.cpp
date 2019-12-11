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

const int maxn = 1e5+5;

struct Node{
	int l;
	int r;
	int id;
}node[maxn];
int sum[maxn];
int ans[maxn];
int maxpos, n;

void init() {
	maxpos = 0;
	memset(sum, 0, sizeof sum);
	memset(ans, 0, sizeof ans);
	memset(node, 0, sizeof node);
}

bool cmp(Node a, Node b) {
	if(a.r == b.r)
		return a.l < b.l;
	return a.r > b.r;
}

int lowbit(int x) {
	return x & (-x);
}

void update(int pos, int val) {
	while(pos <= n) {
		sum[pos] += val;
		pos += lowbit(pos);
	}
}

int query(int pos) {
	int ans = 0;
	while(pos > 0) {
		ans += sum[pos];
		pos -= lowbit(pos);
	}
	return ans;
} 

int main() {
	while(scanf("%d", &n), n) {
		init();
		for(int i=1; i<=n; i++) {
			scanf("%d%d", &node[i].l, &node[i].r);
			node[i].l++;
			node[i].id = i;
		}
		sort(node+1, node+1+n, cmp);
		for(int i=1; i<=n; i++) {
			if(node[i].l == node[i-1].l && node[i].r == node[i-1].r) {
				ans[node[i].id] = ans[node[i-1].id];
			} else {
				int res = query(node[i].l);
				ans[node[i].id] = res;
			}
			update(node[i].l, 1);
		}
		for(int i=1; i<=n; i++) {
			printf("%d%c", ans[i], i==n ? '\n' : ' ');
		}
	}
	return 0; 
}