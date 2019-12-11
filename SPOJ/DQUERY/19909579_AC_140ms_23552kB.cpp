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
const int    maxm = 1e6 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Node {
	int l, r;
	int id;
	bool operator < (Node a) const {
		return r < a.r;
	}
} node[maxn<<1];
int a[maxn], last[maxm], res[maxn<<1], sum[maxn];

void update(int pos, int val) {
	for(int i=pos; i<=n; i+=lowbit(i))
		sum[i] += val;
}

int query(int pos) {
	int ans = 0;
	for(int i=pos; i>=1; i-=lowbit(i))
		ans += sum[i];
	return ans;
}

int main() {
	scanf("%d", &n);
	mes(last, -1);
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for(int i=1; i<=m; i++) {
		scanf("%d%d", &node[i].l, &node[i].r);
		node[i].id = i;
	}
	sort(node+1, node+1+m);
	int j = 1;
	for(int i=1; i<=n; i++) {
		if(last[a[i]] == -1) {
			update(i, 1);
		} else {
			update(last[a[i]], -1);
			update(i, 1);
		}
		last[a[i]] = i;
		while(i == node[j].r) {
			res[node[j].id] = query(node[j].r) - query(node[j].l-1);
			j++;
		}
	}
	for(int i=1; i<=m; i++)	printf("%d\n", res[i]);
	return 0;
}
