/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年05月06日 星期一 11时55分39秒
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

ll C[40][40];
set<ll> st;

void dfs(int d, int c, int last, ll cnt) {
	if(d == n) {
		if(c == m)	st.insert(cnt);
		return ;
	}
	if(c >= m)	return ;
	for(int i=last; i<=m; i++) {
		dfs(d+1, c+i, i, cnt*C[m-c][i]);
	}
}

int main() {
	st.clear();
	scanf("%d%d", &n, &m);
	m--;
	C[0][0] = 1;
	C[1][1] = C[1][0] = 1;
	for(int i=2; i<=m; i++) {
		for(int j=0; j<=m; j++) {
			C[i][j] = j==0 ? 1 : C[i-1][j]+C[i-1][j-1];
		}
	}
	dfs(0, 0, 0, 1);
	for(auto i : st)	printf("%lld\n", i);
	return 0;
}

