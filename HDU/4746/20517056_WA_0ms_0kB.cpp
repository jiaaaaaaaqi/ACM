/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年07月17日 星期三 14时38分33秒
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
const int    maxn = 5e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m, P;
int cas, tol, T;

ll ans;
int pri[maxn], mob[maxn], cnt[maxn];
ll c[maxn][20];
bool ispri[maxn];

void handle() {
	mes(pri, 0), mes(ispri, 1);
	tol = 0;
	int mx = 5e5;
	mob[1] = 1;
	cnt[1] = 0;
	for(int i=2; i<=mx; i++) {
		if(ispri[i]) {
			pri[++tol] = i;
			mob[i] = -1;
			cnt[i] = 1;
		}
		for(int j=1; j<=tol&&i*pri[j]<=mx; j++) {
			ispri[i*pri[j]] = false;
			cnt[i*pri[j]] = cnt[i]+1;
			if(i%pri[j] == 0) {
				mob[i*pri[j]] = 0;
				break;
			} else {
				mob[i*pri[j]] = -mob[i];
			}
		}
	}
	mes(c, 0);
	for(int i=1; i<=mx; i++) {
		for(int j=i; j<=mx; j+=i) {
			c[j][cnt[i]] += mob[j/i];
		}
	}
	for(int i=1; i<=mx; i++) {
		for(int j=1; j<=19; j++) {
			c[i][j] += c[i][j-1];
		}
	}
	for(int i=1; i<=mx; i++) {
		for(int j=0; j<=19; j++) {
			c[i][j] += c[i-1][j];
		}
	}
}

int main() {
	handle();
	scanf("%d", &T);
	while(T--) {
		ans = 0;
		scanf("%d%d%d", &n, &m, &P);
		if(n > m)	swap(n, m);
		ll ans = 0;
		int l = 0, r;
		for(int i=1; i<=n; i=r+1) {
			r = min(n/(n/i), m/(m/i));
			ans += (n/i)*(m/i)*(c[r][P]-c[l][P]);
			l = r;
		}
		printf("%lld\n", ans);
	}
    return 0;
}

