#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define inf 0x3f3f3f3f

using namespace std;

struct Node{
	int x;
	int y;
};
Node node[205];
int maps[205][205];

void init() {
	memset(node, 0, sizeof node);
	memset(maps, inf, sizeof maps);
}

int main() {
	int cas=1;
	int n;
	while(scanf("%d", &n), n) {
		init();
		for(int i=1; i<=n; i++) {
			int x,y;
			scanf("%d%d",&x,&y);
			node[i].x=x;
			node[i].y=y;
		}
		
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				int x=(node[i].x - node[j].x) * (node[i].x - node[j].x);
				int y=(node[i].y - node[j].y) * (node[i].y - node[j].y);
				maps[i][j] = x+y;
			}
		}
		
		int ans=inf;
		for(int k=1; k<=n; k++) {
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=n; j++) {
					if(i != j) {
						if(maps[i][j] > maps[i][k] + maps[k][j]) {
							maps[i][j] = maps[i][k] + maps[k][j];
						}
						ans=min(ans, maps[i][j]);
					}
				}
			}
		}
/*
		for(int i=1; i<=n; i++)	{
			for(int j=1; j<=n; j++)
				printf("%d ", maps[i][j]);
			printf("\n"); 
		}
*/
		float res=sqrt((float)ans);
		printf("Scenario #%d\n", cas++);
		printf("Frog Distance = %.3f\n", res);
		printf("\n");
	}
	return 0;
}