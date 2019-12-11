/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Wed 18 Sep 2019 01:50:00 PM CST
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
#include <unordered_map>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pb         push_back
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

int n, m, q;
int cas, tol, T;

char s[maxn], t[maxn];
ll k;
ll dp[maxn][30];
int vv[maxn], base[maxn];

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &n, &m, &q);
		scanf("%s", s+1);
		int now = 0, cnt = 0;
		for(int i=1; i<=n; i++) {
			now = (now*10+(s[i]=='?' ? 0 : s[i]-'0'))%m;
			if(s[i] == '?')	vv[++cnt] = i;
		}
		base[n] = 1;
		for(int i=n-1; i>=1; i--) {
			base[i] = base[i+1]*10%m;
		}
		for(int i=1; i<=cnt; i++) {
			for(int j=0; j<m; j++) {
				dp[i][j] = 0;
			}
		}
		int endpos = 0;
		for(int i=cnt, p=0; i>=1&&p<=30; i--, p++) {
			int pos = vv[i];
			endpos = i;
			for(int x=0; x<=9; x++) {
				for(int j=0; j<m; j++) {
					dp[i][(x*base[pos]+j)%m] += dp[i+1][j];
				}
				if(i == cnt)	dp[i][x*base[pos]%m]++;
			}
		}
		for(int i=0; i<m; i++)	dp[cnt+1][i] = 1;
		int need = (m-now)%m;
		while(q--) {
			scanf("%lld", &k);
			if(endpos == 0) {
				if(now == 0 && k==1)	printf("%s\n", s+1);
				else	printf("-1\n");
			} else {
				if(dp[endpos][need] >= k) {
					for(int i=1; i<=n; i++) {
						if(s[i]!='?' || (s[i]=='?'&&i<vv[endpos])) {
							t[i] = s[i]=='?' ? '0' : s[i];
						}
					}
					for(int i=endpos; i<=cnt; i++) {
						// printf("%d %d\n", i, k);
						for(int x=0; x<=9; x++) {
							int tmp = (need - (x*base[vv[i]]%m)+m)%m;
							if(dp[i+1][tmp] >= k) {
								if(i==cnt && tmp)	continue;
								t[vv[i]] = x+'0';
								need = tmp;
								break;
							} else {
								k -= dp[i+1][tmp];
							}
						}
					}
					printf("%s\n", t+1);
				} else {
					printf("-1\n");
				}
			}
		}
	}
	return 0;
}

