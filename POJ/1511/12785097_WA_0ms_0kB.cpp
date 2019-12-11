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
Node node[1000005];
Node pre[1000005];
int head[1000005];
bool vis[1000005];
long long int dis[1000005];
int n;

void addnode(int u, int v, int w, int k) {
	node[k].u=u;
	node[k].v=v;
	node[k].w=w;
	node[k].next=head[u];
	head[u]=k;
}

long long int spfa() {
	queue<int> q;
	memset(dis, inf, sizeof(dis));
	memset(vis, false, sizeof(vis));
	vis[1]=true;
	dis[1]=0;
	q.push(1);
	while(!q.empty()) {
		int u;
		u=q.front();
		q.pop();
		vis[u]=0;
		for(int k=head[u]; k!=-1; k=node[k].next) {
			int v=node[k].v;
			int w=node[k].w;
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				if(!vis[v]) {
					vis[v]=true;
					q.push(v);
				}
			}
		}
	}
	long long int res=0;
	for(int i=1; i<=n; i++)
		res+=dis[i];
	return res;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int m;
		scanf("%d%d",&n,&m);

		memset(node, 0, sizeof(node));
		memset(head, -1, sizeof(head));
		for(int i=1; i<=m; i++) {
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			pre[i].u=u;
			pre[i].v=v;
			pre[i].w=w;
			addnode(u, v, w, i);
		}
		long long int ans=0;
		ans+=spfa();

		memset(node, 0, sizeof(node));
		memset(head, -1, sizeof(head));
		for(int i=1; i<=m; i++) {
			addnode(pre[i].v, pre[i].u, pre[i].w, i);
		}
		ans+=spfa();
		printf("%d\n", ans);
	}
	return 0;
}