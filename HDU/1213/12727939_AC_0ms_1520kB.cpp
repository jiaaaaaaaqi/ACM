#include<cstdio>
#include<cstring>
using namespace std;

int fa[1050];

int find(int x) {
	return fa[x]==-1 ? x : fa[x]=find(fa[x]);
}

int bind(int u, int v) {
	int x=find(u);
	int y=find(v);
	if(x!=y) {
		fa[x]=y;
		return 1;
	}
	return 0;
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		memset(fa, -1, sizeof(fa));
		int n,m;
		scanf("%d%d",&n, &m);
		int ans=n;
		while(m--) {
			int u,v;
			scanf("%d%d",&u, &v);
			if(bind(u, v))
				ans--;
		}
		printf("%d\n", ans);
	}
}