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

int block;
struct Node{
	int l, r;
	int id;
	bool operator < (Node a) const {
		return l/block==a.l/block ? r<a.r : l/block<a.l/block;
	}
} node[maxn<<1];
int a[maxn], vis[maxm], res[maxn<<1];
int ans;

void add(int x) {
	vis[a[x]]++;
	if(vis[a[x]] == 1)	ans++;
}

void del(int x) {
	vis[a[x]]--;
	if(vis[a[x]] == 0)	ans--;
}

int main() {
	scanf("%d", &n);
	block = sqrt(1.0*n);
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for(int i=1; i<=m; i++) {
		scanf("%d%d", &node[i].l, &node[i].r);
		node[i].id = i;
	}
	sort(node+1, node+1+m);
	ans = 0;
	int L, R;
	L = 1, R = 0;
	for(int i=1; i<=m; i++) {
		int l = node[i].l, r = node[i].r, id = node[i].id;
		while(L > l)	add(--L);
		while(R < r)	add(++R);
		while(L < l)	del(L++);
		while(R > r)	del(R--);
		res[id] = ans;
	}
	for(int i=1; i<=m; i++)	printf("%d\n", res[i]);
	return 0;
}
