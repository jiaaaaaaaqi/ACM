#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

struct Node{
	int u;
	int v;
	double r;
	double c;
};
Node node[205];
int n,m1,m,ube;
double rbe;
double dis[105];

bool floyd() {
	dis[ube]=rbe;
	for(int r=2; r<=n; r++) {
		bool flag=false;
		for(int i=1; i<=m; i++) {
			if(dis[node[i].v] < (dis[node[i].u] - node[i].c) * node[i].r) {
				flag=true; 
				dis[node[i].v] = (dis[node[i].u] - node[i].c) * node[i].r; 
			} 
		}
		if(!flag)
			return false;
	}
	for(int i=1; i<=m; i++) {
		if(dis[node[i].v] < (dis[node[i].u] - node[i].c) * node[i].r)
			return true;
	}
	return false;
}

void init() {
	memset(node, 0, sizeof(node));
	memset(dis, 0, sizeof(dis));
}

int main() {
	while(scanf("%d%d%d%lf",&n,&m1,&ube,&rbe) != EOF) {
		init();
		m=1;
		int u,v;
		double ruv,cuv,rvu,cvu;
		while(m1--) {
			scanf("%d%d%lf%lf%lf%lf",&u,&v,&ruv,&cuv,&rvu,&cvu);
			node[m].u=u;
			node[m].v=v;
			node[m].r=ruv;
			node[m++].c=cuv;
			node[m].u=v;
			node[m].v=u;
			node[m].r=rvu;
			node[m++].c=cvu;
		}
		if(floyd()) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
} 
