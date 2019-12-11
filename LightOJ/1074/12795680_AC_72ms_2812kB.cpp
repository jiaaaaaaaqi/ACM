#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#define inf 0x3f3f3f3f

using namespace std;
struct Node{
	int u;
	int v;
	int w;
	int next;
};
Node node[100005];
int head[205];
int n;
int busy[205];
int dis[205];
bool vis[205];
int cnt[205];

void init(int n) {
	for(int i=0; i<=n; i++) {
		head[i] = -1;
		dis[i] = inf;
		cnt[i] = 0;
	}
	memset(vis, false, sizeof(vis));
	memset(node, 0, sizeof(node));
}

void addnode(int u, int v, int w, int k) {
	node[k].u=u;
	node[k].v=v;
	node[k].w=w;
	node[k].next=head[u];
	head[u]=k;
}

void spfa( ) {
	dis[1]=0;
	queue<int> q;
	q.push(1);
	while(!q.empty()) {
		int i = q.front();
		q.pop();
		vis[i] = false;
		cnt[i]++;
		for(int j=head[i]; j!=-1; j=node[j].next) {
			int u = node[j].u;
			int v = node[j].v;
			int w = node[j].w;
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				if(vis[v] == false && cnt[v] <= n) {
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	int cas=1;
	while(T--) {
		scanf("%d", &n);
		init(n);
		for(int i=1; i<=n; i++)
			scanf("%d", &busy[i]);
		int k;
		scanf("%d", &k);
		for(int i=1; i<=k; i++) {
			int u,v;
			scanf("%d%d",&u, &v);
			int w=(busy[v]-busy[u])*(busy[v]-busy[u])*(busy[v]-busy[u]);
			addnode(u, v, w, i);
		}
		spfa( );
		printf("Case %d:\n", cas++);
		scanf("%d",&k);
		while(k--) {
			int v;
			scanf("%d",&v);
			if(dis[v] == inf || dis[v] < 3 || cnt[v]>n) {
				printf("?\n");
			}
			else
				printf("%d\n", dis[v]);
		}
	}
	return 0;
}

