#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

struct built {
	int x;
	int y;
};
built con[20005];
struct node {
	char ch;
	int x;
	int y;
};
node ope[50005];
int pow[10005];
bool vis[51000];
int fa[10005];
int ans[50005];
int n;

int find(int x) {
	return fa[x]==x ? x : fa[x]=find(fa[x]);
}

void bind(int u, int v) {
	int x=find(u);
	int y=find(v);
	if(x==y)
		return ;
	else {
		if(pow[x] > pow[y]) {
			fa[y]=x;
		} else if(pow[x] < pow[y]) {
			fa[x]=y;
		} else {
			if(x < y)
				fa[y]=x;
			else
				fa[x]=y;
		}
	}
}

void init() {
	memset(vis, false, sizeof(vis));
	memset(con, 0, sizeof(con));
	memset(ope, 0, sizeof(ope));
	memset(ans, 0 ,sizeof(ans));
	for(int i=0; i<n; i++)
		fa[i]=i;
}

int main() {
	int flag=0;
	while(scanf("%d",&n)!=EOF) {
		if(flag)
			printf("\n");
		else
			flag=1;
		for(int i=0; i<n; i++)
			scanf("%d", &pow[i]);

		int m;
		scanf("%d", &m);
		for(int i=0; i<m; i++) {
			scanf("%d%d",&con[i].x, &con[i].y);
			if(con[i].x > con[i].y)
				swap(con[i].x, con[i].y);
		}

		int m1;
		char str[10];
		scanf("%d",&m1);
		for(int i=0; i<m1; i++) {
			memset(str, 0, sizeof(str));
			scanf("%s", str);
			ope[i].ch=str[0];
			if(ope[i].ch == 'q') {
				scanf("%d", &ope[i].x);
			}
			if(ope[i].ch=='d') {
				scanf("%d%d", &ope[i].x, &ope[i].y);
				if(ope[i].x > ope[i].y)
					swap(ope[i].x, ope[i].y);
				vis[ope[i].x*10000+ope[i].y]=true;
			}
		}

		for(int i=0; i<m; i++) {
			if(!vis[con[i].x*10000+con[i].y])
				bind(con[i].x, con[i].y);
		}

		int j=0;
		for(int i=m1-1; i>=0; i--) {
			if(ope[i].ch=='q') {
				int x=find(ope[i].x);
				if(pow[ope[i].x] >= pow[x])
					ans[j++]=-1;
				else
					ans[j++]=x;
			}
			if(ope[i].ch=='d') {
				bind(ope[i].x, ope[i].y);
			}
		}

		for(int i=j-1; i>=0; i--)
			printf("%d\n", ans[i]);
	}
	return 0;
}