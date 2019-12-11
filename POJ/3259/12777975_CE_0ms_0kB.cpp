#include<iostream>
#include<cstring>
#include<algorithm>
#define inf 0x3f3f3f3f

using namespace std;

int n;
int maps[505][505];
int vis[505];

void init() {
	memset(maps, inf, sizeof(maps));
	memset(vis, false, sizeof(false));
}

bool Bellman_Ford() {
	for(int k=1; k<=n; k++) { 
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(maps[i][j] > maps[i][k] + maps[k][j]) { 
					maps[i][j] = maps[i][k] + maps[k][j];
				}
			}
			if(maps[i][i] < 0)
				return true;
		}
	}
	return false;
}


int main() {
	int T;
	cin >> T;
	while(T--) {
		init();
		int m,k;
		cin>> n >> m >> k;
		for(int i=0; i<m; i++) {
			int u,v,w;
			cin >> u >> v >> w;
			if(maps[u][v] > w) 
				maps[u][v] = maps[v][u] = w;
		}
		for(int i=0; i<k; i++) {
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			w=-w;
			if(maps[u][v] > w)
				maps[u][v] = w;
		}
		bool ans=Bellman_Ford();
/*
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++)
				cout << maps[i][j] << "  " ;
			cout << endl;
		}
*/
		if(ans) 
			cout << "YES" <<endl;
		else 
			cout << "NO" << endl;
	}
	return 0;
}