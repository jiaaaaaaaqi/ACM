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
const int maxn = 30005;
const int maxm = 30005;
const int mod = 1000000007;
using namespace std;

int n, m, tol;
int block;
struct Node {
    int l, r, id, f;
    bool operator < (Node a) const{
        return l/block == a.l/block ? r < a.r : l/block < a.l/block;
    }
};
Node node[maxn << 2];
ll ans;
int a[maxn];
ll res[maxn];
ll cnt[maxn];

void init() {
	memset(a, 0, sizeof a);
	memset(res, 0, sizeof res);
	memset(cnt, 0, sizeof cnt);
}

void add(int x) {
	cnt[a[x]]++;
	if(tol - a[x] >= 1 && tol - a[x] <=n)
		ans += cnt[tol - a[x]];
}

void del(int x) {
	if(tol - a[x] >= 1 && tol - a[x] <=n)
		ans -= cnt[tol - a[x]];
	cnt[a[x]]--;
}

int main() {
    while(~scanf("%d", &n)) {
		init();
		block = sqrt(n);
		scanf("%d", &tol);
		for(int i=1; i<=n; i++)	scanf("%d", &a[i]);
		scanf("%d", &m);
		for(int i=1; i<=4*m; i+=4) {
			int l,r,u,v;
			scanf("%d%d%d%d", &l, &r, &u, &v);
			node[i].l = l, 		node[i].r = v, 		node[i].id = i,		node[i].f = 1;	
			node[i+1].l = l,	node[i+1].r = u-1, 	node[i+1].id = i,	node[i+1].f = -1;
			node[i+2].l = r+1, 	node[i+2].r = v, 	node[i+2].id = i,	node[i+2].f = -1;
			node[i+3].l = r+1,	node[i+3].r = u-1, 	node[i+3].id = i, 	node[i+3].f = 1;
		}
		sort(node+1, node+1+m);
		int L = 1;
		int R = 0;
		for(int i=1; i<=4*m; i++) {
			while(L > node[i].l)
				add(--L);
			while(R < node[i].r)
				add(++R);
			while(L < node[i].l) 
				del(L++);
			while(R > node[i].r)
				del(R--);
			res[node[i].id] += ans * node[i].f;
		}
		for(int i=1; i<=m; i++)	printf("%lld\n", res[i]);
    }
    return 0;
}
