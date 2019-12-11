#include <cstdio>
#include <cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 50050;
int father[MAX];             //记录父节点
int N,K;

int relation[MAX];          //关系数组，表示其父节点与他的关系    0表示同类，1表示被父节点吃  ，2表示吃父节点

void init() {
	int i;
	for (i = 0; i < MAX; i++) {
		father[i] = i;
		relation[i] = 0;
	}
}


int find(int x) {
	if (x != father[x]) {
		int temp = father[x];
		father[x] = find(father[x]);
		relation[x] = (relation[x] + relation[temp]) % 3;
	}
	return father[x];
}


int join(int x,int y,int re) {
	int a = find(x);
	int b = find(y);
	if (a != b) {
		father[b] = a;
		relation[b] = (relation[x] + (re - 1) + (3 - relation[y])) % 3;
	} else {
		if ((re - 1) != (3 - relation[x] + relation[y]) % 3)
			return 1;
	}
	return 0;
}




int main() {
	int i, j;
	int d, x, y;
	scanf("%d%d", &N,&K);
 		int ans = 0;
		init();
		for (i = 0; i < K; i++) {
			scanf("%d%d%d", &d, &x, &y);
			if (x > N || y > N)
				ans++;
			else if (d==2&&x == y)
				ans++;
			else {
				ans+=join(x, y, d);
			}
		}
		printf("%d\n", ans);
	return 0;
}