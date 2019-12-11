#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define  lowbit(x)	x & (-x)
#define  mes(a, b)	memset(a, b, sizeof a)
#define  fi 		first
#define  se 		second
#define  INOPEM		freopen("in.txt", "r", stdin)
#define  OUTOPEN	freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 100005;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

ll a1[maxn << 1];
ll a2[maxn << 1];
char s[maxn << 1];
int p[maxn << 1];
char str[maxn << 1];

void init() {
	for(int i=0; i<=n; i++)
		a1[i] = a2[i] = 0;
}

void handle(int len) {
	str[0] = '*';
	str[1] = '#';
	for (int i = 0; i < len; i++) {
		str[2 * i + 2] = s[i];
		str[2 * i + 3] = '#';
	}
}

void manacher(int len) {
	int id = 0;
	int mx = 0;
	for (int i = 1; i < len; i++) {
		if (mx > i)
			p[i] = min(mx - i, p[2 * id - i]);
		else
			p[i] = 1;
		for (; str[i - p[i]] == str[i + p[i]]; p[i]++);
		if (i + p[i] > mx) {
			id = i;
			mx = i + p[i];
		}
	}
}

int main() {
	while (~scanf("%s", s)) {
		n = strlen(s);
		handle(n);
		manacher(n * 2 + 1);
		init();
		int len = strlen(str);
		for (int i = 1; i < len; i++) {
			if (p[i] == 1 && str[i] == '#')
				continue;
			int l = i - p[i] + 1;
			l = (l - 1) / 2;
			int r = l + p[i] - 2;
			int ml = (l + r) / 2;
			int mr = (l + r) / 2 + ((l + r) % 2);
			a1[ml+1]--;
			a1[l]++;
			a2[r+1]--;
			a2[mr]++;
		}
		ll ans = 0;
		ll sum = a2[0];
		for(int i=1; i<n; i++) {
			a1[i] = a1[i-1] + a1[i];
			ans += sum * a1[i];
			a2[i] = a2[i-1] + a2[i];
			sum += a2[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}