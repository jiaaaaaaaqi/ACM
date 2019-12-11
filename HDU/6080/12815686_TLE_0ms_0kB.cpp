#include<stdio.h>
#include<string.h>
#include<algorithm>
#define inf 0x3f3f3f3f

using namespace std;

struct Node{
	int x;
	int y;
};
Node node1[505];
Node node2[505];
int n, m;
int maps[505][505];

void init() {
	memset(maps, inf, sizeof(maps));
}

void floyd() {
	for(int k=1; k<=m; k++) {
		for(int i=1; i<=m; i++) {
			for(int j=1; j<=m; j++) {
				maps[i][j] = min(maps[i][j], maps[i][k]+maps[k][j]);
			}
		}
	}
}

int cadis(int i, int j, int k) {
	int x1=node2[j].x - node2[i].x;
	int y1=node2[j].y - node2[i].y;
	int x2=node1[k].x - node2[i].x;
	int y2=node1[k].y - node2[i].y;
	return x1*y2-x2*y1;
}

bool judge(int i, int j, int k) {
	if(node2[i].x<node1[k].x && node2[j].x<node1[k].x)
		return 1;
	if(node2[i].x>node1[k].x && node2[j].x>node1[k].x)
		return 1;
	if(node2[i].y<node1[k].y && node2[j].y<node1[k].y)
		return 1;
	if(node2[i].y>node1[k].y && node2[j].y>node1[k].y)
		return 1;
	return 0;	
}

int main() {
	while(scanf("%d",&n) != EOF) {
		init();
		for(int i=1; i<=n; i++) {
			int x,y;
			scanf("%d%d",&x, &y);
			node1[i].x=x;
			node1[i].y=y;
		}
		scanf("%d", &m);
		for(int i=1; i<=m; i++) {
			int x,y;
			scanf("%d%d",&x, &y);
			node2[i].x=x;
			node2[i].y=y;
		}
		for(int i=1; i<=m; i++) {
			for(int j=1; j<=m; j++) {
				int flag=1;
				for(int k=1; k<=n; k++) {
					if(cadis(i, j, k)<0 || cadis(i, j, k)==0 && judge(i, j, k)) {
						flag=0;
						break;
					}
				}
				if(flag)
					maps[i][j] = 1;
			}
		}
		/*
		for(int i=1; i<=m; i++)
			for(int j=1; j<=m; j++)
				printf("%d%c",maps[i][j], j==m ? '\n':'\t');
		*/
		floyd();
		int ans=inf;
		for(int i=1; i<=m; i++) 
			ans=min(ans, maps[i][i]);
		if(ans==inf)
			printf("ToT\n");
		else
			printf("%d\n", m-ans);
	}
	return 0;
}
