/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月09日 星期六 00时28分49秒
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
const int    maxn = 1e2 + 10;
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
int dp[maxn][maxn], p[maxn][maxn];

bool ok(char s1, char s2) {
	if(s1 == '(' && s2 == ')')	return true;
	if(s1 == '[' && s2 == ']')	return true;
	return false;
}

void out(int l, int r) {
	if(l > r)	return ;
	if(l == r) {
        if(s[l] == '(' || s[l] == ')')
            printf("()");
        else
            printf("[]");
        return ;
	}
	if(p[l][r] == -1) {
		printf("%c", s[l]);
		out(l+1, r-1);
		printf("%c", s[r]);
	} else {
		int mid = p[l][r];
        out(l, mid);
        out(mid+1, r);
	}
}

int main() {
    scanf("%s", s+1);
	mes(p, 0);
	n = strlen(s+1);
	mes(p, 0);
	for(int i=1; i<=n; i++) {
		dp[i][i] = 1;
	}
	for(int d=2; d<=n; d++) {
		for(int i=1, j=d; j<=n; i++, j++) {
			dp[i][j] = inf;
			if(ok(s[i], s[j])) {
				dp[i][j] = dp[i+1][j-1];
				p[i][j] = -1;
			}
			for(int k=i; k<j; k++) {
				if(dp[i][j] > dp[i][k]+dp[k+1][j]) {
					dp[i][j] = dp[i][k] + dp[k+1][j];
					p[i][j] = k;
				}
			}
		}
	}
	//cout << p[1][n] << endl;
	out(1, n);
	cout << endl;
	return 0;
}
