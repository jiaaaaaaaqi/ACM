#include<map>
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

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 100010;
const int maxm = 1000;
using namespace std;

int mod;
int n, m;
ll sum[maxn << 2];

void pushup(int root) {
	sum[root] = sum[root << 1] * sum[root << 1 | 1] % mod;
}

void build(int left, int right, int root) {
	if(left == right) {
		sum[root] = 1;
		return ;
	}
	int mid = (left + right) >> 1;
	build(left, mid, root << 1);
	build(mid + 1, right, root << 1 | 1);
	pushup(root);
}

void update(int left, int right, int pos, int val, int root) {
	if(left == right) {
		sum[root] = val;
		return ;
	}
	int mid = (left + right) >> 1;
	if(pos <= mid)	update(left, mid, pos, val, root << 1);
	else	update(mid + 1, right, pos, val, root << 1 | 1);
	pushup(root);
}

int query(int left, int right, int prel, int prer, int root) {

}

int main() {
	int T;
	int cas = 1;
	scanf("%d", &T);
	while(T--) {
		printf("Case #%d:\n", cas++);
		memset(sum, 0, sizeof(sum));
		scanf("%d%d", &n, &mod);
		build(1, n, 1);
		int id, val;
		for(int i=1; i<=n; i++) {
			scanf("%d%d", &id, &val);
			if(id == 1) {
				update(1, n, i, val, 1);
			} else if(id == 2) {
				update(1, n, val, 1, 1);
			}
			printf("%lld\n", sum[1]);
		}
	}
	return 0;
}
