/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Mon 23 Sep 2019 04:20:50 PM CST
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
#include <unordered_map>
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

int a[maxn], b[maxn], c[maxn];

int calc(int len1, int x) {
	for(int i=0; i<=n; i++) {
		b[i] = 0;
		if(i%x == 0)	b[i] = 1;
	}
	int len = 0;
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=n; j++) {
			c[i+j] += a[i]*b[j];
		}
	}
	for(int i=1; i<=n; i++) {
		a[i] = c[i];
		c[i] = 0;
	}
	return len;
}

int main() {
	// freopen("in", "r", stdin);
	while(scanf("%d", &n), n) {
		mes(c, 0);
		int len = 0;
		for(int i=0; i<=n; i++) {
			a[i] = 1;
		}
		for(int i=2; i<=17; i++) {
			len = calc(len, i*i);
		}
		printf("%d\n", a[n]);
	}
	return 0;
}

