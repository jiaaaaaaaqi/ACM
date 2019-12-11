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
const int maxn = 10005;
const int maxm = 305;
using namespace std;

int n, m, tol, T;
struct Node {
    int l, r, h, f;
    bool operator < (Node a) const {
        return h < a.h;
    }
};
Node node[2][maxn];
int sum[maxn << 2];
int cnt[maxn << 2];
int a[2][maxn];

void init() {
    memset(node, 0, sizeof node);
    memset(a, 0, sizeof a);
}

void pushup(int left, int right, int flag, int root) {
    if(cnt[root]) {
        sum[root] = a[flag][right+1] - a[flag][left];
    } else if(left == right) {
        sum[root] = 0;
    } else {
        sum[root] = sum[root << 1] + sum[root << 1 | 1];
    }
}

void update(int left, int right, int prel, int prer, int flag, int val, int root) {
    if(prel <= left && right <= prer) {
        cnt[root] += val;
        pushup(left, right,  flag, root);
        return ;
    }
    int mid = (left + right) >> 1;
    if(prel <= mid)	update(left, mid, prel, prer, flag, val, root << 1);
    if(prer > mid)	update(mid+1, right, prel, prer, flag, val, root << 1 | 1);
    pushup(left, right, flag, root);
}

int main() {
    while(~scanf("%d", &n)) {
        for(int i=1; i<=n; i++) {
            //init();
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            node[0][2*i].l = x1, node[0][2*i-1].l = x1;
            node[0][2*i].r = x2, node[0][2*i-1].r = x2;
            node[0][2*i].h = y1, node[0][2*i-1].h = y2;
            node[0][2*i].f = 1,  node[0][2*i-1].f = -1;
            a[0][2*i] = x1, a[0][2*i-1] = x2;
            node[1][2*i].l = y1, node[1][2*i-1].l = y1;
            node[1][2*i].r = y2, node[1][2*i-1].r = y2;
            node[1][2*i].h = x1, node[1][2*i-1].h = x2;
            node[1][2*i].f = 1,  node[1][2*i-1].f = -1;
            a[1][2*i] = y1, a[1][2*i-1] = y2;

        }
        n <<= 1;
        sort(node[0]+1, node[0]+1+n);
        sort(node[1]+1, node[1]+1+n);
        sort(a[0]+1, a[0]+n+1);
        sort(a[1]+1, a[1]+n+1);
        int cnt1 = unique(a[0]+1, a[0]+1+n) - (a[0]+1);
        int cnt2 = unique(a[1]+1, a[1]+1+n) - (a[1]+1);
        int ans = 0;
        int last = 0;
        memset(sum, 0, sizeof sum);
        memset(cnt, 0, sizeof cnt);
        for(int i=1; i<=n; i++) {
            int l = lower_bound(a[0]+1, a[0]+cnt1+1, node[0][i].l) - a[0];
            int r = lower_bound(a[0]+1, a[0]+cnt1+1, node[0][i].r) - a[0];
            update(1, cnt1, l, r-1, 0, node[0][i].f, 1);
            ans += abs(sum[1] - last);
            last = sum[1];
        }
		last = 0;
        memset(sum, 0, sizeof sum);
        memset(cnt, 0, sizeof cnt);		
        for(int i=1; i<=n; i++) {
            int l = lower_bound(a[1]+1, a[1]+cnt2+1, node[1][i].l) - a[1];
            int r = lower_bound(a[1]+1, a[1]+cnt2+1, node[1][i].r) - a[1];
            update(1, cnt2, l, r-1, 1, node[1][i].f, 1);
            ans += abs(sum[1] - last);
            last = sum[1];
        }
		
        printf("%d\n", ans);
    }
    return 0;
}
