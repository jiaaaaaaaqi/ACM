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

int n, m, k;
int cas, tol, T;

int main() {
	scanf("%d", &T);
	while(T--) {
		priority_queue<int, vector<int>, greater<int>> q;
		scanf("%d%d%d", &n, &m, &k);
		for(int i=1, x; i<=n; i++) {
			scanf("%d", &x);
			q.push(x);
		}
		tol = n-m;
		while(tol) {
			int mx = 0;
			if(!q.empty()) {
				mx = q.top();
				q.pop();
			}
			if(!q.empty()) {
				mx = max(mx, q.top());
				q.pop();
			}
			q.push(mx+k);
			tol--;
		}
		while(q.size() > 1)	q.pop();
		printf("%d\n", q.top());
	}
	return 0;
}
