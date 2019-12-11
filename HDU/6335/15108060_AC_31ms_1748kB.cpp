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
const int maxn = 120;
const int maxm = 10000007;
const int mod = 1000000020;
using namespace std;

int n, m, tol, T;
struct Node{
	ll a;
	ll b;
	bool operator < (Node a) const {
		return b < a.b;
	}
};
Node node[maxn];

int main() {
	scanf("%d", &T);
	while(T--) {
		memset(node, 0, sizeof node);
		scanf("%d%d", &n, &m);
		for(int i=1; i<=n; i++)	scanf("%I64d%I64d", &node[i].a, &node[i].b);
		sort(node+1, node+1+n);
		ll ans = 0;
		ll sum = 1;
		for(int i=1; i<=n; i++) {
			sum *= (node[i].a + node[i].b);
			 if(sum > m)	break;
			 ans++;
		}
		printf("%I64d\n", ans);
	}
    return 0;
}
