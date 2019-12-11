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
const int maxn = 100005;
const int maxm = 100000;
const int mod = 998244353;
using namespace std;

int n, m, tol, T;
int a[maxn];
int b[maxn];
int c[maxn << 2];
int sum[maxn << 2];
int lazy[maxn << 2];

void init() {
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    memset(c, 0, sizeof c);
    memset(sum, inf, sizeof sum);
    memset(lazy, 0, sizeof lazy);
}

void pushup(int root) {
    sum[root] = min(sum[root << 1], sum[root << 1 | 1]);
    c[root] = c[root << 1] + c[root << 1 | 1];
}

void pushdown(int root) {
    if(lazy[root] != 0) {
        lazy[root << 1] += lazy[root];
        lazy[root << 1 | 1] += lazy[root];
        sum[root << 1] -= lazy[root];
        sum[root << 1 | 1] -= lazy[root];
        lazy[root] = 0;
    }
    return ;
}

void build(int left, int right, int root) {
    if(left == right) {
        sum[root] = b[left];
        return ;
    }
    int mid = (left + right) >> 1;
    build(left, mid, root << 1);
    build(mid+1, right, root << 1 | 1);
    pushup(root);
}

void dfs(int left, int right, int root) {
    if(left == right) {
        if(sum[root] == 0) {
            sum[root] = b[left];
			c[root]++;
        }
        return ;
    }
    pushdown(root);
    int mid = (left + right) >> 1;
    if(sum[root << 1] == 0)
		dfs(left, mid, root << 1);
    if(sum[root << 1 | 1] == 0)
		dfs(mid+1, right, root << 1 | 1);
    pushup(root);
}

void update(int left, int right, int prel, int prer, int root) {
    if(prel <= left && right <= prer) {
        lazy[root]++;
        sum[root]--;
        while(sum[root] == 0)	dfs(left, right, root);
        return ;
    }
    pushdown(root);
    int mid = (left + right) >> 1;
    if(prel <= mid)	update(left, mid, prel, prer, root << 1);
    if(prer > mid)	update(mid+1, right, prel, prer, root << 1 | 1);
    pushup(root);
}

int query(int left, int right, int prel, int prer, int root) {
	if(prel <= left && right <= prer) return c[root];
	int mid = (left + right) >> 1;
	int ans = 0;
	if(prel <= mid)	ans += query(left, mid, prel, prer, root << 1);
	if(prer > mid)	ans += query(mid+1, right, prel, prer, root << 1 | 1);
	return ans;
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        init();
        for(int i=1; i<=n; i++)	scanf("%d", &b[i]);
        build(1, n, 1);
        char str[15];
        while(m--) {
            int l, r;
            scanf("%s%d%d", str, &l, &r);
            if(str[0] == 'a') {
                update(1, n, l, r, 1);
            } else if(str[0] == 'q') {
            	int ans = query(1, n, l, r, 1);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
