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

typedef long long int ll;
typedef unsigned long long int ull;
const int    maxn = 100000;
const int    maxm = 100000;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

std::map<int, int> mp;

int main() {
    scanf("%d", &T);
    while (T--) {
        mp.clear();
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            int ans = (int)log2((double)x)+1;
            mp[ans]++;
        }
        int ans = 0;
        for (auto i : mp) {
            if (mp[ans] < i.second) {
                ans = i.first;
            }
        }
        printf("%d\n", mp[ans]);
    }
    return 0;
}