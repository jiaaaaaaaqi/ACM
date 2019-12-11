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
const int    maxn = 10005;
const int    maxm = 1<<10;
const int    mod  = 1000000007;
const ll     INF  = 1e18+100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0*atan(1.0);
using namespace std;

ll n;
ll f[20];
ll judge(ll x) {
	while (x % 10 == 0) {
		x /= 10;
	}
	int len = log10(x);
	if (x % 10 == 5) return len*2-1;
	else return len*2;
}

int main() {
	f[0] = 1;
	for (int i = 1; i <= 17; i++)
		f[i] = f[i-1] * 10;
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%lld", &n);
		ll left = n * 95;
		ll right = n * 105;
		ll tright = right;
		n *= 100;
		ll ans = right;
		int i = 1;
		while(1) {
			bool flag = false;
			right /= f[i];
			right *= f[i];
			if(right == 0)	break;
			if(left <= right) {
				ans = right;
				flag = true;
			} else {
				right += 5*f[i-1];
				if(right > tright)	break;
				if(left <= right) {
					ans = right;
					flag = true;
				}
			}
			if(!flag)	break;
			i++;
		}
		if(judge(ans) < judge(n)) {
			printf("absurd\n");
		} else {
			printf("not absurd\n");
		}
	}
	return 0;
}
