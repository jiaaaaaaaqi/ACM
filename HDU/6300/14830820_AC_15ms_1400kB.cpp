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
#define first fi
#define second se
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 3005;
const int maxm = 305;
using namespace std;

int n, m, tol, T;
struct Node{
	int x, y, id;
	bool operator < (Node a) const {
		return x < a.x;
	}
};
Node node[maxn];

void init() {
	memset(node, 0, sizeof node);
}

int main() {
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d", &n);
		n = 3*n;
		for(int i=1; i<=n; i++) {
			scanf("%d%d", &node[i].x, &node[i].y);
			node[i].id = i;
		}
		sort(node+1, node+1+n);
		for(int i=1; i<=n; i+=3) {
			printf("%d %d %d\n", node[i].id, node[i+1].id, node[i+2].id);
		}
	}
	return 0;
}
