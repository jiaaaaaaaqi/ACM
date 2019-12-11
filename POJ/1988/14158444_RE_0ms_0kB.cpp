#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 3005;
using namespace std;

int n, m;
int num[maxn];
int fath[maxn];
int dis[maxn];

void init() {
	for(int i=0; i<maxn; i++) {
		fath[i] = i;
		num[i] = 1;
		dis[i] = 0;
	}
}

int find(int x) {
	if(fath[x] == x)	return x;
	int tmp = fath[x];
	fath[x] = find(fath[x]);
	dis[x] += dis[tmp];
	return fath[x];
}

void bind(int x, int y) {
	fath[x] = y;
	dis[x] += num[y];
	num[y] += num[x];
}

int main() {
	while(~scanf("%d", &m)) {
		init();
		char str[10];
		while(m--) {
			scanf("%s", str);
			if(str[0] == 'M') {
				int pos1, pos2;
				scanf("%d%d", &pos1, &pos2);
				int x = find(pos1);
				int y = find(pos2);
				if(x != y) 	bind(x, y);
			} else {
				int pos;
				scanf("%d", &pos);
				find(pos);
				printf("%d\n", dis[pos]);
			}
		}
	}
	return 0;
}
