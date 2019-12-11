/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年05月04日 星期六 18时51分42秒
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

vector<int> v;
vector<vector<int> > vv;
map<vector<int>, ll> mp;
set<ll> st;

void dfs(int h, int cnt, int last) {
	if(cnt == n) {
		if(h == m-1)	vv.push_back(v);
		else	return ;
	}
	if(h == m-1)	return ;
	for(int i=last; i<m; i++) {
		v.push_back(i);
		dfs(h+i, cnt+1, i);
		v.pop_back();
	}
}

ll solve(vector<int> vv) {
	if(mp.count(vv))	return mp[vv];
	// for(auto i : vv) {
	//     printf("%d ", i);
	// }
	// printf("\n");
	int cnt = 0;
	for(auto i : vv)	cnt += i ? 0 : 1;
	if(cnt == n-1) {
		mp[vv] = 1;
		return 1;
	}
	ll ans = 0;
	for(int i=0; i<vv.size(); i++) {
		if(vv[i]) {
			vv[i]--;
			ans += solve(vv);
			vv[i]++;
		}
	}
	mp[vv] = ans;
	return ans;
}

int main() {
	v.clear();
	vv.clear();
	mp.clear();
	st.clear();
	scanf("%d%d", &n, &m);
	vv.clear();
	dfs(0, 0, 0);
	for(auto v : vv) {
		sort(vv.begin(), vv.end());
		st.insert(solve(v));
	}
	for(auto i : st) {
		printf("%d\n", i);
	}
	return 0;
}

