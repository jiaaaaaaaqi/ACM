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
const int    maxn = 300;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int	 seed = 26;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

std::map<int, bool> mp;
char s[maxn] = {0};

void init() {
	mp.clear();
	mes(s, 0);
}

int Hash(char *s, int len) {
	if (len == 3) {
		if (s[0] != s[2])
			return -1;
	}
	if (len == 4) {
		if (s[0] != s[3] || s[1] != s[2])
			return -1;
	}
	int ans = 0;
	for (int i = 0; i < len; i++)
		ans = ans * seed + (int)(s[i] - 'a');
	return ans;
}

int main() {
	while (~scanf("%s", s)) {
		int len = strlen(s);
		int cnt = 0;
		for (int i = 0; i < len; i++) {
			if (i + 2 == len)	break;
			int ans = Hash(s + i, 3);
			if (ans == -1)	continue;
			if (mp[ans] == 0)
				cnt++;
			mp[ans] = 1;
			if (cnt >= 2)
				break;
		}
		if (cnt >= 2) {
			printf("%s\n", s);
			init();
			continue;
		}
		for (int i = 0; i < len; i++) {
			if (i + 3 == len)	break;
			int ans = Hash(s + i, 4);
			if (ans == -1)	continue;
			if (mp[ans])	continue;
			int ans1 = Hash(s + i, 3);
			if (mp[ans1])	continue;
			int ans2 = Hash(s + i + 1, 3);
			if (mp[ans2])	continue;
			cnt++;
			mp[ans] = 1;
			if(ans1 != -1)
				mp[ans1] = 1;
			if(ans2 != -1)
				mp[ans2] = 1;
			if (cnt >= 2)	break;
		}
		if (cnt >= 2) {
			printf("%s\n", s);
			init();
			continue;
		}
		init();
	}
	return 0;
}