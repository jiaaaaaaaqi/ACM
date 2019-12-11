#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pii        pair<int, int>
#define  INOPEN     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 2e4 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Node{
    int a, p;
    bool operator < (Node na) const {
        return a < na.a;
    }
} node[maxn];
int sumpre[maxn];
int sumsuf[maxn];
int cntpre[maxn];

void sum_update_pre(int x, int val, int n) {
    for(int i=x; i<=n; i+=lowbit(i))
        sumpre[i] += val;
}

int sum_query_pre(int x, int n) {
    int ans = 0;
    for(int i=x; i>0; i-=lowbit(i))
        ans += sumpre[i];
    return ans;
}

void sum_update_suf(int x, int val, int n) {
    for(int i=x; i>0; i-=lowbit(i))
        sumsuf[i] += val;
}

int sum_query_suf(int x, int n) {
    int ans = 0;
    for(int i=x; i<=n; i+=lowbit(i))
        ans += sumsuf[i];
    return ans;
}

void cnt_update_pre(int x, int n) {
    for(int i=x; i<=n; i+=lowbit(i))
        cntpre[i]++;
}

int cnt_query_pre(int x, int n) {
    int ans = 0;
    for(int i=x; i>0; i-=lowbit(i))
        ans += cntpre[i];
    return ans;
}

int main() {
    scanf("%d", &n);
    int nn = 0;
    for(int i=1; i<=n; i++) {
        scanf("%d%d", &node[i].a, &node[i].p);
        nn = max(nn, node[i].p);
    }
    sort(node+1, node+1+n);
    // for(int i=1; i<=n; i++) {
    //     printf("%d %d\n", node[i].a, node[i].p);
    // }
    ll ans = 0;
    for(int i=1; i<=n; i++) {
        int a = node[i].a, p = node[i].p;
        int x = sum_query_pre(node[i].p, nn);
        int y = cnt_query_pre(node[i].p, nn);
        int pre = (y * node[i].p - x) * node[i].a;
        x = sum_query_suf(node[i].p, nn);
        y = i - 1 - y;
        int suff = (x - node[i].p * y) * node[i].a;
        ans += pre + suff;
        sum_update_pre(node[i].p, node[i].p, nn);
        sum_update_suf(node[i].p, node[i].p, nn);
        cnt_update_pre(node[i].p, nn);
    }
    printf("%lld\n", ans);
    return 0;
}