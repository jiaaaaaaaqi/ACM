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
#define  INOPEN     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

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

int n, m;
int cas, tol, T;
vector<int> vv;
int sum[maxn];
int zero;

bool ok(int mid) {
	for(int i=1; i<=m; i++) {
		if(i+mid-1 > m)	break;
		int l = i, r = i+mid-1;
		int cnt = sum[r] - sum[l-1];
		if(cnt+zero >= mid)	return true;
	}
	return false;
}

int main() {
    scanf("%d", &T);
    while (T--) {
		vv.clear();
		zero = 0;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			int num;
			scanf("%d", &num);
			if (num == 0) zero++;
			else vv.push_back(num);
		}
		sort(vv.begin(), vv.end());
		vv.erase(unique(vv.begin(), vv.end()), vv.end());
		mes(sum, 0);
		for(int i=0; i<vv.size(); i++) {
			sum[vv[i]] = 1;
		}
		for(int i=1; i<=m; i++) {
			sum[i] += sum[i-1];
		}
		int l = 1, r = n, ans = 0;
		while(l <= r) {
			int mid = (l+r)>>1;
			if(ok(mid)) {
				l = mid+1, ans = mid;
			} else {
				r = mid-1;
			}
		}
		printf("%d\n", ans);
    }
    return 0;
}
