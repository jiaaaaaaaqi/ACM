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
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int cnt;
bool ispri[maxn];
int pri[maxn];
std::vector<int> vec;
int vis[maxn];
int ans1, ans2;

void init() {
    mes(vis, 0);
    vec.clear();
}

void handle() {
    tol = 1;
    mes(ispri, 1);
    mes(pri, 0);
    for (int i = 2; i < maxn; i++) {
        if (ispri[i]) {
            pri[tol++] = i;
        }
        for (int j = 1; j < tol && i * pri[j] < maxn; j++) {
            ispri[i * pri[j]] = 0;
            if (i % pri[j] == 0)
                break;
        }
    }
}

void solve(int x) {
    for (int i = 1; i < tol && pri[i] * pri[i] <= x; i++) {
        if (x % pri[i] == 0) {
            vec.push_back(pri[i]);
            while (x % pri[i] == 0) {
                vis[i]++;
                x /= pri[i];
            }
        }
    }
    if (x > 1)
        vec.push_back(x);
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int x, int y) {
    return x / gcd(x, y) * y;
}
int len, a, b;
bool dfs(int res, int id) {
    cnt++;
    if (cnt > 5e2)
        return false;
    int res1 = a - res;
    if (res1 > 0 && lcm(res, res1) == b) {
        ans1 = min(res, res1);
        ans2 = max(res, res1);
        return true;
    }
    for (int i = id; i < len; i++) {
        if (res % vec[i] == 0) {
            if (dfs(res / vec[i], i))
                return true;
        }
    }
    return false;
}

int main() {
    handle();
    while (~scanf("%d%d", &a, &b)) {
        cnt = 1;
        init();
        solve(b);
        ans1 = ans2 = 0;
        len = vec.size();
        dfs(b, 0);
        if (ans1 && ans2)
            printf("%d %d\n", ans1, ans2);
        else
            printf("No Solution\n");
    }
    return 0;
}
