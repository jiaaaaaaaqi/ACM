/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年08月16日 星期五 11时25分55秒
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
 
int a[maxn], b[maxn];
 
int solve() {
	for(int i=3; i<=n; i++) {
		b[i] = a[i];
	}
	int ans = 0;
	int d = b[2]-b[1];
	for(int i=3; i<=n; i++) {
		int need = b[i-1]+d;
		if(abs(need-b[i]) > 1)	return inf;
		if(b[i] != need) {
			b[i] = need;
			ans++;
		}
	}
	return ans;
}
 
int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &n);
	for(int i=1; i<=n; i++)	scanf("%d", &a[i]);
	if(n <= 2) {
		printf("0\n");
		return 0;
	}
	int ans = inf;
	for(int i=-1; i<=1; i++) {
		for(int j=-1; j<=1; j++) {
			b[1] = a[1]+i, b[2] = a[2]+j;
			ans = min(ans, solve()+(i!=0)+(j!=0));
		}
	}
	printf("%d\n", ans==inf ? -1:ans);
	return 0;
}