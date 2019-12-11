/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年08月23日 星期五 12时08分05秒
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

char s[2][1030][1030];
int f;

void handle(int n) {
    mes(s, 0);
    s[1][1][1] = 'C', s[1][1][2] = 'C';
    s[1][2][1] = 'P', s[1][2][2] = 'C';
    f = 1;
    for(int t=2; t<=n; t++) {
        f = !f;
        m = 1<<t;
        for(int i=1; i<=m/2; i++) {
            for(int j=1; j<=m/2; j++) {
                s[f][i][j] = s[!f][i][j];
            }
        }
        for(int i=m/2+1; i<=m; i++) {
            for(int j=m/2+1; j<=m; j++) {
                s[f][i][j] = s[!f][i-m/2][j-m/2];
            }
        }
        for(int i=1; i<=m/2; i++) {
            for(int j=m/2+1; j<=m; j++) {
                s[f][i][j] = s[!f][i][j-m/2];
            }
        }
        for(int i=m/2+1; i<=m; i++) {
            for(int j=1; j<=m/2; j++) {
                s[f][i][j] = (s[!f][i-m/2][j]=='P' ? 'C' : 'P');
            }
        }
    }
}

int main() {
    // freopen("in", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        handle(n);
        m = 1<<n;
        for(int i=1; i<=m; i++) {
            printf("%s\n", s[f][i]+1);
        }
    }
    return 0;
}