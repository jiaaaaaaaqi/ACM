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
const int    maxn = 2e5 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int a[maxn];

int main() {
    mes(a, 0);
    int q;
    scanf("%d", &q);
    int l = 2e5 + 10;
    int r = 2e5 + 10;
    while (q--) {
        char ch[3];
        int id;
        scanf("%s%d", ch, &id);
        if (ch[0] == 'L') {
            a[id] = --l;
        } else if (ch[0] == 'R') {
            a[id] = r++;
        } else {
            int pos = a[id];
            printf("%d\n", min(pos - l, r - pos - 1));
        }
    }
    return 0;
}