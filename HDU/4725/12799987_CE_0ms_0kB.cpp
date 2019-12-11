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
const maxn=100005;
int n,k;
Node node[20*maxn];
int head[2*maxn];
int lay[2*maxn];
int dis[2*maxn];
bool vis[2*maxn];

void init() {
	memset(node, 0, sizeof(node));
	memset(lay, 0, sizeof(lay));
	memset(vis, 0, sizeof(vis));
	memset(head, -1, sizeof(head));
	memset(dis, inf, sizeof(dis));
}

void addnode(int u, int v, int w) {
	node[k].u=u;
	node[k].v=v;
	node[k].w=w;
	node[k].next=head[u];
	head[u]=k++;
}

void spfa(int pos) {
	memset(vis, false, sizeof(vis));
	queue<int> q;
	vis[pos] = true;
	dis[pos] = 0;
	q.push(pos);
	while(!q.empty()) {
		int i=q.front();
		q.pop();
		vis[i] = false;
		for(int k=head[i]; k!=-1; k=node[k].next) {
			int u=node[k].u;
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
}

int main() {
	int T;
	int cas=1;
	scanf("%d",&T);
	while(T--) {
		init();
		int m,w;
		scanf("%d%d%d",&n,&m,&w);
		for(int i=1; i<=n; i++) {
			int la;
			scanf("%d",&la);
			lay[i] = la;
			vis[la] = true;
		}
		k=1;
		for(int i=1; i<n; i++) {
			if(vis[i] && vis[i+1]) {
				addnode(i+n+1, i+n, w);
				addnode(i+n, i+n+1, w);
			}
		}
		for(int i=1; i<=n; i++) {
			int u,v,c;
			scanf("%d%d%d",&u, &v, &c);
			addnode(u, v, c);
			addnode(v, u, c);
		}
		for(int i=1; i<=n; i++) {
			addnode(lay[i]+n, i, 0);
			if(lay[i] > 1)
				addnode(i, lay[i]+n-1, w);
			if(lay[i] < n)
				addnode(i, lay[i]+n+1, w);
		}
		spfa(1);
		/*
		for(int i=1; i<=n; i++)
			printf("%d  ",dis[i]);
		*/
		printf("Case #%d: ", cas++);
		if(dis[n] == inf)
			printf("-1\n");
		else
			printf("%d\n",dis[n]);
	}
	return 0;
}