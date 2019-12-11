/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Wed 09 Oct 2019 10:07:38 PM CST
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
const int    maxn = 2e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Node{
	int u;
	int dep;
};
int a[maxn];
char s[maxn], t[maxn];
bool vis[maxn];

bool bfs() {
	int mx = 0;
	for(int i=0; i<n; i++) {
		mx = max(mx, s[i]-'0');
		vis[i] = 0;
	}
	queue<Node> q;
	for(int i=0; i<n; i++) {
		if(s[i]-'0' == mx)
			q.push(Node{i, 1});
	}
	t[1] = mx+'0';
	int dep = 0, tot = 0;;
	while(!q.empty()) {
		Node now = q.front();
		q.pop();
		if(now.dep == n+1)	break;
		if(dep != now.dep) {
			dep = now.dep;
			while(tot)	vis[a[tot--]] = false;
		}
		Node nex;
		nex.u = (1ll*now.u*now.u+1) % n;
		nex.dep = now.dep+1;
		if(t[nex.dep]>s[nex.u] || vis[nex.u])	continue;
		t[nex.dep] = s[nex.u];
		vis[nex.u] = true;
		a[++tot] = nex.u;
		q.push(nex);
	}
}

int main() {
	// freopen("in", "r", stdin);
	cas = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		scanf("%s", s);
		for(int i=0; i<n; i++)	t[i] = '\0';
		bfs();
		t[n+1] = '\0';
		printf("Case #%d: %s\n", cas++, t+1);
	}
	return 0;
}

