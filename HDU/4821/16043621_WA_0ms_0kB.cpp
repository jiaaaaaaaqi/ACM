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

ull seed = 131;
char s[maxn];
ull fp[maxn];
ull Hash[maxn];
std::map<ull, int> mp;

int main() {
	fp[0] = 1;
	for (int i = 1; i < maxn; i++)
		fp[i] = fp[i - 1] * seed;
	while (~scanf("%d%d", &n, &m)) {
		mes(Hash, 0);
		mes(s, 0);
		scanf("%s", s);
		int len = strlen(s);
		Hash[len] = 0;
		for (int i = len - 1; i >= 0; i--)
			Hash[i] = Hash[i + 1] * seed + s[i] - 'a';
		int ans = 0;
		for (int i = 0; i < m && i + n * m <= len; i++) {
			mp.clear();
			ull tmp;
			for (int j = i; j + m <= len; j += m) {
				tmp = Hash[j] - Hash[j + m] * fp[m];
				mp[tmp]++;
			}
			if (mp.size() == n)	ans++;
			for (int j = i + n * m; j + m <= len; j += m) {
				tmp = Hash[j - n * m] - Hash[j - n * m + m] * fp[m];
				mp[tmp]--;
				if (mp[tmp] == 0)
					mp.erase(tmp);
				tmp = Hash[j] - Hash[j + m] * fp[m];
				mp[tmp]++;
				if (mp.size() == n)	ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}