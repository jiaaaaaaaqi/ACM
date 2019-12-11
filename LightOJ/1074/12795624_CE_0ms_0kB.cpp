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

void init() {
	memset(head, -1, sizeof(head));
	memset(busy, 0, sizeof(busy));
	memset(dis, inf, sizeof(dis));
	memset(vis, false, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
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
	vis[1]=true;
	dis[1]=0;
	queue<int> q;
	q.push(1);
	while(!q.empty()) {
		int i=q.front();
		q.pop();
		vis[i] = false;
		cnt[i]++;
		for(int k=head[i]; k!=-1; k=node[k].next) {
			int u=node[k].u;
			int v=node[k].v;
			int w=node[k].w;
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				if(!vis[v] && cnt[k]<=n) {
					vis[v]=true;
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
		init();
		scanf("%d", &n);
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
			if(dis[v] == inf || dis[v] < 3 || cnt[i]>n) {
				printf("?\n");
			}
			else
				printf("%d\n", dis[v]);
		}
	}
	return 0;
}

