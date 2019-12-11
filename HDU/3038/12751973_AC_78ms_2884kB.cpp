#include<stdio.h>
#include<string.h>

int fa[200005];
int sum[200005];

void init(int n) {
	for(int i=0; i<=n; i++)
		fa[i]=i;
	memset(sum, 0, sizeof sum);	
}

int find(int x) {
	if(fa[x]==x)
		return x;
	int tmp=find(fa[x]);
	sum[x]+=sum[fa[x]];
	return fa[x]=tmp;
}

int main() {
	int n,m;
	while(scanf("%d%d",&n, &m)!=EOF) {
		init(n);
		int ans=0;
		int u,v,va;
		while(m--) {
			scanf("%d%d%d",&u, &v, &va);
			u--;
			int x=find(u);
			int y=find(v);
			if(x != y) {
				fa[y]=x;
				sum[y] = sum[u] + va - sum[v];
			}
			if(x == y) {
				int pre=sum[v]-sum[u];
				if(pre != va)
					ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}