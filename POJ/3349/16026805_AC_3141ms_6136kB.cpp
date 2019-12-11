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
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;
int a1[10];
int a2[10];
ull seed = 131;
std::map<ull, int> mp;

inline int read()
{
	int X = 0, w = 0; char ch = 0;
	while (!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
	return w ? -X : X;
}

int min_express(int a[]) {
	int i = 0, j = 1, k = 0;
	int n = 6;
	while (i < n && j < n && k < n) {
		int t = a[(i + k) % n] - a[(j + k) % n];
		if (t == 0) {
			k++;
		} else {
			if (t > 0)	i += k + 1;
			else		j += k + 1;
			if (i == j)	j++;
			k = 0;
		}
	}
	return i > j ? j : i;
}

int check(int pos1, int pos2) {
	int cnt = 6;
	while (cnt--) {
		if (a1[pos1] == a2[pos2]) {
			pos1++;
			pos2++;
			if (pos1 == 6)	pos1 = 0;
			if (pos2 == 6)	pos2 = 0;
		} else {
			if (a1[pos1] < a2[pos2])
				return 0;
			else
				return 1;
		}
	}
}

int main() {
	scanf("%d", &n);
	bool flag = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 6; j++) {
			a1[j] = read();
			a2[5 - j] = a1[j];
		}
		if (flag)	continue;
		int pos1 = min_express(a1);
		int pos2 = min_express(a2);
		int id = check(pos1, pos2);
		ull ans = 0;
		if (id == 0) {
			for (int j = pos1, cnt = 0; cnt < 6; cnt++, j++) {
				ans = ans * seed + a1[j];
				if (j == 5)
					j = -1;
			}
		} else {
			for (int j = pos2, cnt = 0; cnt < 6; cnt++, j++) {
				ans = ans * seed + a2[j];
				if (j == 5)
					j = -1;
			}
		}
		if (mp[ans] == 1) {
			flag = true;
			break;
		} else {
			mp[ans] = 1;
		}
	}
	if (flag)
		printf("Twin snowflakes found.\n");
	else
		printf("No two snowflakes are alike.\n");
	return 0;
}