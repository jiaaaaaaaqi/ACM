/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月09日 星期六 14时26分03秒
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
#define  pii        pair<int, int>

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 2e1 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int a[maxn], b[maxn];
int dp[maxn][maxn];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		ll s1, s2, s3, s4;
		s1 = s2 = s3 = s4 = 0;
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
			if(i & 1)	s1 += a[i];
			else	s2 += a[i];
		}
		for(int i=1; i<=n; i++) {
			scanf("%d", &b[i]);
			if(i & 1)	s3 += b[i];
			else	s4 += b[i];
		}
		cout << max(s1+s4, s2+s3) << endl;
	}
	return 0;
}

