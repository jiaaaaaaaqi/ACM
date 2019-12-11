/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年08月20日 星期二 11时28分59秒
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
#define  pb         push_back
#define  pii        pair<int, int>

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 3e6 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

char s[maxn];
int digit[30];

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%s", s+1);
		mes(digit, 0);
		int len = strlen(s+1);
		int cnt = 1;
		for(int i=1; i<=len; i++) {
			if(s[i] == '^') {
				if(cnt&1)	digit[1] = !digit[1];
				for(int i=21; i>=2; i--) {
					if(!digit[i] && cnt>=(1<<(i-1))) {
						digit[i] = 1;
						cnt -= (1<<(i-1));
					}
				}
				cnt = 1;
			} else {
				cnt++;
			}
		}
		if(cnt&1)	digit[1] = !digit[1];
		for(int i=21; i>=2; i--) {
			if(!digit[i] && cnt>=(1<<(i-1))) {
				digit[i] = 1;
				cnt -= (1<<(i-1));
			}
		}
		ll ans = 0;
		for(int i=1; i<=21; i++) {
			if(digit[i])	ans += (1<<(i-1));
		}
		printf("%lld\n", ans);
	}
    return 0;
}

