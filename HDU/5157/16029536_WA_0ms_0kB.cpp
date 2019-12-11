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
	mes(a1, 0);
	mes(a2, 0);
	mes(p, 0);
}

void handle() {
	int len = strlen(s);
	str[0] = '*';
	str[1] = '#';
	for (int i = 0; i < len; i++) {
		str[2 * i + 2] = s[i];
		str[2 * i + 3] = '#';
	}
}

void manacher() {
	int id = 0;
	int mx = 0;
	int len = strlen(str);
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

void update(int pos, int val) {
	if (pos == 0)
		return ;
	for (int i = pos; i < n; i += lowbit(i))
		a1[i] += val;
}

int query(int pos) {
	if (pos == 0)
		return 0;
	int ans = 0;
	for (int i = pos; i > 0; i -= lowbit(i))
		ans += a1[i];
	return ans;
}

void update_(int pos, int val) {
	if (pos == 0)
		return ;
	for (int i = pos; i > 0; i -= lowbit(i))
		a2[i] += val;
}

int query_(int pos) {
	if (pos == 0)
		return 0;
	int ans = 0;
	for (int i = pos; i < n; i += lowbit(i))
		ans += a2[i];
	return ans;
}

int main() {
	while (~scanf("%s", s)) {
		init();
		handle();
		manacher();
		n = strlen(s) + 1;
		int len = strlen(str);
		for (int i = 1; i < len; i++) {
			if (p[i] == 1 && str[i] == '#')
				continue;
			int l = i - p[i] + 1;
			l = (l - 1) / 2;
			int r = l + p[i] - 2;
			l++;
			r++;
			int ml = (l + r) / 2;
			int mr = (l + r) / 2 + ((l + r) % 2);
			// printf("%d %d %d %d\n", l, ml, mr, r);
			update(ml, 1);
			update(l - 1, -1);
			update_(r, 1);
			update_(mr - 1, -1);
		}
		// for (int j = 1; j < n; j++)
		// 	printf("!!%d %d %d\n", j, query(j), query_(j));
		// printf("\n");
		ll ans = 0;
		ll a = 0, b = 0;
		for (int i = 1; i < n; i++) {
			b = query_(n - i);
			ans += a*b;
			a += query(i);
		}
		printf("%d\n", ans);
	}
	return 0;
}