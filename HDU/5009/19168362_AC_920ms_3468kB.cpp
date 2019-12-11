/***************************************************************
    > File Name    : c.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年04月08日 星期一 19时56分04秒
 ***************************************************************/
#include <assert.h>
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

map<int, int> mp;
int dp[maxn];
int a[maxn], b[maxn];
bool vis[maxn];

int main() {
	while(~scanf("%d", &n)) {
		mp.clear();
		int cnt = 0;
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
			if(!mp.count(a[i]))	
				mp[a[i]] = ++cnt;
			a[i] = mp[a[i]];
		}
		tol = 1;
		b[1] = a[1];
		for(int i=2; i<=n; i++) {
			if(a[i] == a[i-1]) {
				continue;
			} else {
				b[++tol] = a[i];
			}
		}
		n = tol;
		for(int i=1; i<=n; i++) {
			dp[i] = inf;
		}
		vector<int> vv;
		vv.clear();
		dp[0] = 0, dp[n] = n;
		for(int i=1; i<=n; i++) {
			if(dp[i-1] > dp[i]) continue;
			int ans = 0;
			for(int j=i; j<=n; j++) {
				if(!vis[b[j]]) {
					vv.push_back(b[j]);
					vis[b[j]] = true;
					ans++;
				}
				if(dp[i-1]+ans*ans>=dp[n])	break;
				dp[j] = min(dp[j], dp[i-1]+ans*ans);
			}
			for(auto j : vv) {
				vis[j] = false;
			}
			vv.clear();
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}
