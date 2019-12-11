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
#define  INOPEM     freopen("in.txt", "r", stdin)
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

ull seed = 131;
int a[maxn];
ull b[maxn];
ull h[maxn];
ull fp[maxn];

bool find(int l) {
    tol = 0;
    for (int i = 1; i + l <= n; i++) {
        b[tol++] = h[i + l] - h[i] * fp[l];
    }
    sort(b, b + tol);
    int cnt = 1;
    for (int i = 1; i < tol; i++) {
        if (b[i] == b[i - 1])  cnt++;
        else    cnt = 1;
        if (cnt == m)
            return true;
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    fp[0] = 1;
    for (int i = 1; i <= n; i++)
        fp[i] = fp[i - 1] * seed;
    h[0] = 0;
    for (int i = 1; i <= n; i++)
        h[i] = h[i - 1] * seed + a[i];
    int l = 0;
    int r = n;
    int ans = 0;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (find(mid + 1))
            l = mid + 1;
        else
            r = mid;
    }
    printf("%d\n", l);
}