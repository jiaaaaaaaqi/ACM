#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

struct node{
	int beg;
	int end;
	int way;
	int cos;
	int next;
};
node p[10005];
int len=0;
int first[105]={0};
bool vis[105]={0};
int sum,n,k,ans;

void add_(int u, int v, int w, int cost) {
	p[len].end=v;
	p[len].way=w;
	p[len].cos=cost;
	p[len].next=first[u];
	first[u]=len++;
}

void dfs(int from, int dis, int money) {
	if(from==n)
		ans=min(ans, dis);
	if(dis>ans)
		return ;
	for(int i=first[from]; i!=-1; i=p[i].next) { 
 		if(vis[p[i].end] || money+p[i].cos>sum)
			continue;
		vis[p[i].end]=true;
		dfs(p[i].end, dis+p[i].way, money+p[i].cos);
		vis[p[i].end]=false;
	}
}

int main() {
	scanf("%d%d%d",&sum, &n, &k);
		memset(vis, 0, sizeof vis);
		memset(first, -1, sizeof first);
		for(int i=0; i<k; i++) {
			int a,b,c,d;
			scanf("%d%d%d%d",&a, &b, &c, &d);
			add_(a, b, c, d);
		}
		ans=0x3f3f3f3f;
		vis[1]=true;
		dfs(1, 0, 0);
		if(ans==0x3f3f3f3f)
			printf("-1\n");
		else
			printf("%d\n", ans);
	return 0;
}