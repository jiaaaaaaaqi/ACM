
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
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Node{
	int l, r;
	int sum;
} node[maxn * 50];
vector<int> vec;
int a[maxn];
int rt[maxn];

void init() {
	tol = 0;
	vec.clear();
	mes(rt, 0);
}

int getid(int x) {
	return lower_bound(vec.begin(), vec.end(), x) - vec.begin() +1;
}

void update(int l, int r, int &x, int y, int pos) {
	tol++;
	node[tol] = node[y];
	node[tol].sum++;
	x = tol;
	if(l == r)	return ;
	int mid = (l + r) >> 1;
	if(pos <= mid) 
		update(l, mid, node[x].l, node[y].l, pos);
	else
		update(mid+1, r, node[x].r, node[y].r, pos);
}

int query(int l, int r, int x, int y, int k) {
	if(l == r) {
		return l;
	}
	int mid = (l + r) >> 1;
	int sum = node[node[y].l].sum - node[node[x].l].sum;
	if(sum >= k) 
		return query(l, mid, node[x].l, node[y].l, k);
	else
		return query(mid+1, r, node[x].r, node[y].r, k - sum);
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		init();
		int x;
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
			vec.push_back(a[i]);
		}
		sort(vec.begin(), vec.end());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());
		for(int i=1; i<=n; i++) {
			update(1, n, rt[i], rt[i-1], getid(a[i]));
		}
		int l, r, k;
		while(m--) {
			scanf("%d%d%d", &l, &r, &k);
			int pos = query(1, n, rt[l-1], rt[r], k) - 1;
			printf("%d\n", vec[pos]);
		}
	}
	return 0;
}