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
vector<double> vec;
double sum[maxn << 2];
int cnt[maxn << 2];

void init() {
    vec.clear();
    memset(sum, 0, sizeof sum);
    memset(cnt, 0, sizeof cnt);
}

int getid(int x) {
    return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;
}

void pushup(int l, int r, int rt) {
    if(cnt[rt] != 0)
        sum[rt] = vec[r] - vec[l-1];
    else if(l == r)
        sum[rt] = 0;
    else
        sum[rt] = sum[rt<<1] + sum[rt<<1|1];

}

void update(int l, int r, int pl, int pr, int f, int rt) {
    if(pl <= l && r <= pr) {
        cnt[rt] += f;
        pushup(l, r, rt);
        return ;
    }
    int mid = (l + r) >> 1;
    if(pl <= mid)
        update(l, mid, pl, pr, f, rt<<1);
    if(pr > mid)
        update(mid+1, r, pl, pr, f, rt<<1|1);
    pushup(l, r, rt);
}

int main() {
    int cas = 1;
    while(scanf("%d", &n)== 1 && n) {
        init();
        tol = 0;
        double x1, y1, x2, y2;
        for(int i=1; i<=n; i++) {
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            node[++tol].l = x1;
            node[tol].r = x2;
            node[tol].h = y1;
            node[tol].f = 1;
            node[++tol].l = x1;
            node[tol].r = x2;
            node[tol].h = y2;
            node[tol].f = -1;
            vec.push_back(x1);
            vec.push_back(x2);
        }
        sort(node+1, node+tol+1);
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        int len = vec.size();
        double ans = 0;
        for(int i=1; i<tol; i++) {
            int l = getid(node[i].l);
            int r = getid(node[i].r);
            update(1, vec.size(), l, r-1, node[i].f, 1);
            ans += (node[i+1].h - node[i].h) * sum[1];
        }
        printf("Test case #%d\n", cas++);
        printf("Total explored area: %0.2f\n", ans);
        printf("\n");
    }
    return 0;
}