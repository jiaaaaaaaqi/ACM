/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年05月22日 星期三 19时40分05秒
 ***************************************************************/

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

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 2e5 + 10;
const int    maxm = 1e5 + 10;
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
	int cnt, id;
	Node() {
		cnt = id = 0;
	}
} node[maxn];
int a[maxn], bel[maxn];

int read() {
	int x=0, f=1;
	char s=getchar();
	while(s<'0' || s>'9') {
		if(s=='-')	f=-1;
		s=getchar();
	}
	while(s>='0'&&s<='9') {
		x=x*10+s-'0';
		s=getchar();
	}
	return x*f;
}

void output(int x) {
	if(x>9)	output(x/10);
	putchar(x%10+'0');
}

int L(int x) {
	return (x-1)*block+1;
}

void update(int p, int v) {
	a[p] = v;
	int l = L(bel[p]);
	for(int i=p; i>=l; i--) {
		int r = i+a[i];
		if(r > n) {
			node[i].cnt = 1;
			node[i].id = n+1;
		} else if(bel[i] == bel[r]) {
			node[i].cnt = node[r].cnt+1;
			node[i].id = node[r].id;
		} else {
			node[i].cnt = 1;
			node[i].id = r;
		}
	}
}

int query(int x) {
	int ans = 0;
	while(x <= n) {
		ans += node[x].cnt;
		x = node[x].id;
	}
	return ans;
}

int main() {
	n = read();
	block = sqrt(1.0*n);
	for(int i=1; i<=n; i++) {
		a[i] = read();
		bel[i] = (i-1)/block + 1;
	}
	for(int i=n; i>=1; i--) {
		int r = i+a[i];
		if(r > n) {
			node[i].cnt = 1;
			node[i].id = n+1;
		} else if(bel[i] == bel[r]) {
			node[i].cnt = node[r].cnt+1;
			node[i].id = node[r].id;
		} else {
			node[i].cnt = 1;
			node[i].id = r;
		}
	}
	scanf("%d", &T);
	while(T--) {
		int id, x, y;
		id = read();
		if(id == 1) {
			x = read();
			int ans = query(x+1);
			output(ans);
			printf("\n");
		} else {
			x = read();
			y = read();
			update(x+1, y);
		}
	}
	return 0;
}

