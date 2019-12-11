/*************************************************************** 
	> File Name		: a.cpp
	> Author		: Jiaaaaaaaqi
	> Created Time	: Thu 14 Nov 2019 01:19:54 PM CST
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

bool vis[1100];

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &n);
	int l, r;
	l = 200, r = 1;
	mes(vis, 0);
	for(int i=1; i<=n; i++) {
		int x;scanf("%d", &x);
		l = min(l, x), r = max(r, x);
		vis[x] = 1;
	}
	int flag = 0;
	for(int i=1; i<=r; i++) {
		if(!vis[i]) {
			printf("%d\n", i);
			flag = 1;
		}
	}
	if(!flag)	printf("good job\n");
	return 0;
}

