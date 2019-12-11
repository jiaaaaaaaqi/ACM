#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#define inf 0x3f3f3f3f

using namespace std;

struct Node {
	int u;
	int v;
	int w;
	int next;
};
int n, m, be, en;
int ans=0;
int top;
Node node1[200005];
Node node2[200005];
int head1[2005];
int head2[2005];
int cur[2005];
int dis1[2005];
int dis2[2005];
int dis[2005];
int gap[2005];
int pre[2005];
bool vis[2005];

void init() {
	memset(pre, 0, sizeof(pre));
	memset(dis, 0, sizeof(dis));
	memset(gap, 0, sizeof(gap));
	memset(cur, 0, sizeof(cur));
	memset(dis1, inf, sizeof(dis1));
	memset(dis2, inf, sizeof(dis2));
	memset(node1,  0, sizeof(node1));
	memset(node2,  0, sizeof(node2));
	memset(head1, -1, sizeof(head1));
	memset(head2, -1, sizeof(head2));
}

void addnode1(int u, int v, int w, int k) {
	node1[k].u=u;
	node1[k].v=v;
	node1[k].w=w;
	node1[k].next=head1[u];
	head1[u]=k;
}

void addnode2(int u, int v, int w, int k) {
	node2[k].u=u;
	node2[k].v=v;
	node2[k].w=w;
	node2[k].next=head2[u];
	head2[u]=k;
}

void spfa1(int pos) {
	memset(vis, false, sizeof(vis));
	queue<int> q;
	dis1[pos]=0;
	vis[pos]=true;
	q.push(pos);
	while(!q.empty()) {
		int i=q.front();
		vis[i]=false;
		q.pop();
		for(int k=head1[i]; k!=-1; k=node1[k].next) {
			int u=node1[k].u;
			int v=node1[k].v;
			int w=node1[k].w;
			if(dis1[v] > dis1[u] + w) {
				dis1[v] = dis1[u] + w;
				if(!vis[v]) {
					vis[v]=true;
					q.push(v);
				}
			}
		}
	}
}

void spfa2(int pos) {
	memset(vis, false, sizeof(vis));
	queue<int> q;
	dis2[pos]=0;
	vis[pos]=true;
	q.push(pos);
	while(!q.empty()) {
		int i=q.front();
		vis[i]=false;
		q.pop();
		for(int k=head2[i]; k!=-1; k=node2[k].next) {
			int u=node2[k].u;
			int v=node2[k].v;
			int w=node2[k].w;
			if(dis2[v] > dis2[u] + w) {
				dis2[v] = dis2[u] + w;
				if(!vis[v]) {
					vis[v]=true;
					q.push(v);
				}
			}
		}
	}
}

int SAP() {
	memcpy(cur, head2, sizeof(head2));
	int u=pre[be]=be;
	int maxflow=0;
	int aug=-1;
	gap[0]=n;
	while(dis[be] < n) {
loop:
		for(int &i=cur[u]; i!=-1; i=node2[i].next) {
			int v=node2[i].v;
//				printf("%d  %d  %d  \n",node2[i].w, dis[u], dis[v]);
			if(node2[i].w && dis[u]==dis[v]+1) {
				if(aug==-1 || aug>node2[i].w) {
					aug=node2[i].w;
				}
				pre[v]=u;
				u=v;
				if(v==en) {
					maxflow+=aug;
					for(u=pre[u]; v!=be; v=u,u=pre[u]) {
						node2[cur[u]].w -=aug;
						node2[cur[u]^1].w += aug;
					}
					aug=-1;
				}
				goto loop;
			}
		}
		int mindis=n;
		for(int i=head2[u]; i!=-1; i=node2[i].next) {
			int v=node2[i].v;
			if(node2[i].w && mindis>dis[v]) {
				cur[u] = i;
				mindis=dis[v];
			}
		}
		if((--gap[dis[u]]) == 0)
			break;
		gap[dis[u]=mindis+1]++;
		u=pre[u];
	}
	return maxflow;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d%d",&n, &m);
		int k1=1;
		int k2=1;
		for(int i=1; i<=m; i++) {
			int u,v,w;
			scanf("%d%d%d",&u, &v, &w);
			if(u == v)
				continue;
			else {
				addnode1(u, v, w, k1++);
				addnode2(v, u, w, k2++);
			}
		}
		scanf("%d%d",&be, &en);
		spfa1(be);
		spfa2(en);
		/*
		for(int i=1; i<=n; i++) {
			printf("%d  %d\n",dis1[i], dis2[i]);
		}
		puts("");
		*/
		k2=0;
		memset(node2, 0, sizeof(node2));
		memset(head2, -1, sizeof(head2));
		for(int i=1; i<=m; i++) {
			int u=node1[i].u;
			int v=node1[i].v;
			int w=node1[i].w;
			if(dis1[u] + dis2[v] + w == dis1[en]) {
				addnode2(u, v, 1, k2++);
				addnode2(v, u, 0, k2++);
			}
		}
		/*
		for(int i=0; i<k2; i++)
			printf("%d  ..%d..  %d\n",node2[i].v, node2[i].w, node2[i].next);
		*/
		int maxflow=SAP( );
		printf("%d\n",maxflow);
	}
	return 0;
}