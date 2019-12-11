#include<stdio.h>
#include<string.h>

int fa[150005];
int n;
int ans;

int find(int x) {
	return fa[x]==x ? x : fa[x]=find(fa[x]);
}

void bind(int u, int v) {
	int x=find(u);
	int y=find(v);
	if(x != y)
		fa[x]=y;
}

void init() {
	for(int i=0; i<=n*3; i++)
		fa[i]=i;
}

int main() {
	int k;
	scanf("%d%d",&n, &k);
		init();
		ans=0;
		int ca,u,v;
		while(k--) {
			scanf("%d%d%d",&ca, &u, &v);
			if(u<1 || v<1)
			{
				ans++;
				continue;
			}
			if(u>n || v>n)
			{
				ans++;
				continue;
			}
			if(ca==1) {
				if(find(u)==find(v+n) || find(u)==find(v+2*n))
				{
					ans++;
					continue;
				}
				bind(u, v);
				bind(u+n, v+n);
				bind(u+2*n, v+2*n);
			}
			if(ca==2) {
				if(find(u)==find(v) || find(u)==find(v+2*n))
				{
					ans++;
					continue;
				}
				bind(u, v+n);
				bind(u+n, v+2*n);
				bind(u+2*n, v);
			}
		}
		printf("%d\n", ans);
	return 0;
}