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
#define  INOPEN     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

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
/********************************/
struct Node{
	int u, v, w;
	int val;
	int next;
} node[maxm<<2];
int head[maxn];
int pre[maxn];
int dis[maxn];
int cap[maxn];
bool vis[maxn];

void init() {
	tol = 0;
	mes(head, -1);
}
void addnode(int u, int v, int w, int val) {
	node[tol].u = u;
	node[tol].v = v;
	node[tol].w = w;
	node[tol].val = val;
	node[tol].next = head[u];
	head[u] = tol++;
}
bool spfa(int src, int des, int &flow, int &cost) {
	mes(pre, 0);
	mes(dis,inf);
	mes(cap, inf);
	mes(vis, false);
	queue<int> q;
	pre[src] = src;
	vis[src] = true;
	dis[src] = 0;
	cap[src] = inf;
	q.push(src);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = false;
		for(int i=head[u]; ~i; i=node[i].next) {
			int v = node[i].v;
			if(node[i].w && dis[v] > dis[u]+node[i].val) {
				dis[v] = dis[u]+node[i].val;
				cap[v] = min(cap[u], node[i].w);
				pre[v] = i;
				if(!vis[v]) {
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
	if(dis[des] == inf)	return false;
	flow += cap[des];
	cost += cap[des]*dis[des];
	int u = des;
	while(u != src) {
		node[pre[u]].w -= cap[des];
		node[pre[u]^1].w += cap[des];
		u = node[pre[u]].u;
	}
	return true;
}
pii MCMF(int src, int des) {
	int flow = 0, cost = 0;
	while(spfa(src, des, flow, cost));
	return make_pair(flow, cost);
}
/********************************/
char s[105], t[105];
int cnt[105][30], cc[105], ss[30];
int main() {
	init();
	mes(s, 0);
	scanf("%s", s+1);
	scanf("%d", &n);
	mes(cnt, 0);
	for(int i=1; i<=n; i++) {
		mes(t, 0);
		scanf("%s%d", t+1, &cc[i]);
		int lt = strlen(t+1);
		for(int j=1; j<=lt; j++) {
			cnt[i][t[j]-'a'+1]++;
		}
	}
	int len = strlen(s+1);
	int src, des;
	src = 0, des = len+n+1;
	for(int i=1; i<=len; i++) {
		ss[s[i]-'a'+1]++;
	}
	for(int i=1; i<=26; i++) {
		addnode(src, i, ss[i], 0);
		addnode(i, src, 0, 0);
		for(int j=1; j<=n; j++) {
			if(cnt[j][i]) {
				addnode(i, j+26, cnt[j][i], j);
				addnode(j+26, i, 0, -j);				
			}
		}
	}
//	for(int i=1; i<=len; i++) {
//		addnode(src, i, 1, 0);
//		addnode(i, src, 0, 0);
//		for(int j=1; j<=n; j++) {
//			if(cnt[j][s[i]-'a'+1]) {
//				addnode(i, j+len, cnt[j][s[i]-'a'+1], j);
//				addnode(j+len, i, 0, -j);
////				printf("%d %d %d %d\n", i, j+len, cnt[j][s[i]-'a'+1], j);
//			}
//		}
//	}
	for(int i=1; i<=n; i++) {
		addnode(i+26, des, cc[i], 0);
		addnode(des, i+26, 0, 0);
	}
	auto ans = MCMF(src, des);
	if(ans.fi == len)
		printf("%d\n", ans.se);
    else
		printf("-1\n");
    return 0;
}
/*
aaabbtttefg
6
abbbca 3
ffatgg 2
yioa 4
ppaeg 2
aetgffff 4
treiiaav 10
*/
