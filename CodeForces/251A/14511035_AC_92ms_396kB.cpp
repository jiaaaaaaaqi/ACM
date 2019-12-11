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
#define mem(a, b) memset(a, b, sizeof a)

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 100005;
const int maxm = 305;
using namespace std;

int n, m, tol;
int num[maxn];

int main() {
	while(~scanf("%d%d", &n, &m)) {
		for(int i=1; i<=n; i++)	scanf("%d", &num[i]);
		ll ans = 0;
		for(int i=1; i<=n; i++) {
			int pos = upper_bound(num+1, num+1+n, num[i]+m) - num;
			pos--;
			ll x = pos - i;
			if(x & 1)	ans += (x-1) / 2 * x;
			else	ans += x / 2 * (x-1);
		}
		printf(("%I64d\n"), ans);
	}
	return 0;
}
