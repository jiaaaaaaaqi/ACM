/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年07月17日 星期三 09时38分01秒
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

int phi[maxn], pri[maxn], mob[maxn];
ll f[maxn], g[maxn];
bool ispri[maxn];

void handle() {
	int mx = 1e5;
	tol = 0, mob[1] = 1;
	mes(pri, 0), mes(ispri, 1);
	for(int i=2; i<=mx; i++) {
		if(ispri[i]) {
			pri[++tol] = i;
			mob[i] = -1;
		}
		for(int j=1; j<=tol && i*pri[j]<=mx; j++) {
			ispri[i*pri[j]] = false;
			if(i%pri[j] == 0) {
				mob[i*pri[j]] = 0;
				break;
			} else {
				mob[i*pri[j]] = -mob[i];
			}
		}
	}
}

int main() {
	handle();
	scanf("%d", &T);
	cas = 1;
	while(T--) {
		ll a, b, c, d, k;
		scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &d, &k);
		if(k == 0) {
			printf("Case %d: 0\n", cas++);
			continue;
		}
		b/=k, d/=k;
		if(b > d)	swap(b, d);
		ll ans1 = 0, ans2 = 0;
		for(int i=1; i<=b; i++)
			ans1 += 1ll*mob[i]*(b/i)*(d/i);
		for(int i=1; i<=b; i++)
			ans2 += 1ll*mob[i]*(b/i)*(b/i);
		ll ans = ans1 - (ans2-1)/2; 
		printf("Case %d: %lld\n", cas++, ans);
	}
    return 0;
}
