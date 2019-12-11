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
const int maxm = 10000007;
const int mod = 1000000020;
using namespace std;

int n, m, tol, T;
int a[maxn];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i=1; i<=n; i++)	scanf("%d", &a[i]);
		int ans = abs(a[n] - a[1]);
		ans = (int)sqrt(ans);
		printf("%d\n", ans);
	}
    return 0;
}
