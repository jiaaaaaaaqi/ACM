#include<map>
#include<queue>
#include<string>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define inf 0x3f3f3f3f

typedef long long int ll;
using namespace std;

const int maxn = 35;

char str[maxn][maxn];
vector<int> maps[maxn];
struct Node {
	int x;
	int y;
} node[maxn][2];
int ind[maxn];
int ans[maxn];
int n, m;
int numch;

void init() {
	numch = 0;
	memset(ans, 0, sizeof ans);
	memset(ind, 0, sizeof ind);
	memset(str, 0, sizeof str);
	memset(ind, -1, sizeof ind);
	for(int i=0; i<maxn; i++) {
		maps[i].clear();
		node[i][0].x = node[i][0].y = -1;
		node[i][1].x = node[i][1].y = -1;
	}
}

void handle() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(str[i][j] == '.')
				continue;
			int ch = str[i][j] - 'A';
			ind[ch] = 0;
			if(node[ch][0].x == -1) {
				numch++;
				node[ch][0].x = i;
				node[ch][0].y = j;
				node[ch][1].x = i;
				node[ch][1].y = j;
			} else {
				node[ch][0].x = min(i, node[ch][0].x);
				node[ch][0].y = min(j, node[ch][0].y);
				node[ch][1].x = max(i, node[ch][1].x);
				node[ch][1].y = max(j, node[ch][1].y);
			}
		}
	}
}

void getmap() {
	for(int num=0; num<26; num++) {
		if(node[num][0].x == -1)
			continue;
		for(int i=node[num][0].x; i<=node[num][1].x; i++) {
			if(i == node[num][0].x || i == node[num][1].x) {
				for(int j=node[num][0].y; j<=node[num][1].y; j++) {
					if(str[i][j] == '.')
						continue;
					int ch = str[i][j] - 'A';
					if(num != ch) {
						ind[ch]++;
						maps[num].push_back(ch);
					}
				}
			} else {
				if(str[i][node[num][0].y] != '.') {
					int ch = str[i][node[num][0].y] - 'A';
					if(num != ch) {
						ind[ch]++;
						maps[num].push_back(ch);
					}
				}
				if(str[i][node[num][1].y] != '.') {
					int ch = str[i][node[num][1].y] - 'A';
					if(num != ch) {
						ind[ch]++;
						maps[num].push_back(ch);
					}
				}
			}
		}
	}
}

void dfs(int len) {
	if(len == numch) {
		for(int i=0; i<len; i++) {
			printf("%c", ans[i] + 'A');
		}
		printf("\n");
		return ;
	}
	for(int num=0; num<26; num++) {
		if(node[num][0].x == -1) 
			continue;
		if(ind[num] == 0) {
			int ch = num;
			ans[len] = ch;
			ind[num]--;
			for(int i=0; i<maps[num].size(); i++) {
				ind[maps[num][i]]--;
			}
			dfs(len+1);
			for(int i=0; i<maps[num].size(); i++) {
				ind[maps[num][i]]++;
			}
			ind[num]++;
		}
	}
}

int main() {
	while(~scanf("%d", &n)) {
		scanf("%d", &m);
		init();
		for(int i=1; i<=n; i++) {
			scanf("%s", str[i]+1);
		}
		handle();
		getmap();
		/*
		for(int i=0; i<numch; i++) {
			printf("%d %d\n", node[i][0].x, node[i][0].y);
		}
		for(int i=0; i<26; i++) {
			printf("%d\n", ind[i]);
		}
		*/
		dfs(0);
	}
	return 0;
}
