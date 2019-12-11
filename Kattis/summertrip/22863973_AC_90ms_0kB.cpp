/*************************************************************** 
	> File Name		: K.cpp
	> Author		: Jiaaaaaaaqi
	> Created Time	: Thu 14 Nov 2019 02:24:27 PM CST
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

char s[maxn];
int pr[maxn], p[40];
vector<int> vv[40];

int main() {
	// freopen("in", "r", stdin);
	scanf("%s", s+1);
	n = strlen(s+1);
	for(int i=1; i<=30; i++)vv[i].clear();
	for(int i=1; i<=n; i++) {
		vv[s[i]-'a'+1].pb(i);
		p[s[i]-'a'+1] = n+1;
	}
	for(int i=1; i<=26; i++) {
		vv[i].pb(n+1);
	}
	for(int i=n; i>=1; i--) {
		pr[i] = p[s[i]-'a'+1];
		p[s[i]-'a'+1] = i;
	}
	ll ans = 0;
	for(int i=1; i<=n; i++) {
		int l = i, r = pr[i];
		for(int j=1; j<=26; j++) {
			if(j == s[i]-'a'+1)	continue;
			int p = lower_bound(vv[j].begin(), vv[j].end(), l)-vv[j].begin();
			if(vv[j][p]>=r)	continue;
			ans++;
		}
	}
	printf("%lld\n", ans);
	return 0;
}

