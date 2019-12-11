#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int x;
int n;
int ans;
int str[17][17];
bool check[17];
int vis[17][1<<17];

void dfs(int nowland, int nowtime, int nowstate) {
	x++;
	if(nowtime >= ans)
		return ;

	if(x == n-1) {
		ans=min(ans, nowtime+str[nowland][n]);
		return ;
	}

	if(nowtime<vis[nowland][nowstate] || vis[nowland][nowstate]==0) {
		vis[nowland][nowstate]=nowtime;
	} else 
		return ;

	check[nowland]=1;

	for(int j=1; j<n; j++) {
		if(!check[j]) {
			check[j]=1;
			dfs(j, nowtime+str[nowland][j], nowstate+(1<<nowland-1));
			check[j]=0;
			x--;
		}
	}
}

void init() {
	memset(str, 0, sizeof(str));
	memset(vis, 0, sizeof(vis));
	memset(check, 0, sizeof(check));
}

int main() {
	while(scanf("%d",&n)!=EOF) {
		init();
		x=0;
		ans=0x3f3f3f3f;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				scanf("%d", &str[i][j]);
		check[1]=1;
		dfs(1, 0, 1);
		printf("%d\n", ans);
	}
	return 0;
}