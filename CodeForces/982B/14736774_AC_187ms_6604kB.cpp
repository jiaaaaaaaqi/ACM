#include<map>
#include<set>
#include<ctime>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 200005;
const int maxm = 30005;
const int mod = 1000000007;
using namespace std;

int n, m, tol;
struct Node{
	int id, num;
	bool operator < (Node a) const {
		return num < a.num;
	}
};
Node node[maxn];
struct Edge{
	int num;
	int id;
	bool operator < (Edge a) const {
		return num < a.num;
	}
};
priority_queue<Edge> q;
char str[maxn << 1];
int ans[maxn << 1];

void init() {
	memset(str, 0 ,sizeof str);
	memset(node, 0, sizeof node);
	memset(ans, 0, sizeof ans);
}

int main() {
	while(~scanf("%d", &n)) {
		init();
		for(int i=1; i<=n; i++) {
			scanf("%d", &node[i].num);
			node[i].id = i;
		}
		sort(node+1, node+1+n);
		scanf("%s", str);
		int len = 2*n;
		int j = 1;
		tol = 1;
		for(int i=0; i<len; i++) {
			if(str[i] == '0') {
				Edge e;
				e.id = node[j].id;
				e.num = node[j].num;
				ans[tol++] = node[j].id;
				j++;
				q.push(e);
			}
			else if(str[i] == '1') {
				Edge e = q.top();
				ans[tol++] = e.id;
				q.pop();
			}
		}
		for(int i=1; i<tol; i++)	printf("%d%c", ans[i], i==tol-1 ? '\n' : ' ');
	}
	return 0;
}
