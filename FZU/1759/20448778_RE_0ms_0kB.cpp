/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年07月15日 星期一 14时47分29秒
 ***************************************************************/

#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <cfloat>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pii        pair<int, int>

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

ll A, B, C;
char s[maxn];

ll phi(ll x) {
	ll ans = x;
	for(ll i=2; i*i<=x; i++) {
		if(x%i == 0) {
			ans = ans/i*(i-1);
			while(x%i == 0)	x /= i;
		}
	}
	if(x>1)	ans = ans/x*(x-1);
	return ans;
}

ll fpow(ll a, ll b, ll mod) {
	ll ans = 1;
	while(b) {
		if(b&1)	ans = ans*a%mod;
		a = a*a%mod;
		b >>= 1;
	}
	return ans;
}

int main() {
	while(~scanf("%lld %s %lld", &A, s+1, &C)) {
		int len = strlen(s+1);
		ll phiC = phi(C);
		bool flag = false;
		for(ll i=1, tmp=0; i<=len; i++) {
			tmp = tmp*10+s[i]-'0';
			if(tmp > phiC) {
				flag = true;
				break;
			}
		}
		if(flag) {
			B = 0;
			for(int i=1; i<=len; i++) 
				B = (B*10 + s[i]-'0')%phiC;
			printf("%lld\n", fpow(A, B+phiC, C));
		} else {
			B = 0;
			for(int i=1; i<=len; i++)
				B = B*10 + s[i]-'0';
			printf("%lld\n", fpow(A, B, C));
		}
	}
    return 0;
}

