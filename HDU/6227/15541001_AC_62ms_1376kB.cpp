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
int T, tol;
int a[600];

int main() {
	scanf("%d", &T);
	while(T--) {
		memset(a, 0, sizeof a);
		scanf("%d", &n);
		int s = 0;
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);	
			if(i == 1)	continue;
			s += a[i] - a[i-1] - 1;
		}
		if(a[2]-a[1] <= a[n] - a[n-1]) {
			s -= a[2] - a[1] - 1;
		} else {
			s -= a[n] - a[n-1] - 1;
		}
		cout << s << endl;
	}	
	return 0;	
}
