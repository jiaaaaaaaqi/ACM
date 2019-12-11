/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年07月17日 星期三 10时20分16秒
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
const int    maxn = 1e7 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

ll n, m;
int cas, tol, T;

int pri[maxn], mob[maxn];
bool ispri[maxn];
ll sum[maxn];

void handle() {
	mes(sum, 0), mes(pri, 0), mes(ispri, 1);
	tol = 0;
	mob[1] = 1;
	int mx = 1e7;
	for(int i=2; i<=mx; i++) {
		if(ispri[i]) {
			pri[++tol] = i;
			mob[i] = -1;
			sum[i] = 1;
		}
		for(int j=1; j<=tol && i*pri[j]<=mx; j++) {
			ispri[i*pri[j]] = false;
			if(i%pri[j] == 0) {
				mob[i*pri[j]] = 0;
				sum[i*pri[j]] = mob[i];
				break;
			} else {
				mob[i*pri[j]] = -mob[i];
				sum[i*pri[j]] = mob[i] - sum[i];
			}
		}
	}
}

int main() {
	handle();
	scanf("%lld", &n);
	ll ans = 0;
	for(ll d=2; d<=n; d++) {
		ans += 1ll*sum[d]*(n/d)*(n/d);
	}
	printf("%lld\n", ans);
	return 0;
}

