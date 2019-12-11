#include<stdio.h>
#include<string.h>
#include<algorithm>
#define inf 0x3f3f3f3f
#include<queue>

using namespace std;

struct Node{
	int u;
	int v;
	int w;
	int next;
};
int n,sum;
Node node[20005];
int dis[1005];
int cnt[1005];
int head[1005];
bool vis[1005];

void init() {
	memset(dis, inf, sizeof(dis));
	memset(vis, false, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
	memset(node, 0, sizeof(node));
	memset(head, -1, sizeof(head));	
}

void addnode(int u, int v, int w) {
	node[sum].u=u;
	node[sum].v=v;
	node[sum].w=w;
	node[sum].next=head[u];
	head[u]=sum++;
}

void spfa() {
	queue<int> q;
	q.push(1);
	vis[1]=true;
	dis[1]=0;
	while(!q.empty()) {
		int i=q.front();
		q.pop();
		vis[i]=false;
		cnt[i]++;
		for(int k=head[i]; k!=-1; k=node[k].next) {
			int u=node[k].u;
			int v=node[k].v;
			int w=node[k].w;
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				if(!vis[v] && cnt[v] <=n) {
					vis[v]=true;
					q.push(v);
				}
			}
		}
	}
}

int main() {
	int ml,md;
	while(scanf("%d%d%d",&n,&ml,&md) != EOF) {
		init();
		sum=0;
		while(ml--) {
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			if(u>v)
				swap(u, v);
			addnode(u, v, w);
		}
		while(md--) {
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			if(u<v)
				swap(u, v);
			addnode(u, v, -w);
		}
		spfa();
		int ans=dis[n];
		if(dis[n] == inf)
			ans = -2;
		if(cnt[n] > n)
			ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}
