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
const int maxn = 110;
const int maxm = 2010;
const int mod = 998244353;
using namespace std;

int n, m;
int T, tol,  num[5005];

int main() {
	int T;
	scanf("%d", &T);
	
	while (T--) {
		int n;
		scanf("%d", &n);
		int maxi = 0, sum =0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &num[i]);
			if (i >= 2) {
				maxi = max(maxi, num[i]-num[i-1]-1);
				sum += (num[i]-num[i-1]-1);
			}
		}
		if (n == 3) printf("%d\n", maxi);
		else printf("%d\n", sum);
	}
	return 0;	
}
