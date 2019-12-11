#include<map>
#include<set>
#include<ctime>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 250000;
const int maxm = 1e9;
const int mod = 998244353;
using namespace std;

int n, m;
int T, tol;
int a[maxn];
int b[maxn];
int s[maxn];
int p[maxn];

void init() {
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	memset(s, 0, sizeof s);
	memset(p, 0, sizeof p);
}

void handle() {
	s[0] = -2;
	s[1] = 0;
	for(int i=0; i<n; i++) {
		s[2*i+2] = a[i];
		s[2*i+3] = 0;
	}
	m = 2*n+2;
}

void manacher() {
	int id = 0, mx = 0;
	for(int i=0; i<m; i++) {
		if(mx > i)	p[i] = min(mx-i, p[2*id-i]);
		else		p[i] = 1;
		for(; s[i-p[i]] == s[i+p[i]]; p[i]++);
		if(i + p[i] > mx) {
			mx = i + p[i];
			id = i;
		}
	}
}

int main() {
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d", &n);
		for(int i=0; i<n; i++)	scanf("%d", &a[i]);
		int mxh = 1;
		b[0] = 1;
		for(int i=1; i<n; i++) {
			mxh = a[i] >= a[i-1] ? mxh+1 : 1;
			b[i] = mxh;
		}
//		for(int i=0; i<n; i++)	printf("%d%	c", b[i], i==n-1 ? '\n' : ' ');
		handle();
		manacher();
//		for(int i=0; i<m; i++)	printf("%d%c", s[i], i==m-1 ? '\n' : ' ');
//		for(int i=0; i<m; i++)	printf("%d%c", p[i], i==m-1 ? '\n' : ' ');
		for(int i=0; i<n; i++) {
			int pos = 2*i + 2;
			int ri = b[i]*2 - 1;
			p[pos] = min(p[pos]-1, ri);
			pos = 2*i + 3;
			ri = b[i]*2;
			p[pos] = min(p[pos]-1, ri);
		}
		int ans = 0;
		for(int i=0; i<m; i++)	ans = max(ans, p[i]);
		printf("%d\n", ans);
	}
	return 0;
}
