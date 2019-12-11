/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年08月05日 星期一 14时28分09秒
 ***************************************************************/

#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <cfloat>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pb         push_back
#define  pii        pair<int, int>

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 998244353;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

ll a[maxn];

int main() {
    // freopen("in", "r", stdin);
    a[1] = 1;
    a[2] = 1;
    a[3] = 1;
    a[4] = 2;
    for(int i=5; i<=100000; i++) {
        a[i] = a[i-1]+a[i-3];
        a[i] %= mod;
    }
    scanf("%d", &T);
    while(T--) {
        int x, y;
        scanf("%d%d%d", &n, &x, &y);
        if(x != 1)  x++;
        if(y != n)  y--;
        printf("%lld\n", a[y-x+1]);
    }
    return 0;
}
