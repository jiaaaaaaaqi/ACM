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
const int maxn = 100005;
const int maxm = 50005;
const int mod = 10007;
using namespace std;

int n, m, tol, T;
struct Node{
	int x;
	int y;
	bool operator < (Node a) const{
		return (x-y) > (a.x-a.y);
	}
};
Node node[maxn];

int main() {
	scanf("%d%d", &n, &m);
	ll ans1 = 0;
	ll ans2 = 0;
	for(int i=1; i<=n; i++) {
		scanf("%d%d", &node[i].x, &node[i].y);
		ans1 += node[i].x;
		ans2 += node[i].y;
	}
	if(ans1 <= m) {
		printf("0\n");
		return 0;
	}
	if(ans2 > m) {
		printf("-1\n");
		return 0;
	}
	sort(node+1, node+1+n);
	int ans = 0;
	for(int i=1; i<=n; i++) {
		ans++;
		ans1 -= node[i].x;
		ans1 += node[i].y;
		if(ans1 <= m)	break;
	}
	printf("%d\n", ans);
    return 0;
}