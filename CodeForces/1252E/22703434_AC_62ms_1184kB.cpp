/*************************************************************** 
	> File Name		: a.cpp
	> Author		: Jiaaaaaaaqi
	> Created Time	: Tue 05 Nov 2019 11:34:59 PM CST
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

int a[maxn], f[maxn], g[maxn];

int main() {
	// freopen("in", "r", stdin);
	int L, R;
	scanf("%d%d%d%d", &n, &L, &R, &m);
	for(int i=1; i<=n; i++)	scanf("%d", &a[i]);
	f[n] = L;
	for(int i=n-1; i>=1; i--) {
		if(a[i] > a[i+1])	f[i] = f[i+1]+1;
		else if(a[i] == a[i+1])	f[i] = f[i+1];
		else	f[i] = max(L, f[i+1]-m);
	}
	g[1] = f[1];
	for(int i=2; i<=n; i++) {
		if(a[i] > a[i-1])	g[i] = max(f[i], g[i-1]+1);
		else if(a[i] == a[i-1])	g[i] = g[i-1];
		else	g[i] = max(f[i], g[i-1]-m);
	}
	for(int i=1; i<=n; i++)	if(!(L<=g[i] && g[i]<=R))	return 0*puts("-1");
	for(int i=1; i<=n; i++)	printf("%d%c", g[i], i==n?'\n':' ');
	return 0;
}

