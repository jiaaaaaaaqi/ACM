/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Wed 04 Sep 2019 04:11:01 PM CST
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
const int    maxn = 2e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int ans[maxn];

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		m = log2(n)+1;
		mes(ans, 0);
		int res = 0;
		for(int i=2; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				if(i&(1<<(j-1)))	continue;
				ans[i] = (1<<(j-1));
				break;
			}
			if(ans[i] == 0)	ans[i] = 1, res++;
		}
		printf("%d\n", res);
		for(int i=2; i<=n; i++)	printf("%d%c", ans[i], i==n ? '\n' : ' ');
	}
	return 0;
}

