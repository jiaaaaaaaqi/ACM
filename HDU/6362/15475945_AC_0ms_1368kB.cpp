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
typedef unsigned int ui;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 205;
const int maxm = 2e5+10;
const int mod = 1<<30;
const double eps = 1e-8;
using namespace std;

int n, m;
int T, tol;
int ans;

///2b + aπ
int main() {
	scanf("%d", &T);
	while(T--) {
		int a, b;
		scanf("%d%d", &a, &b);
		double ans = (double)2*b + (double)a*pi;
		printf("%.6f\n", ans-0.0000005);
	}
	return 0;
}
