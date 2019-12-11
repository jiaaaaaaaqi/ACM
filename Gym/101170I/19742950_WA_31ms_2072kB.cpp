/***************************************************************
    > File Name    : I.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年05月15日 星期三 02时21分19秒
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

int n, m, k;
int cas, tol, T;

int id[maxn];
bool vis[maxn][5];
vector<int> vv[maxn];
struct Node{
	int id;
	int sta;
	int cnt;
	Node() {

	}
	Node(int _id, int _sta, int _cnt) {
		id = _id, sta = _sta, cnt = _cnt;
	}
};

int bfs() {
	Node now, nex;
	if(id[1]) {
		now = Node{1, (1<<(id[1]-1)), 0};
		vis[1][(1<<(id[1]-1))] = true;
	} else {
		now = Node(1, 0, 0);
		vis[1][0] = true;
	}
	queue<Node> q;
	q.push(now);
	while(!q.empty()) {
		now = q.front();
		q.pop();
		if(now.sta == 3)	return now.cnt;
		int u = now.id;
		int sta = now.sta;
		int cnt = now.cnt;
		for(auto v : vv[u]) {
			int nst = sta;
			int ncn = cnt+1;
			if(id[v]) {
				nst = sta | (1<<(id[v]-1));
			}
			if(vis[v][nst])	continue;
			vis[v][nst] = true;
			q.push(Node(v, nst, ncn));
		}
	}
	return -1;
}

int main() {
	mes(id, 0);
	mes(vis, 0);
	scanf("%d%d%d", &n, &m, &k);
	for(int i=1, x; i<=m; i++) {
		scanf("%d", &x);
		id[x] = 1;
	}
	for(int i=1, x; i<=k; i++) {
		scanf("%d", &x);
		id[x] = 2;
	}
	for(int i=1, num, v; i<=n; i++) {
		vv[i].clear();
		scanf("%d", &num);
		while(num--) {
			scanf("%d", &v);
			vv[i].push_back(v);
		}
	}
	int ans = bfs();
	if(ans == -1)	puts("impossible");
	else	printf("%d\n", ans);
	return 0;
}

