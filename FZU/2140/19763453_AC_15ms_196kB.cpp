/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年05月16日 星期四 15时46分18秒
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
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-7;
using namespace std;

int n, m;
int cas, tol, T;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		if(n <= 3) {
			printf("No\n");
		} else {
			printf("Yes\n");
			printf("1.000000 0.000000\n");
			printf("0.500000 -0.133975\n");
			printf("0.000000 0.000000\n");
			printf("0.500000 0.866025\n");
			double x = 0.5;
			double up = 0.005;
			x = x + up + eps;
			for(int i=5; i<=n; i++) {
				double y = sqrt(1.0-x*x+eps);
				printf("%.6f %.6f\n", x, y);
				x = x + up + eps;
			}
		}
	}
	return 0;
}

