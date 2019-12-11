#include<map>
#include<queue>
#include<string>
#include<vector>
#include<math.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define inf 0x3f3f3f3f

typedef long long int ll;
using namespace std;

const int maxn = 2005;

int n, m, nn;
vector<int> mapsx[maxn], mapsy[maxn], mapsz[maxn];
int indx[maxn], indy[maxn], indz[maxn];
int ansx[maxn], ansy[maxn], ansz[maxn];

void init() {
	memset(indx, 0, sizeof indx);
	memset(indy, 0, sizeof indy);
	memset(indz, 0, sizeof indz);
	memset(ansx, 0, sizeof ansx);
	memset(ansy, 0, sizeof ansy);
	memset(ansz, 0, sizeof ansz);
	for(int i=0; i<maxn; i++) {
		mapsx[i].clear();
		mapsy[i].clear();
		mapsz[i].clear();
	}
}

bool topu(vector<int> maps[], int ind[], int ans[]) {
	queue<int> q;
	for(int i=1; i<=nn; i++) {
		if(ind[i] == 0) {
			q.push(i);
		}
	}
	int num = 0;
	while(!q.empty()) {
		int t = q.front();
		q.pop();
		ans[t] = num++;
		int len = maps[t].size();
		for(int i=0; i<len; i++) {
			ind[maps[t][i]]--;
			if(ind[maps[t][i]] == 0) {
				q.push(maps[t][i]);
			}
		}
	}
	return num == nn;
}

int main() {
	int cas = 1;
	while(scanf("%d%d", &n, &m), n||m) {
		init();
		nn = 2 * n;
		for(int i=1; i<=n; i++) {
			indx[i+n]++;
			mapsx[i].push_back(i+n);
			indy[i+n]++;
			mapsy[i].push_back(i+n);
			indz[i+n]++;
			mapsz[i].push_back(i+n);
		}
		for(int i=0; i<m; i++) {
			char str[10];
			int u, v;
			scanf("%s%d%d", str, &u, &v);
			if(str[0] == 'I') {
				indx[u + n]++;
				mapsx[u].push_back(v + n);
				indx[v + n]++;
				mapsx[v].push_back(u + n);
				indy[u + n]++;
				mapsy[u].push_back(v + n);
				indy[v + n]++;
				mapsy[v].push_back(u + n);
				indz[u + n]++;
				mapsz[u].push_back(v + n);
				indz[v + n]++;
				mapsz[v].push_back(u + n);
			} else if(str[0] == 'X') {
				indx[v]++;
				mapsx[u + n].push_back(v);
			} else if(str[0] == 'Y') {
				indy[v]++;
				mapsy[u + n].push_back(v);
			} else if(str[0] == 'Z') {
				indz[v]++;
				mapsz[u + n].push_back(v);
			}
		}
		printf("Case %d: ", cas++);
		bool flag = true;
		if(!topu(mapsx, indx, ansx))
			flag = false;
		if(!topu(mapsy, indy, ansy))
			flag = false;
		if(!topu(mapsz, indz, ansz))
			flag = false;
		if(flag) {
			printf("POSSIBLE\n");
			for(int i=1; i<=n; i++) {
				printf("%d %d %d %d %d %d\n", ansx[i], ansy[i], ansz[i], 
					ansx[i + n], ansy[i + n], ansz[i + n]);
			}
		} else {
			printf("IMPOSSIBLE\n");
		}
		printf("\n");
	}
	return 0;
}
