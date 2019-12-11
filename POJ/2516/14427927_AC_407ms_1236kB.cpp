#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
#define INF (1<<30)
#define MAXN 111
#define MAXM 30000
struct Edge {
	int u,v,cap,cost,next;
} edge[MAXM];
int head[MAXN];
int NV,NE,vs,vt;

void addEdge(int u,int v,int cap,int cost) {
	edge[NE].u=u;
	edge[NE].v=v;
	edge[NE].cap=cap;
	edge[NE].cost=cost;
	edge[NE].next=head[u];
	head[u]=NE++;
	edge[NE].u=v;
	edge[NE].v=u;
	edge[NE].cap=0;
	edge[NE].cost=-cost;
	edge[NE].next=head[v];
	head[v]=NE++;
}
bool vis[MAXN];
int d[MAXN],pre[MAXN];
bool SPFA() {
	for(int i=0; i<NV; ++i) {
		vis[i]=0;
		d[i]=INF;
	}
	vis[vs]=1;
	d[vs]=0;
	queue<int> que;
	que.push(vs);
	while(!que.empty()) {
		int u=que.front();
		que.pop();
		for(int i=head[u]; i!=-1; i=edge[i].next) {
			int v=edge[i].v;
			if(edge[i].cap && d[v]>d[u]+edge[i].cost) {
				d[v]=d[u]+edge[i].cost;
				pre[v]=i;
				if(!vis[v]) {
					vis[v]=1;
					que.push(v);
				}
			}
		}
		vis[u]=0;
	}
	return d[vt]!=INF;
}
int MCMF() {
	int res=0;
	while(SPFA()) {
		int flow=INF,cost=0;
		for(int u=vt; u!=vs; u=edge[pre[u]].u) {
			flow=min(flow,edge[pre[u]].cap);
		}
		for(int u=vt; u!=vs; u=edge[pre[u]].u) {
			edge[pre[u]].cap-=flow;
			edge[pre[u]^1].cap+=flow;
			cost+=flow*edge[pre[u]].cost;
		}
		res+=cost;
	}
	return res;
}

int n,m,k,mat[55][55][55],to[55][55],from[55][55];
bool isOK(int *need,int *supply) {
	for(int i=0; i<k; ++i) if(need[i]>supply[i]) return 0;
	return 1;
}
int main() {
	int a;
	while(~scanf("%d%d%d",&n,&m,&k) && (n||m||k)) {
		int sum=0;
		int supply[55]= {0},need[55]= {0};
		for(int i=0; i<n; ++i) {
			for(int j=0; j<k; ++j) {
				scanf("%d",&to[i][j]);
				need[j]+=to[i][j];
			}
		}
		for(int i=0; i<m; ++i) {
			for(int j=0; j<k; ++j) {
				scanf("%d",&from[i][j]);
				supply[j]+=from[i][j];
			}
		}
		for(int z=0; z<k; ++z) {
			for(int x=0; x<n; ++x) {
				for(int y=0; y<m; ++y) scanf("%d",&mat[z][x][y]);
			}
		}
		if(!isOK(need,supply)) {
			puts("-1");
			continue;
		}

		vs=n+m;
		vt=vs+1;
		NV=n+m+2;
		int res=0;
		for(int good=0; good<k; ++good) {
			NE=0;
			memset(head,-1,sizeof(head));

			for(int i=0; i<m; ++i) addEdge(vs,i,from[i][good],0);
			for(int i=0; i<n; ++i) {
				for(int j=0; j<m; ++j) addEdge(j,i+m,INF,mat[good][i][j]);
			}
			for(int i=0; i<n; ++i) addEdge(i+m,vt,to[i][good],0);
			res+=MCMF();
		}
		printf("%d\n",res);
	}
	return 0;
}