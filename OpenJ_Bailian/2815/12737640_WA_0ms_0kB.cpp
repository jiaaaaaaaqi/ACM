#include<stdio.h>
#include<string.h>

int ans;
int n, m;
int str[55][55];
bool vis[55][55];

void dfs(int i, int j, int preans) {
	if(vis[i][j])
		return ;
	if(i<0||j<0||i>=n||j>=m)
		return ;
	vis[i][j]=true;
	preans++;
	ans=ans>preans ? ans:preans;
			
	if((str[i][j] & 1)==0)
		dfs(i, j-1, preans);
	if((str[i][j] & 2)==0)
		dfs(i-1, j, preans);
	if((str[i][j] & 4)==0)
		dfs(i, j+1, preans);
	if((str[i][j] & 8)==0)		
		dfs(i+1, j, preans);
}

void init() {
	memset(str, 0, sizeof(str));
	memset(vis, 0, sizeof(vis));
} 

int main() {
	while(scanf("%d%d",&n, &m)!=EOF) {
		init();
		ans=0;
		int cnt=0;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				scanf("%d", &str[i][j]);

		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(!vis[i][j])
				{
					dfs(i, j, 1);
					cnt++;
				} 
			}
		}
		printf("%d\n", cnt);
		printf("%d\n", ans);
	}
	return 0;	
}