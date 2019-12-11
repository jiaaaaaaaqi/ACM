#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<string>
#include<queue>
#include<map>
#define inf 0x3f3f3f3f

typedef long long int ll;
using namespace std;
const int maxn = 505;

int n, m;
int degree[maxn];
bool maps[maxn][maxn];
map<string,int> m1;

void init() {
	m1.clear();
	memset(maps, 0, sizeof(maps));
	memset(degree, 0, sizeof(degree));
}

bool topsort(int n) {
	int cnt = 0;
	for(int i=1; i<n; i++) {
		if(degree[i] == 0) {
			cnt++;
		}
	}
	if(cnt == 1)
		return true;
	else
		return false;
}

int main() {
	while(scanf("%d", &n), n) {
		init();
		int cnt = 1;
		for(int i=0; i<n; i++) {
			string str1, str2;
			cin >> str1;
			cin >> str2;
			if(!m1[str1])
				m1[str1] = cnt++;
			if(!m1[str2])
				m1[str2] = cnt++;
			int u = m1[str1];
			int v = m1[str2];
			if(maps[u][v] == 0) {
				maps[u][v] = true;
				degree[v]++;
			}
		}
		if(topsort(cnt))
			printf("Yes\n");
		else 
			printf("No\n");
	}
	return 0;
}