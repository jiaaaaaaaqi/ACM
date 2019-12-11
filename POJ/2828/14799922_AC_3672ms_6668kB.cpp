#include<map>
#include<set>
#include<ctime>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define first fi
#define second se
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 220005;
const int maxm = 305;
using namespace std;

int n, m, tol, T;
struct Node{
	int k, val;
};
Node node[maxn];
int pos;
int ans[maxn];
int sum[maxn << 2];

void init() {
	memset(ans, 0, sizeof ans);
	memset(sum, 0, sizeof sum);
	memset(node, 0, sizeof node);
}

void pushup(int root) {
	sum[root] = sum[root << 1] + sum[root << 1 | 1];
}

void build(int left, int right, int root) {
	if(left == right) {
		sum[root] = 1;
		return ;
	}
	int mid = (left + right) >> 1;
	build(left, mid, root << 1);
	build(mid+1, right, root << 1 | 1);
	pushup(root);
}

void update(int left, int right, int k, int val, int root) {
	if(left == right) {
		sum[root]--;
		ans[left] = val;
		return ;
	}
	int mid = (left + right) >> 1;
	if(sum[root<<1] >= k)	update(left, mid, k, val, root << 1);
	else	update(mid+1, right, k-sum[root<<1], val, root << 1 | 1);
	pushup(root);
}

int main() {
	while(~scanf("%d", &n)) {
		init();
		build(1, n, 1);
		for(int i=1; i<=n; i++)	scanf("%d%d", &node[i].k, &node[i].val);
		for(int i=n; i>=1; i--) {
			int k = node[i].k + 1;
			int val = node[i].val;
			update(1, n, k, val, 1);
		}
		for(int i=1; i<=n; i++)	printf("%d%c", ans[i], i==n ? '\n' : ' ');
	}
	return 0;
}
