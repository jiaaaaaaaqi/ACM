#include<stdio.h>
#include<string.h>
#include<algorithm>
#define inf 0x3f3f3f3f
#include<stack>

using namespace std;

struct Node{
	int u;
	int v;
	int w;
	int next;
};
int n,m;
Node node[150005];
bool vis[30005];
int dis[30005];
int head[30005];

void init() {
	memset(node, 0, sizeof(node));
	memset(dis, inf, sizeof(dis));
	memset(head, -1, sizeof(head));	 
	memset(vis, false, sizeof(vis));
}

void addnode(int u, int v, int w, int k) {
	node[k].u=u;
	node[k].v=v;
	node[k].w=w;
	node[k].next=head[u];
	head[u]=k;
}

void spfa() {
	stack<int> sta;
	sta.push(1);
	dis[1]=0;
	vis[1]=true;
	while(!sta.empty()) {
		int u=sta.top();
		sta.pop();
		vis[u]=false;
		for(int k=head[u]; k!=-1; k=node[k].next) {
			int v=node[k].v;
			int w=node[k].w;
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				if(!vis[v]) {
					vis[v]=true;
					sta.push(v);
				}
			}
		}
	}
}

int main() {
	while(scanf("%d%d",&n,&m)!=EOF) {
		init();
		for(int i=1; i<=m; i++) {
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			addnode(u, v, w, i);
		}
		spfa();
		printf("%d\n", dis[n]);
	}
	return 0;
}