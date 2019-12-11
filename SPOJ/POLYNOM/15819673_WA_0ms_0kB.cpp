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
#define lowbit(x) 	x & (-x)
#define fi			first
#define	se			second
#define INOPEM  	freopen("in.txt", "r", stdin)
#define OUTOPEN 	freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 550;
const int    maxm = 1<<10;
const int    mod  = 1000000007;
const ll     INF  = 1e18+100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0*atan(1.0);
using namespace std;

int n, m;
int tol, T;
ll x[maxn];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			scanf("%d", &x[i]);
		}
		if(n == 1) {			
			printf("YES\n");
		} else if(n == 2) {
			printf("YES\n");
		} else if(n == 3) {
			ll x1 = x[1];
			ll x2 = x[2];
			ll x3 = x[3];
			ll tmp = x1 + x3 - 2*x2;
			if(tmp % 2 == 0) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		} else {
			ll x1 = x[1];
			ll x2 = x[2];
			ll x3 = x[3];
			ll x4 = x[4];
			ll a, b, c, d;
			ll tmp = -x1 + 3*x2 - 3*x3 + x4;
			if(tmp % 7 == 0) {
				a = tmp / 7;
			} else {
				printf("NO\n");
				continue;
			}
			tmp = x1 + x3 - 2*x2 - 11*a;
			if(tmp % 2 == 0) {
				b = tmp / 2;
			} else {
				printf("NO\n");
			}
			c = x2 - x1 - 7*a - 3*b;
			d = x1 - a - b - c;
			bool flag = true;
			for(int i=1; i<=n; i++) {
				tmp = a*i*i*i + b*i*i + c*i + d;
				if(tmp != x[i]) {
					flag = false;
					break;
				}
			}
			if(flag)	printf("YES\n");
			else		printf("NO\n");
		}
	}
	return 0;
}
