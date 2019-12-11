/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Fri 30 Aug 2019 11:18:48 PM CST
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
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

ll C[1005][1005];

int main() {
    // freopen("in", "r", stdin);
    int k;
    scanf("%d%d%d", &n, &m, &k);
    if(2*k+1 > min(n, m)) {
        printf("0\n");
        return 0;
    }
    C[0][0] = C[1][0] = C[1][1] = 1;
    for(int i=2; i<=1000; i++) {
        for(int j=0; j<=i; j++) {
            C[i][j] = j==0 ? 1 : (C[i-1][j]+C[i-1][j-1])%mod;
        }
    }
    k<<=1;
    printf("%lld\n", C[n-1][k]*C[m-1][k]%mod);
    return 0;
}

