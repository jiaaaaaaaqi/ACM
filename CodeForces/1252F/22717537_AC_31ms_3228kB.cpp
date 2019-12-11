/*************************************************************** 
    > File Name        : a.cpp
    > Author           : Jiaaaaaaaqi
    > Created Time     : 2019年11月06日 星期三 18时45分28秒
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

vector<int> vv[maxn];
int sz[maxn], gsz[maxn];

void dfs(int u, int fa) {
	sz[u] = 1;
	for(auto v : vv[u])	if(v != fa) {
		dfs(v, u);
		sz[u] += sz[v];
	}
}

void getroot(int u, int fa, int N, pair<int, int> &rt) {
	gsz[u] = 0;
	for(auto v : vv[u])	if(v != fa) {
		gsz[u] = max(gsz[u], sz[v]);
		getroot(v, u, N, rt);
	}
	gsz[u] = max(gsz[u], N-sz[u]);
	if(rt.fi == -1 || gsz[rt.fi] > gsz[u]) {
		rt.fi = rt.se = u;
	} else if(gsz[rt.fi] == gsz[u]){
		rt.se = u;
	}
}

string get(int u, int fa, int st) {
	vector<string> vec;
	vec.clear();
	for(auto v : vv[u])	if(v!=fa && v!=st)
		vec.push_back(get(v, u, st));
	sort(vec.begin(), vec.end());
	string ans = "0";
	for(auto s : vec)	ans = ans+s;
	ans = ans+"1";
	return ans;
}

int calc(int u) {
	if((int)vv[u].size() <= 1)	return -1;
	string A, B, C;
	A = B = C = "";
	bool ok = 1;
	for(int i=0; i<vv[u].size(); i++) {
		int v = vv[u][i];
		if(v == u)	continue;
		pair<int, int> rt;
		rt.fi = rt.se = -1;
		dfs(v, u);
		getroot(v, u, sz[v], rt);
		if(i == 0) {
			A = get(rt.fi, 0, u);
			B = get(rt.se, 0, u);
		} else {
			C = get(rt.fi, 0, u);
			if(C==A || C==B)	continue;
			C = get(rt.se, 0, u);
			if(C==A || C==B)	continue;
			ok = 0;
			break;
		}
	}
	if(ok)	return vv[u].size();
	else	return -1;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &n);
	for(int i=2,u,v; i<=n; i++) {
		scanf("%d%d", &u, &v);
		vv[u].pb(v);
		vv[v].pb(u);
	}
	pair<int, int> rt;
	rt.fi = rt.se = -1;
	dfs(1, 0);
	getroot(1, 0, n, rt);
	printf("%d\n", max(calc(rt.fi), calc(rt.se)));
	return 0;
}

