#include<stdio.h>
#include<string.h>

int fa[2000005];

int find(int x) {
	return fa[x]==x ? x : fa[x]=find(fa[x]);
}

void bind(int u ,int v) {
	int x = find(u);
	int y = find(v);
	if(x != y)
		fa[x] = y;
	return ;
}

int main() {
	int T;
	int cas=1;
	scanf("%d",&T);
	while (T--) {
		int n,m;
		int flag=0;
		scanf("%d%d",&n, &m);
		for(int i=1; i<=n<<1; i++)
			fa[i]=i;

		for(int i=0; i<m; i++) {
			int u, v;
			scanf("%d%d",&u, &v);
			if(flag)
				continue;
			bind(u, v+n);
			bind(u+n, v);
//			printf("u和u+n的祖先%d  %d\n", find(u), find(u+n));
//			printf("v和v+n的祖先%d  %d\n", find(v), find(v+n));
			if(find(u)==find(u+n) || find(v)==find(v+n))
				flag=1;
		}
		
		printf("Scenario #%d:\n", cas++);
		if(flag)
			printf("Suspicious bugs found!\n");
		else
			printf("No suspicious bugs found!\n");
		printf("\n");
	}
	return 0;
}