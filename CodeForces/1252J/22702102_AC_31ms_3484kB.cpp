/*************************************************************** 
	> File Name		: a.cpp
	> Author		: Jiaaaaaaaqi
	> Created Time	: Tue 05 Nov 2019 10:00:31 PM CST
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

ll g1, g2, g3;
char s[maxn];
ll dp[60][60][60][2];
vector<int> vv;

ll calc(ll a, ll b, ll c) {
	if(a > m)	a = m;
	ll ans = a*g1 + c*g3;
	ll tmp = min(b, (m-a)/2);
	ll res = max(b*g2, (b-tmp)*g2 + tmp*2ll*g1);
	if(a+tmp*2<m && b-tmp>0)	res = max(res, res-g2+g1);
	return ans+res;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d%d%lld%lld%lld", &n, &m, &g1, &g2, &g3);	
	scanf("%s", s+1);
	vv.clear();
	vv.pb(0);
	for(int i=1; i<=n; i++) {
		if(s[i]=='#')	vv.pb(i);
	}
	vv.pb(n+1);
	for(int i=0; i<60; i++)	for(int j=0; j<60; j++)
		for(int k=0; k<60; k++)	for(int z=0; z<2; z++)
			dp[i][j][k][z] = -INF;
	dp[0][0][0][0] = 0;
	int sz = vv.size()-1;
	for(int i=1; i<=sz; i++) {
		int s = vv[i]-vv[i-1]-1;
		for(int j=0; j<=i; j++) {
			for(int k=0; k<=i; k++) {
				dp[i][j][k][0] = max(dp[i][j][k][0], dp[i-1][j-s%2 >= 0 ? j-s%2 : j][k][0] + s/2);
				if(s>=1 && k>=1)
				dp[i][j][k][0] = max(dp[i][j][k][0], dp[i-1][j-(s-1)%2 >= 0 ? j-(s-1)%2 : j][k-1][1] + (s-1)/2);
				if(s>=1)
				dp[i][j][k][1] = max(dp[i][j][k][1], dp[i-1][j-(s-1)%2 >= 0 ? j-(s-1)%2 : j][k][0] + (s-1)/2);
				if(s>=2 && k>=1)
				dp[i][j][k][1] = max(dp[i][j][k][1], dp[i-1][j-(s-2)%2 >= 0 ? j-(s-2)%2 : j][k-1][1] + (s-2)/2);
			}
		}
	}
	ll ans = 0;
	for(int i=0; i<60; i++)	for(int j=0; j<60; j++)	if(dp[sz][i][j][0]>=0)	
		ans = max(ans, calc(i, dp[sz][i][j][0], j));
	printf("%lld\n", ans);
	return 0;
}

