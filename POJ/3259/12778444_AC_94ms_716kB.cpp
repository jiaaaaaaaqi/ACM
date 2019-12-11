#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x3f3f3f3f

using namespace std;

struct Node{
	int u;
	int v;
	int w;
};
Node node[5205];
int n,sum;
int dis[505];


void init() {
	memset(dis, inf, sizeof(dis));
}

bool Bellman_Ford() {
	for(int i=1; i<=n; i++) {
		bool flag=false;
		for(int j=1; j<=sum; j++) {
			if(dis[node[j].v] > dis[node[j].u] + node[j].w) {
				flag=true; 
				dis[node[j].v] = dis[node[j].u] + node[j].w;
			}
		}
		if(!flag)
			break;
	}

	for(int i=1; i<=sum; i++)
		if(dis[node[i].v] > dis[node[i].u] + node[i].w)
			return true;
	return false;
}


int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		int m,k;
		scanf("%d%d%d",&n,&m,&k);
		sum=1;
		for(int i=0; i<m; i++) {
			int u,v,w;
			scanf("%d%d%d", &u, &v, &w);
			node[sum].u=u;
			node[sum].v=v;
			node[sum++].w=w;
			node[sum].u=v;
			node[sum].v=u;
			node[sum++].w=w;
		}
		for(int i=0; i<k; i++) {
			int u,v,w;
			scanf("%d%d%d", &u, &v, &w);
			node[sum].u=u;
			node[sum].v=v;
			node[sum++].w=-w;
		}
		bool ans=Bellman_Ford();
		printf("%s\n", ans ? "YES" : "NO");
	}
	return 0;
}