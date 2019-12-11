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
const int maxn = 1 << 20;
const int maxm = 10000;
const int mod = 364875103;
using namespace std;

int n, m, tol;
int k, block;
struct Node {
    int l, r, id;
    bool operator < (Node a) const {
        return l/block == a.l/block ? r < a.r : l/block < a.l/block;
    }
};
Node node[maxn];
ll cnt[maxn];
ll res[maxn];
int a[maxn];
ll ans;

void init() {
	ans = 0;
	memset(node, 0, sizeof node);
	memset(cnt, 0, sizeof cnt);
	memset(a, 0, sizeof a);
}

void add(int x) {
	ans += cnt[a[x] ^ k];
	cnt[a[x]]++;
}

void del(int x) {
	cnt[a[x]]--;
	ans -= cnt[a[x] ^ k];
}

int main() {
	init();
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=n; i++)	{
        scanf("%d", &a[i]);
		a[i] ^= a[i-1];
    }
    block = sqrt(n);
    for(int i=1; i<=m; i++) {
        scanf("%d%d", &node[i].l, &node[i].r);
        node[i].id = i;
    }
    sort(node+1, node+1+m);
    int L = 1;
    int R = 0;
    cnt[0] = 1;
    for(int i=1; i<=m; i++) {
        while(L < node[i].l) {
			del(L-1);
			L++;
        }
        while(L > node[i].l) {
			L--;
			add(L-1);
        }
        while(R < node[i].r) {
			R++;
			add(R);
        }
        while(R > node[i].r) {
			del(R);
			R--;
        }
        res[node[i].id] = ans;
    }
    for(int i=1; i<=m; i++) {
		printf("%d\n", res[i]);
    }
    return 0;
}
