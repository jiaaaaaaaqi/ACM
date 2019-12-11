#include<map>
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
const int maxm = 1 << 8;
const int mod = 200;
using namespace std;

int n, m, tol;
struct Node{
	int x;
	int y;
};
Node node[maxn];

int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		node[i].x = max(x, y);
		node[i].y = min(x, y);
	}
	int top = node[1].x;
	bool flag = true;
	for(int i=2; i<=n; i++) {
		if(top >= node[i].x) {
			top = node[i].x;
		} else if(top >= node[i].y) {
			top = node[i].y;
		} else {
			flag = false;
			break;
		}
	}
	flag ? printf("YES\n") : printf("NO\n");
	return 0;
}