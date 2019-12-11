/***************************************************************
    > File Name    : c.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年04月08日 星期一 19时56分04秒
 ***************************************************************/

#include <unordered_map>
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

unordered_map<int, int> mp;
int dp[maxn];
int a[maxn], b[maxn], c[maxn];

int main() {
	while(~scanf("%d", &n)) {
		tol = 0;
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
			if(mp.count(a[i]))	mp[a[i]] = ++tol;
			mp[a[i]] = tol;
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
		dp[0] = 0;
		vector<int> save;
		for(int i=1; i<=n; i++) {
			if(i!=n && dp[i] > dp[i+1])	continue;
			for(auto j : save) {
				c[j] = 0;
			}
			save.clear();
			int ans = 1, r=i;
			c[b[i]]++;
			save.push_back(b[i]);
			if(dp[i] > dp[n])	break;
			while(r<=n) {
				dp[r] = min(dp[r], dp[i-1]+ans*ans);
				if(dp[r] > dp[n])	break;
				r++;
				c[b[r]]++;
				if(c[b[r]] == 1) {
					save.push_back(b[r]);
					ans++;
				}
			}
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}
