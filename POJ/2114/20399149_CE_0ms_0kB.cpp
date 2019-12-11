/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年07月13日 星期六 10时25分31秒
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

int S, distol;
struct Node{
	int v, w;
	int next;
} node[maxn*50];
int sz[maxn], hv[maxn], head[maxn], dis[maxn];
bool vis[maxn];

void dfssz(int u, int fa, int &rt) {
	sz[u] = 1, hv[u] = 0;
	for(int i=head[u]; ~i; i=node[i].next) {
		int v = node[i].v;
		if(v==fa || vis[v])	continue;
		dfssz(v, u, rt);
		sz[u] += sz[v];
		hv[u] = max(hv[u], sz[v]);
	}
	hv[u] = max(hv[u], S-sz[u]);
	if(rt==0 || hv[u]<hv[rt])	rt = u;
}

void dfsdis(int u, int fa, int k) {
	if(k>m)	return ;
	dis[++distol] = k;
	for(int i=head[u]; ~i; i=node[i].next) {
		int v = node[i].v;
		if(v==fa || vis[v])	continue;
		dfsdis(v, u, k+node[i].w);
	}
}

int calc(int u, int w) {
	distol = 0;
	dfsdis(u, 0, w);
	sort(dis+1, dis+1+distol);
	int l=1, r=distol, ans=0;
	while(l<r) {
		if(dis[l]+dis[r] < m) {
			l++;
		} else if(dis[l]+dis[r] > m) {
			r--;
		} else {
			if(dis[l]==dis[r]) {
				ans += (r-l+1)*(r-l)/2;
			} else {
				int tl = l, tr = r;
				while(dis[tl]==dis[l])	tl++;
				while(dis[tr]==dis[r])	tr--;
				ans += (tl-l)*(r-tr);
				l = tl, r = tr;
			}
		}
	}
	return ans;
}

bool dfs(int u) {
	S = sz[u] ? sz[u] : n;
	int rt = 0;
	dfssz(u, 0, rt);
	vis[rt] = true;
	int ans = calc(rt, 0);
	for(int i=head[rt]; ~i; i=node[i].next) {
		int v = node[i].v;
		if(vis[v])	continue;
		ans -= calc(v, node[i].w);
		if(dfs(v))	return true;
	}
	return ans>0 ? true : false;
}

void addnode(int u, int v, int w) {
	node[tol].v = v;
	node[tol].w = w;
	node[tol].next = head[u];
	head[u] = tol++;
}

int main() {
	scanf("%d", &n), n);
	tol = 0;
	mes(head, -1);
	for(int i=1, v, c; i<=n; i++) {
		while(scanf("%d", &v), v) {
			scanf("%d", &c);
			addnode(i, v, c);
			addnode(v, i, c);
		}
	}
	while(scanf("%d", &m), m) {
		for(int i=1; i<=n; i++)	vis[i] = false;
		bool ok = dfs(1);
		if(ok)	printf("AYE\n");
		else	printf("NAY\n");
	}
	printf(".\n");
	return 0;
}
