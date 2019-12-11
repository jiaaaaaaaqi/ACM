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
const int maxn = 1005;
const int maxm = 1000005;
const int mod = 10007;
using namespace std;

int n, m, tol, T;

int main() {
	scanf("%d", &n);
	ll sum1 = 0;
	ll x;
	for(int i=1; i<=n; i++) {
		scanf("%I64d", &x);
		sum1 += x;
	}
	ll sum2 = 0;
	for(int i=1; i<=n; i++) {
		scanf("%I64d", &x);
		sum2 += x;
	}
	if(sum1 >= sum2)	printf("Yes\n");
	else		printf("No\n");
    return 0;
}