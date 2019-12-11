#include<stdio.h>
#include<string.h>
#include<algorithm>
#define inf 0x3f3f3f3f

using namespace std;

int maps[105][105];

void init() {
	memset(maps, 0, sizeof(maps));
}

int main() {
	int n,m;
	while(scanf("%d%d",&n,&m) != EOF) {
		init();
		while(m--) {
			int u,v;
			scanf("%d%d",&u,&v);
			maps[v][u]= 1;
		}
		for(int k=1; k<=n; k++) {
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=n; j++) {
					if(maps[i][k] && maps[k][j])
						maps[i][j] = 1;
				}
			}
		}
/*
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				printf("%d%c",maps[i][j], j==n ? '\n':' ');
*/
		int ans=0;
		for(int i=1; i<=n; i++) {
			int res=0;
			for(int j=1; j<=n; j++) {
				if(maps[i][j] || maps[j][i])
					res++;
			}
			if(res == n-1)
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}