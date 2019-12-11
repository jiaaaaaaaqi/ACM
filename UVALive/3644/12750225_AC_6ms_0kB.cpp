#include<stdio.h>
#include<string.h>

int fa[100005];

int find(int x) {
	return fa[x]==x ? x : fa[x]=find(fa[x]);
}

void init() {
	for(int i=0; i<100005; i++)
		fa[i]=i;
}

int main() {
	int u,v;
	while(scanf("%d", &u)!=EOF) {
		scanf("%d", &v);
		init();
		fa[find(u)]=find(v);
		int ans=0;
		while(scanf("%d", &u), u!=-1) {
			scanf("%d", &v);
			int x=find(u);
			int y=find(v);
			if(x == y)
				ans++;
			else
				fa[x]=y;
		}
		printf("%d\n", ans);
	}
	return 0;
}