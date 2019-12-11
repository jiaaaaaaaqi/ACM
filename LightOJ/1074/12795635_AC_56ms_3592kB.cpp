#include<stdio.h>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;

const int maxn = 100005;
const int maxm = 205;
const int oo = 0xfffffff;

struct node {
	int u, v, c, next;
} e[maxn];
int dis[maxm], head[maxm];
int busy[maxn], p[maxn];//p数组记录一共访问的次数
bool use[maxm];

void Add(int u, int v, int c, int k) {
	e[k].u = u;
	e[k].v = v;
	e[k].c = c*c*c;
	e[k].next = head[u];
	head[u] = k;
}
void spfa(int N) {
	queue<int> Q;
	Q.push(1);

	while(Q.size()) {
		int i = Q.front();
		Q.pop();
		use[i] = false, p[i]++;

		for(int j=head[i]; j!=0; j=e[j].next) {
			int u = e[j].u, v = e[j].v, c = e[j].c;
			if(dis[u]+c < dis[v]) {
				dis[v] = dis[u]+c;

				if(use[v] == false && p[v] <= N) {
					use[v] = true;
					Q.push(v);
				}
			}
		}
	}
}

int main() {
	int T, t=1;
	scanf("%d", &T);
	while(T--) {
		int i, N, M, k=1, u, v;
		scanf("%d", &N);
		for(i=1; i<=N; i++) {
			dis[i] = oo;
			head[i] = 0;
			p[i] = 0;
			scanf("%d", &busy[i]);
		}
		scanf("%d", &M);
		while(M--) {
			scanf("%d%d", &u, &v);
			Add(u, v, busy[v]-busy[u], k++);
		}
		scanf("%d", &M);
		printf("Case %d:\n", t++);
		dis[1] = 0;
		spfa(N);
		while(M--) {
			scanf("%d", &v);
			if(dis[v] == oo || dis[v] < 3 || p[v] > N)
				printf("?\n");
			else
				printf("%d\n", dis[v]);
		}
	}
	return 0;
}