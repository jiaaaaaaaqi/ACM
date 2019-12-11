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

int n, m, tol, T;
int a[maxn << 1];

int main() {    
	scanf("%d", &n);
	for(int i=1; i<=2*n; i++)	scanf("%d", &a[i]);
	sort(a+1, a+1+2*n);
	ll ans = 1ll * (a[n]-a[1]) * (a[2*n]-a[n+1]);
	for(int i=2; i<=n; i++)	ans = min(ans, 1ll * (a[2*n]-a[1]) * (a[n+i-1]-a[i]));
	printf("%I64d\n", ans);
    return 0;
}