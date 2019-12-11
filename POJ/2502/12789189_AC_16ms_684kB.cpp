#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

int bex,bey;
int enx,eny;
int sux[205];
int suy[205];
double dis[205];
double maps[205][205];
bool vis[205];

void init() {
	for(int i=0; i<205; i++)
		for(int j=0; j<205; j++)
			maps[i][j] = 10000000.0;
	for(int i=0; i<205; i++)
		dis[i] = 10000000.0;
	memset(vis, false, sizeof(vis));
}

double distance(int x1, int y1, int x2, int y2) {
	double ans=sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	return ans;
}

void dijkstra(int n) {
	vis[1]=true;
	for(int i=1; i<=n; i++) {
		dis[i] = maps[1][i];
	}
	for(int r=2; r<=n; r++) {
		int p=0;
		for(int i=1; i<=n; i++) {
			if(!vis[i] && dis[p] > dis[i]) {
				p=i;
			}
		}
		vis[p]=true;
		for(int i=1; i<=n; i++) { 
			if(dis[i] > dis[p] + maps[p][i]) { 
				dis[i] = dis[p] + maps[p][i];
			} 
		} 
	}
}

int main() {
	while(scanf("%d%d%d%d",&bex,&bey,&enx,&eny) != EOF) {
		init();
		double vw=10000/60;
		double vs=40000/60;
		int x,y;
		int sum=2;
		while(scanf("%d%d",&x,&y) != EOF) {
			sux[sum] = x;
			suy[sum] = y;
			sum++;
			while(scanf("%d%d",&x,&y), !(x==-1&&y==-1)) {
				maps[sum][sum-1] = distance(x, y, sux[sum-1], suy[sum-1]) / vs;
				maps[sum-1][sum] = maps[sum][sum-1];
				sux[sum]=x;
				suy[sum]=y;
				sum++;
			}
		}
		for(int i=2; i<sum; i++) {
			for(int j=2; j<sum; j++) {
				double len=distance(sux[i], suy[i], sux[j], suy[j]);
				maps[i][j] = maps[j][i] = min(len/vw, maps[i][j]);
			}
		}

		for(int i=2; i<sum; i++) {
			double len=distance(bex, bey, sux[i], suy[i]);
			maps[1][i] = maps[i][1] = len/vw;
			len=distance(enx, eny, sux[i], suy[i]);
			maps[sum][i] = maps[i][sum] = len/vw;
		}
		maps[1][sum] = maps[sum][1] = distance(bex, bey, enx, eny) / vw;
		maps[1][1] = 0;
		maps[sum][sum] = 0; 
/*		
		for(int i=2; i<=sum; i++)
			for(int j=2; j<=sum; j++)
				printf("%.2lf%c",maps[i][j], j==sum ? '\n':'\t');
*/		
		dijkstra(sum);
/*
		for(int i=0; i<=sum; i++)
			printf("%.2lf   ",dis[i]);
*/		
		printf("%d\n", (int)(dis[sum]+0.5));
	}
	return 0;
}
