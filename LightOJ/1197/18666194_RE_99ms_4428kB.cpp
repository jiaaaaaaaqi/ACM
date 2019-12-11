/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月11日 星期一 21时54分23秒
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
const int    maxn = 1e6 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

bool ispri[maxn], vis[maxn];
int pri[maxn/10];

void handle() {
	tol = 0;
	mes(pri, 0);
	mes(ispri, true);
	int mx = 1e6;
	for(int i=2; i<=mx; i++) {
		if(ispri[i]) {
			pri[++tol] = i;
			for(int j=2; i*j<=mx; j++) {
				ispri[i*j] = false;
			}
		}
	}
}

int main() {
	cas = 1;
	handle();
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		mes(vis, true);
		for(int i=1; i<=tol && pri[i]*pri[i]<=m; i++) {
			int j = n/pri[i]*pri[i];
			if(j < n)	j+=pri[i];
			if(j == pri[i])	j += pri[i];
			for(; j<=m; j+=pri[i]) {
				vis[j-n] = false;
			}
		}
		int ans = 0;
		for(int i=0; i<=m-n; i++) {
			// if(vis[i])	printf("!!!%d\n", i+n);
			ans += vis[i];
		}
		if(n == 1)	ans--;
		printf("Case %d: %d\n", cas++, ans);
	}
	return 0;
}

