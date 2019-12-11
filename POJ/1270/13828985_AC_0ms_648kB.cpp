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

const int maxn = 30;

int n;
int id[300];
int ind[maxn];
int ans[maxn];
char alp[maxn];
bool maps[maxn][maxn];

void init() {
	n = 0;
	memset(id, 0, sizeof(id));
	memset(alp, 0, sizeof(alp));
	memset(ind, 0, sizeof(ind));
	memset(ans, 0, sizeof(ans));
	memset(maps, false, sizeof(maps));
}

void topu(int len) {
	if(len == n) {
		for(int i=0; i<n; i++) {
			printf("%c", ans[i]);
		}
		printf("\n");
		return ;
	}
	for(int i=0; i<n; i++) {
		if(ind[i] == 0) {
			ind[i]--;
			ans[len] = alp[i];
			for(int j=0; j<n; j++) {
				if(maps[i][j]) {
					ind[j]--;
				}
			}
			topu(len+1);
			ind[i]++;
			for(int j=0; j<n; j++) {
				if(maps[i][j]) {
					ind[j]++;
				}
			}
		}
	}
}

int main() {
	char str[maxn];
	while(gets(str) != NULL) {
		init();
		int len = strlen(str);
		n = 0;
		for(int i=0; i<len; i++) {
			if(isalpha(str[i]))
				alp[n++] = str[i];
		}
		sort(alp, alp+n);
		for(int i=0; i<n; i++)
			id[alp[i] - 'a'] = i;
		memset(str, 0, sizeof(str));
		gets(str);
		len = strlen(str);
		int flag = 0;
		int u, v;
		for(int i=0; i<len; i++) {
			if(isalnum(str[i])) {
				if(!flag) {
					u = id[str[i] - 'a'];
					flag = 1;
				} else {
					v = id[str[i] - 'a'];
					ind[v]++;
					maps[u][v] = true;
					flag = 0;
				}
			}
		}
		/*
		for(int i=0; i<n; i++) {
			printf("%d", i);
			for(int j=0; j<maps[i].size(); j++) {
				printf(" %d", maps[i][j]);
			}
			printf("\n");
		}
		*/
		topu(0);
		printf("\n");
		memset(str, 0, sizeof(str));
	}
	return 0;
}

