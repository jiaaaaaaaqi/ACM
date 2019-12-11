/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Thu 05 Sep 2019 12:18:18 AM CST
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

int n, k;
int cas, tol, T;

vector<int> vv[maxn];

void solve1(int n) {
	int p = 1;
	int flag = 0;
	for(int i=1; i<=n; i++) {
		vv[p].pb(i);
		if(flag == 0)	p++;
		else	p--;
		if(p == k+1)	p = k, flag = 1;
		if(p == 0)	p = 1, flag = 0;
	}
}

void solve2(int n, int x) {
	int p = x+1;
	for(int i=1; i<=k; i++)		vv[i].pb(p++);
	for(int i=k; i>=1; i-=2)	vv[i].pb(p++);
	for(int i=k-1; i>=1;i-=2)	vv[i].pb(p++);
	for(int i=k-1; i>=1;i-=2)	vv[i].pb(p++);
	for(int i=k; i>=1; i-=2)	vv[i].pb(p++);
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &k);
		tol = 1ll*n*(n+1)/2;
		if(tol%k) {
			printf("no\n");
		} else {
			printf("yes\n");
			for(int i=1; i<=k; i++)	vv[i].clear();
			if((n/k)%2 == 0) {
				solve1(n);
			} else {
				if(k == 1) {
					for(int i=1; i<=n; i++)	vv[1].pb(i);
				} else {
					solve1(n-3*k);
					solve2(3*k, n-3*k);
				}
			}
			for(int i=1; i<=k; i++) {
				for(int j=0; j<vv[i].size(); j++) {
					printf("%d%c", vv[i][j], j==vv[i].size()-1 ? '\n' : ' ');
				}
			}
		}
	}
	return 0;
}

