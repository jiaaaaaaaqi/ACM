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
const int maxm = 1000005;
const int mod = 10007;
using namespace std;

int T, tol;
int n, m;

int main() {
	scanf("%d", &T);
	while(T--) {
		ll ans = 0, x;
		scanf("%d", &n);
		for(int i=1; i<=n; i++)	{
			scanf("%lld", &x), ans ^= x;
		}
		for(int i=1; i<n; i++)	scanf("%lld%lld", &x, &m);
		printf("%s\n", ans ? "Q" : "D");
	}
	return 0;
}
