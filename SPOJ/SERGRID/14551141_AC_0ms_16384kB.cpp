#include<map>
#include<ctime>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 100005;
const int maxm = 1<<11;
const int mod = 200;
using namespace std;

int n, m, tol;
struct Node{
	int x;
	int y;
	int cnt;
	bool operator < (Node a) const{
		return  cnt > a.cnt;
	}
};
char str[505][505];
bool vis[505][505];
int dis[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

void init() {
	memset(vis, 0, sizeof vis);
	memset(str, 0, sizeof str);
}

int bfs(int bex, int bey) {
	priority_queue<Node> q;
	Node now;
	now.x = bex;
	now.y = bey;
	now.cnt = 0;
	vis[bex][bey] = true;
	q.push(now);
	while(!q.empty()) {
		now = q.top();
		q.pop();
		if(now.x == n && now.y == m)
			return now.cnt;
		for(int i=0; i<4; i++) {
			Node nex;
			int cn = str[now.x][now.y] - '0';
			nex.x = now.x + dis[i][0] * cn;
			nex.y = now.y + dis[i][1] * cn;
			if(nex.x < 1 || nex.x > n || nex.y < 1 || nex.y > m)	continue;
			if(vis[nex.x][nex.y])	continue;
			vis[nex.x][nex.y] = true;
			nex.cnt = now.cnt + 1;
			q.push(nex);
		}
	}
	return -1;
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
		init();
		for(int i=1; i<=n; i++) {
			scanf("%s", str[i] + 1);
		}
		int ans = bfs(1, 1);
		printf("%d\n", ans);
	}
    return 0;
}
