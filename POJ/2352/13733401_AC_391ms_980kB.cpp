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

const int maxn = 15005;
const int maxm = 32005;

struct Node{
	int l;
	int r;
}node[maxn];
int sum[maxm];
int ans[maxn];
int n;
int maxpos;

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
	while(pos <= maxpos) {
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
	while(~scanf("%d", &n)) {
		init();
		for(int i=1; i<=n; i++) {
			scanf("%d%d", &node[i].l, &node[i].r);
			node[i].l++;
			maxpos = max(maxpos, node[i].l);
		}
		for(int i=1; i<=n; i++) {
			int res = query(node[i].l);
			ans[res]++;
			update(node[i].l, 1);
			/*
			for(int j=0; j<maxpos; j++) {
				printf("%d ", sum[j]);
			}
			printf("\n");
			*/
		}
		for(int i=0; i<n; i++) {
			printf("%d\n", ans[i]);
		}
	}
	return 0; 
}

