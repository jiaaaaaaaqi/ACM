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
const int maxn = 305;
const int maxm = 305;
using namespace std;

int n, m, tol, T;
struct Node {
    double l, r, h;
    int f;
    bool operator <(Node a) const {
        return h < a.h;
    }
};
Node node[maxn];
double a[maxn];
double sum[maxn << 2];
int cnt[maxn << 2];

void init() {
    memset(sum, 0, sizeof sum);
    memset(cnt, 0, sizeof cnt);
}

void pushup(int left, int right, int root) {
    if(cnt[root] != 0)		sum[root] = a[right + 1] - a[left];
    else if(left == right)	sum[root] = 0;
    else	sum[root] = sum[root << 1] + sum[root << 1 | 1];
}

void update(int left, int right, int prel, int prer, int val, int root) {
    if(prel <= left && right <= prer) {
    	cnt[root] += val;
    	pushup(left, right, root);
    	return ;
    }
    int mid = (left + right) >> 1;
    if(prel <= mid)	update(left, mid, prel, prer, val, root << 1);
    if(prer > mid)	update(mid+1, right, prel, prer, val, root << 1 | 1);
    pushup(left, right, root);
}

int main() {
    int cas = 1;
    while(scanf("%d", &n)== 1 && n) {
        init();
        double x1, y1, x2, y2;
        for(int i=1; i<=n; i++) {
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            node[2*i-1].l = x1;
            node[2*i].l = x1;
            node[2*i-1].r = x2;
            node[2*i].r = x2;
            node[2*i-1].h = y1;
            node[2*i].h = y2;
            node[2*i-1].f = 1;
            node[2*i].f = -1;
            a[2*i-1] = x1;
            a[2*i] = x2;
        }
        n = 2*n;
        sort(node+1, node+1+n);
        sort(a+1, a+1+n);
        int nn = unique(a+1, a+1+n) - (a+1);
        double ans = 0;
        for(int i=1; i<n; i++) {
            int l = lower_bound(a+1, a+1+nn, node[i].l) - a;
            int r = lower_bound(a+1, a+1+nn, node[i].r) - a;
            if(l < r)	update(1, nn, l, r-1, node[i].f, 1);
            ans += (node[i+1].h - node[i].h) * sum[1];
        }
        printf("Test case #%d\n", cas++);
        printf("Total explored area: %0.2f\n", ans);
    }
    return 0;
}
