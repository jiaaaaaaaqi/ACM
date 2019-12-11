#include<stdio.h>
#include<string.h>

struct node {
	int x;
	int y;
};
node pos[10005];
int fa[10005]={0};
int ok[10005]={0};
int d;

int find(int x) {
	return fa[x]==x ? x : fa[x]=find(fa[x]);
}

void bind(int u, int v) {
	int x=find(u);
	int y=find(v);
	if(x!=y)
		fa[x]=y;
}

bool distance(int a, int b) {
	int x=pos[a].x-pos[b].x;
	int y=pos[a].y-pos[b].y;
	if(x*x+y*y>d*d)
		return false;
	else
		return true;
}

int main() {
	int n;
	scanf("%d%d",&n, &d);
	for(int i=1; i<=n; i++) {
		fa[i]=i;
	}
	for(int i=1; i<=n; i++) {
		int x,y;
		scanf("%d%d",&x, &y);
		pos[i].x=x;
		pos[i].y=y;
	}
	char ch;
	while(scanf("%c", &ch)!=EOF) {
		if(ch=='O') {
			int v;
			scanf("%d",&v);
			ok[v]=1;
			for(int i=1; i<=n; i++) {
				if(i!=v && ok[i] && distance(i, v)) {
					bind(i, v);
				}
			}
		}
		if(ch=='S') {
			int u,v;
			scanf("%d%d",&u, &v);
			int x=find(u);
			int y=find(v);
			if(x==y)
				printf("SUCCESS\n");
			else
				printf("FAIL\n");
		}
	}
	return 0;
}