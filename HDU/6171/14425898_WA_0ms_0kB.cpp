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

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 1005;
const int maxm = 400010;
using namespace std;

int n, m, tol;
struct Node{
	int maps[7][7];
	int x, y;
	int cnt;
	int flag;
};
map<ll, ll> vis[2];
int dis[4][2] = {1, 0, 1, 1, -1, 0, -1, -1};

void init() {
    vis[0].clear();
    vis[1].clear();
}

ll gethash(int maps[7][7]) {
	ll ans = 0;
	for(int i=1; i<=6; i++) {
		for(int j=1; j<=i; j++) {
			ans = (ans << 2) + maps[i][j];
		}
	}
	return ans;
}

bool judge(int x, int y) {
	if(x < 1 || x > 6)
		return false;
	if(y < 1 || y > x)
		return false;
	return true;
}

int bfs(Node st, Node ed) {
	queue<Node> q;
	while(!q.empty())	q.pop();
	ed.x = 1;
	ed.y = 1;
	st.cnt = 1;
	ed.cnt = 1;
	st.flag = 0;
	ed.flag = 1;
	q.push(st);
	q.push(ed);
	vis[0][gethash(st.maps)] = 1;
	vis[1][gethash(ed.maps)] = 1;
	while(!q.empty()) {
		Node now = q.front();
		q.pop();
		ll tmp = gethash(now.maps);
		if(vis[1 - now.flag][tmp]) {
			if(vis[now.flag][tmp] + vis[1 - now.flag][tmp] <= 20)
				return vis[now.flag][tmp] + vis[1 - now.flag][tmp] - 2;
			else continue;
		}
		if(now.cnt > 10)	continue;
		for(int i=0; i<4; i++) {
			Node nex = now;
			nex.x = now.x + dis[i][0];
			nex.y = now.y + dis[i][1];
			if(judge(nex.x, nex.y)) {
				swap(nex.maps[now.x][now.y], nex.maps[nex.x][nex.y]);
				ll tmp1 = gethash(nex.maps);
				if(!vis[nex.flag][tmp1]) {
					nex.cnt++;
					vis[nex.flag][tmp1] = nex.cnt;
					q.push(nex);
				}
			}
		}
	}
	return -1;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		Node a, b;
		memset(a.maps, 0, sizeof a.maps);
		memset(b.maps, 0, sizeof b.maps);
		for(int i=1; i<=6; i++) {
			for(int j=1; j<=i; j++) {
				scanf("%d", &a.maps[i][j]);
				b.maps[i][j] = i - 1;
				if(a.maps[i][j] == 0) {
					a.x = i;
					a.y = j;
				}
			}
		}
		int ans = bfs(a, b);
		printf("%d\n", ans);
	}
	return 0;
}
