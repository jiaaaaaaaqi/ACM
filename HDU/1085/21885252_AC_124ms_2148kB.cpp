/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Mon 23 Sep 2019 04:40:18 PM CST
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

int a[maxn], c[maxn];

void calc(int d, int x) {
	for(int i=0; i<=n; i++) {
		for(int j=0, k=0; j<=n&&k<=x; j+=d, k++) {
			c[i+j] += a[i];
		}
	}
	for(int i=0; i<=n; i++) {
		a[i] = c[i];
		c[i] = 0;
	}
}

int main() {
	// freopen("in", "r", stdin);
	int n1, n2, n3;
	while(scanf("%d%d%d", &n1, &n2, &n3), n1||n2||n3) {
		mes(a, 0);
		mes(c, 0);
		n = n1+2*n2+5*n3;
		for(int i=0; i<=n1; i++)	a[i] = 1;
		calc(2, n2);
		calc(5, n3);
		for(int i=1; ; i++) {
			if(a[i] == 0) {
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}

