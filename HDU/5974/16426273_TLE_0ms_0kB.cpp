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

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int x, int y) {
    return x / gcd(x, y) * y;
}

int main() {
    int a, b;
    while (~scanf("%d%d", &a, &b)) {
        int ans1, ans2;
        bool flag = false;
        for (int x = 0; x <= a / 2 + 1; x++) {
            if (x > a)   break;
            int tx = x;
            int y = a - x;
            if (tx > y)
                swap(tx, y);
            if (lcm(tx, y) == b) {
                ans1 = tx;
                ans2 = y;
                flag = true;
                break;
            }
        }
        if (flag)
            printf("%d %d\n", ans1, ans2);
        else
            printf("No Solution\n");
    }
    return 0;
}