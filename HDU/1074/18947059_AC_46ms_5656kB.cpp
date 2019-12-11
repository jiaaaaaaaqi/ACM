/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月27日 星期三 14时32分49秒
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
const int    maxn = 16;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

char s[maxn][105];
int a[maxn], b[maxn], dp[1<<maxn];
string str[1<<maxn];

void init() {
	mes(a, 0), mes(b, 0);
	mes(s, 0), mes(dp, inf);
}

int main() {
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d", &n);
		int mx = (1<<n)-1;
		for(int i=1; i<=n; i++) {
			scanf("%s%d%d", s[i]+1, &b[i], &a[i]);
		}
		dp[0] = 0;
		str[0] = "";
		for(int i=0; i<mx; i++) {
			int st = 0;
			for(int j=1; j<=n; j++) {
				if(i & (1<<(j-1)))	st += a[j];
			}
			for(int j=1; j<=n; j++) {
				if(i & (1<<(j-1)))	continue;
				int tmp = st + a[j];
				char ch = '0' + j;
				if(dp[i|(1<<(j-1))] > dp[i] + max(0, tmp-b[j])) {
					dp[i|(1<<(j-1))] = dp[i] + max(0, tmp-b[j]);
					str[i|(1<<(j-1))] = str[i] + ch;
				} else if(dp[i|(1<<(j-1))] == dp[i] + max(0, tmp-b[j])) {
					if(str[i|(1<<(j-1))] > str[i] + ch) {
						str[i|(1<<j-1)] = str[i] + ch;
					}
				}
			}
		}
		printf("%d\n", dp[mx]);
		string ss = str[mx];
		for(int i=0; i<ss.size(); i++) {
			printf("%s\n", s[ss[i]-'0']+1);
		}
	}
	return 0;
}

