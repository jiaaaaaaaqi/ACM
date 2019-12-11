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
vector<int> maps[maxn];

void init() {
	n = 0;
	for(int i=0; i<maxn; i++)
		maps[i].clear();
	memset(id, 0, sizeof(id));
	memset(alp, 0, sizeof(alp));
	memset(ind, 0, sizeof(ind));
	memset(ans, 0, sizeof(ans));
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
			for(int j=0; j<maps[i].size(); j++) {
				ind[maps[i][j]]--;
			}
			topu(len+1);
			ind[i]++;
			for(int j=0; j<maps[i].size(); j++) {
				ind[maps[i][j]]++;
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
		for(int i=0; i<len; i+=4) {
			int u = id[str[i] - 'a'];
			int v = id[str[i+2] - 'a'];
			ind[v]++;
			maps[u].push_back(v);
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
	}
	return 0;
}

