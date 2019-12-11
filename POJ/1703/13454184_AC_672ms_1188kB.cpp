#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn = 100005;
struct Node {
	int fath;
	int rela;
};
Node node[maxn];

void init(int n) {

	for(int i=0; i<=n; i++) {
		node[i].fath = i;
		node[i].rela = 0;
	}
}

int find(int x) {
	if(node[x].fath == x) {
		return x;
	} else {
		int tmp = node[x].fath;
		node[x].fath = find(tmp);
		node[x].rela = (node[x].rela + node[tmp].rela) % 2;
		return node[x].fath;
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		init(n);
		while(m--) {
			char ch[5];
			int u, v;
			scanf("%s %d %d", ch, &u, &v);
			int x = find(u);
			int y = find(v);
			if(ch[0] == 'A') {
				if(x == y) {
					int d = (node[u].rela - node[v].rela + 2) % 2;
					if(d == 0) {
						printf("In the same gang.\n");
					} else {
						printf("In different gangs.\n");
					}
				} else {
					printf("Not sure yet.\n");
				}
			} else if(ch[0] == 'D') {
				node[y].fath = x;
				node[y].rela = (2 + 1 + node[u].rela - node[v].rela) % 2;
			}
		}
	}
}