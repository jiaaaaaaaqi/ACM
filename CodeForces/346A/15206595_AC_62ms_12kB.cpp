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
const int maxn = 1e5+10;
const int maxm = 1e11;
const int mod = 1e9+7;
using namespace std;

int n, m;
int T, tol;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}

int main() {
	scanf("%d", &n);
	int mx = 0;
	int g = 0;
	for(int i=1; i<=n; i++) {
		int x;
		scanf("%d", &x);
		g = gcd(g, x);
		mx = max(x, mx);
	}
	int cnt = mx / g - n;
	if(cnt & 1)	printf("Alice\n");
	else	printf("Bob\n");
	return 0;
}
