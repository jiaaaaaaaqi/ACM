/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月18日 星期一 16时07分55秒
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
const int    maxn = 2e1 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

double f[10] = {
	0.1, 0.01, 0.001, 0.0001, 0.00001, 0.000001
};
double l[maxn], r[maxn];

void get(int id) {
	char s[maxn];
	scanf("%s", s+1);
	int len = strlen(s+1);
	int pos = -1;
	double ans = 0.0;
	for(int i=1; i<=len; i++) {
		if(s[i] == '.') {
			pos = i;
			break;
		}
		ans = ans*10 + s[i]-'0';
	}
	int d;
	if(pos != -1) {
		for(int i=pos+1, j=0; i<=len; i++, j++) {
			ans = ans + f[j]*(s[i]-'0');
		}
		d = len-pos;
	} else {
		d = 0;
	}
	l[id] = ans - f[d]*5 - eps;
	r[id] = ans + f[d]*5 - eps;
}

bool ok(int x) {
	int ls, rs;
	ls = rs = 0;
	for(int i=1; i<=n; i++) {
		ls += (int)ceil(l[i]*x/100);
		rs += (int)floor(r[i]*x/100);
	}
	// cout << ls << endl;
	// cout << rs << endl;
	return ls<=x && x<=rs;
}

int main() {
	cas = 1;
	while(scanf("%d", &n), n) {
		for(int i=1; i<=n; i++) {
			get(i);
		}
		int ans = -1;
		for(int i=1; i<=9999; i++) {
			if(ok(i)) {
				ans = i;
				break;
			}
		}
		printf("Case %d: ", cas++);
		if(ans != -1)	printf("%d\n", ans);
		else	printf("error\n");
	}
	return 0;
}

