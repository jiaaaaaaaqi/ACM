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
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 100005;
const int maxm = 100005;
const int mod = 1000000007;
using namespace std;

int n, m, tol;
int block;
struct Node {
    int l, r, id;
    bool operator < (Node a) const{
        return l/block == a.l/block ? r < a.r : l/block < a.l/block;
    }
};
Node node[maxn];
ll ans;
int a[maxn];
int p[maxn];
int cnt[maxn];
ll res[maxn];

void init() {
	ans = 0;
	memset(a, 0, sizeof a);
	memset(p, 0, sizeof p);
	memset(cnt, 0, sizeof cnt);
	memset(res, 0, sizeof res);
	memset(node, 0, sizeof node);
}

void add(int x) {
	ans -= cnt[a[x]] * cnt[a[x]] * cnt[a[x]];
	cnt[a[x]]++;
	ans += cnt[a[x]] * cnt[a[x]] * cnt[a[x]];
}

void del(int x) {
	ans -= cnt[a[x]] * cnt[a[x]] * cnt[a[x]];
	cnt[a[x]]--;
	ans += cnt[a[x]] * cnt[a[x]] * cnt[a[x]];
}

int main() {
    while(~scanf("%d", &n)) {
		init();
		for(int i=1; i<=n; i++)	{
			scanf("%d", &a[i]);
			p[i] = a[i];
		}
		sort(p+1, p+1+n);
		int nn = unique(p+1, p+1+n) - (p+1);
		for(int i=1; i<=n; i++)	a[i] = lower_bound(p+1, p+1+nn, a[i]) - p;
		block = sqrt(n);
		scanf("%d", &m);
		for(int i=1; i<=m; i++) {
			scanf("%d%d", &node[i].l, &node[i].r);
			node[i].id = i;
		}
		sort(node+1, node+1+m);
		int L = 1;
		int R = 0;
		for(int i=1; i<=m; i++) {
			while(L > node[i].l)
				add(--L);
			while(R < node[i].r)
				add(++R);
			while(L < node[i].l) 
				del(L++);
			while(R > node[i].r)
				del(R--);
			res[node[i].id] = ans;
		}
		for(int i=1; i<=m; i++)	printf("%lld\n", res[i]);
    }
    return 0;
}
