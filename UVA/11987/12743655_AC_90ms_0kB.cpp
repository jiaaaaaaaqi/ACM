#include<stdio.h>
#include<string.h>

int n;
int fa[200005];
int id[200005];
int cnt[200005];
int sum[200005];

int find(int x) {
	return fa[x]==x ? x: fa[x]=find(fa[x]);
}

void init( ) {
	for(int i=0; i<=n; i++) {
		id[i]=i;
		fa[i]=i;
		cnt[i]=1;
		sum[i]=i;
	}
}


int main() {
	int k;
	while (scanf("%d%d",&n, &k)!=EOF) {
		init();
		int kca=n+1;
		while(k--) {
			int ca, u, v;
			scanf("%d",&ca);
			if(ca==1) {
				scanf("%d%d",&u, &v);
				int x=id[u];
				int y=id[v];
				x=find(x);
				y=find(y);
				if(x != y) {
					fa[x]=y;
					sum[y]+=sum[x];
					cnt[y]+=cnt[x];
				}
			} else if(ca==2) {
				scanf("%d%d",&u, &v);
				int x=id[u];
				int y=id[v];
				x=find(x);
				y=find(y);
				if(x != y) {
					sum[x]-=u;
					cnt[x]--;
					id[u]=kca++;
					x=id[u];
					fa[x]=y;
					sum[y]+=u;
					cnt[y]++;
				}
			} else if(ca==3) {
				scanf("%d", &u);
				int x=id[u];
				x=find(x);
				printf("%d %d\n",cnt[x], sum[x]);
			}
		}
//		for(int i=1; i<kca; i++)
//			printf("%d的父节点%d有%d个子节点，总和是%d\n",i,find(i), cnt[i],sum[i]);
	}
	return 0;
}