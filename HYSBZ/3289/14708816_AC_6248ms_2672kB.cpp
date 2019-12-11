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
const int maxn = 50005;
const int maxm = 10000;
const int mod = 364875103;
using namespace std;

int n, m, tol;
int block;
int ans;
struct Node {
    int l, r, id;
    bool operator < (Node a) const {
        return l/block == a.l/block ? r < a.r : l/block < a.l/block;
    }
};
Node node[maxn];
int sum[maxn];
int res[maxn];
int a[maxn];
int p[maxn];
int nn;

void init() {
    memset(a, 0, sizeof a);
    memset(p, 0, sizeof p);
    memset(res, 0, sizeof res);
    memset(sum, 0, sizeof sum);
    memset(node, 0, sizeof node);
}

void update(int x, int v) {
    while(x <= nn) {
        sum[x] += v;
        x += lowbit(x);
    }
}

int query(int x) {
    int ans = 0;
    while(x) {
        ans += sum[x];
        x -= lowbit(x);
    }
    return ans;
}

int main() {
    while(~scanf("%d", &n)) {
        init();
        for(int i=1; i<=n; i++)	{
            scanf("%d", &a[i]);
            p[i] = a[i];
        }
        sort(p+1, p+n+1);
        nn = unique(p+1, p+n+1) - (p+1);
        for(int i=1; i<=n; i++)	a[i] = lower_bound(p+1, p+1+nn, a[i]) - p;
        block = sqrt(n);
        scanf("%d", &m);
        for(int i=1; i<=m; i++) {
            scanf("%d%d", &node[i].l, &node[i].r);
            node[i].id = i;
        }
        sort(node+1, node+1+m);
        ans = 0;
        int L = 1;
        int R = 0;
        for(int i=1; i<=m; i++) {
            while(L < node[i].l) {
                ans -= query(a[L] - 1);
                update(a[L], -1);
                L++;
            }
            while(L > node[i].l) {
                L--;
                ans += query(a[L] - 1);
                update(a[L], 1);
            }
            while(R < node[i].r) {
				R++;
                ans += query(nn) - query(a[R]);
                update(a[R], 1);
            }
            while(R > node[i].r) {
                ans -= query(nn) - query(a[R]);
                update(a[R], -1);
				R--;
            }
            res[node[i].id] = ans;
        }
        for(int i=1; i<=m; i++)	printf("%d\n", res[i]);
    }
    return 0;
}
