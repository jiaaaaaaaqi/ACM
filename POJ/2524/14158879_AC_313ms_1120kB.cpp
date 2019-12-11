#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 50005;
using namespace std;

int n, m;
struct Node{
	int fath;
	int rela;
}node[maxn];
bool vis[maxn];

void init() {
	for(int i=0; i<=n; i++) {
		node[i].fath = i;
		node[i].rela = 1;
	}
	memset(vis, false, sizeof(vis));
}

int find(int x) {
	if(node[x].fath == x)	return x;
	int tmp = node[x].fath;
	node[x].fath = find(node[x].fath);
	node[x].rela += node[tmp].rela;
	return node[x].fath;
}

void bind(int x, int y) {
	node[y].fath = x;
	node[x].rela += node[y].rela;	
}

int main() {
	int cas = 1;
	while(scanf("%d%d", &n, &m), n||m) {
		init();
		while(m--) {
			int u, v;
			scanf("%d%d", &u, &v);
			int x = find(u);
			int y = find(v);
			if(x != y)	bind(x, y);
		}
		int ans = n;
		for(int i=1; i<=n; i++) {
			find(i);
			int pos = node[i].fath;
			if(!vis[pos] && node[pos].rela) {
				vis[pos] = true;
				ans = ans - node[pos].rela + 1;
			}
		}
		printf("Case %d: %d\n", cas++, ans);
	}
	return 0;
} 