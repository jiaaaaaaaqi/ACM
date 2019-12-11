/***************************************************************
    > File Name    : F.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年05月14日 星期二 23时31分31秒
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
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

char s1[maxn], s2[maxn];

ll dfs1(int pos, char *s) {
	if(pos == n+1)	return 1;
	if(s[pos] == s[pos-1])	return dfs1(pos+1, s);
	else	return dfs1(pos+1, s) + (1<<(n-pos));
}

ll dfs2(int pos, char *s) {
	if(pos == n+1)	return 1;
	if(s[pos] != s[pos-1])	return dfs2(pos+1, s);
	else	return dfs2(pos+1, s) + (1<<(n-pos));
}

ll solve(char *s) {
	if(s[1] == '0')	return dfs1(2, s);
	else {
		s[1] = '0';
		return dfs2(2, s) + (1<<(n-1));
	}
}

int main() {
	scanf("%d", &n);
	scanf("%s%s", s1+1, s2+1);
	ll ans = solve(s2) - solve(s1)-1;
	// printf("%d %d\n", solve(s1), solve(s2));
	printf("%lld\n", ans);
	return 0;
}

