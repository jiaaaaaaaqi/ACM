#include<stdio.h>
#include<string.h>

int fa[30005];
int n,m;

int find(int x){
	return fa[x]==x ? x : fa[x]=find(fa[x]);
}

void bind(int u, int v){
	int x=find(u);
	int y=find(v);
	if(x!=y)
		fa[x]=y;
}

void init(){
	for(int i=0; i<n ;i++)
		fa[i]=i;
}

int main(){
	while(scanf("%d%d",&n, &m),n||m){
		init();
		int ans=0;
		while(m--){
			int k;
			scanf("%d",&k);
			int now;
			scanf("%d",&now);
			k--;
			while(k--){
				int nex;
				scanf("%d", &nex);
				bind(now, nex);
			}
		}
		for(int i=0; i<n; i++){
			if(find(i)==fa[0])
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}