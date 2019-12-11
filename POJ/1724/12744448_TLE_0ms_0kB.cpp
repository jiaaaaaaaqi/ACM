#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

struct node{
	int beg;
	int end;
	int way;
	int cos;
};
node p[10005];
bool vis[1005]={0};
int sum,n,k,ans;

void dfs(int from, int dis, int money) {
	if(from==n)
		ans=min(ans, dis);
	if(dis>ans)
		return ;
	for(int i=0; i<k; i++) {
		if(p[i].beg == from && money+p[i].cos <= sum) {
			if(vis[p[i].end])
				continue;
			vis[p[i].end]=true;
			dfs(p[i].end, dis+p[i].way, money+p[i].cos);
			vis[p[i].end]=false;
		}
	}
}

int main() {
	scanf("%d%d%d",&sum, &n, &k);
		memset(vis, 0, sizeof vis);
		memset(p, 0, sizeof p); 
		ans=0x3f3f3f3f;
		for(int i=0; i<k; i++)
			scanf("%d%d%d%d",&p[i].beg, &p[i].end, &p[i].way, &p[i].cos);
		
		vis[1]=true;
		dfs(1, 0, 0);
		if(ans==0x3f3f3f3f)
			printf("-1\n");
		else
			printf("%d\n", ans);
	return 0;
}