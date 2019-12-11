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
const int    maxn = 1e6 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-5;
using namespace std;

int n, m;
int cas, tol, T;

int a[maxn], q[maxn], ans[maxn];

void getMin() {
	int head, tail;
	head = 1, tail = 0;
	for(int i=1; i<=n; i++) {
		while(head<=tail && i-q[head]>=m)
			head++;
		while(head<=tail && a[i]<a[q[tail]])
			tail--;
		q[++tail] = i;
		ans[i] = a[q[head]];
	}
	for(int i=m; i<=n; i++) {
		printf("%d%c", ans[i], i==n ? '\n' : ' ');
	}
}

void getMax() {
	int head, tail;
	head = 1, tail = 0;
	for(int i=1; i<=n; i++) {
		while(head<=tail && i-q[head]>=m)
			head++;
		while(head<=tail && a[i]>a[q[tail]])
			tail--;
		q[++tail] = i;
		ans[i] = a[q[head]];
	}
	for(int i=m; i<=n; i++) {
		printf("%d%c", ans[i], i==n ? '\n' : ' ');
	}
}


int main() {
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
	}
	getMin();
	getMax();
    return 0;
}
