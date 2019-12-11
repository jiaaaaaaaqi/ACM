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
const int    maxn = 1e6 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m, p;
int cas, tol, T;

int a[maxn], b[maxn];
int s1[maxn];
int nex[maxn];

void init() {
	mes(a, 0);
	mes(b, 0);
	mes(s1, 0);
}

void make_next_table(int s[], int len) {
	mes(nex, 0);
	int i = 1, j = 0;
	nex[0] = -1;
	while(i < len) {
		if(j == -1 || s[i] == s[j])
			nex[++i] = ++j;
		else
			j = nex[j];
	}
//	for(int i=0; i<len; i++)
//		printf("%d%c", nex[i], i==len-1 ? '\n' : ' ');
}

ll kmp(int s1[], int s2[], int len1, int len2) {
	ll cnt = 0;
	int i = 0, j = 0;
	while(i < len1) {
		if(j == -1 || s1[i] == s2[j])
			i++, j++;
		else
			j = nex[j];
		if(j == len2) {
			j = nex[j];
			cnt++;
		}
	}
//	for(int i=0; i<len1; i++)
//		printf("%d%c", s1[i], i==len1-1 ? '\n' : ' ');
//	printf("!!!%d\n", cnt);
	return cnt;
}

int main() {
	cas = 1;
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d%d%d", &n, &m, &p);
		for(int i=0; i<n; i++)	scanf("%d", &a[i]);
		for(int i=0; i<m; i++)	scanf("%d", &b[i]);
		make_next_table(b, m);
		ll ans = 0;
		for(int i=0; i<p; i++) {
			int len1 = 0;
			for(int j=i; j<n; j += p)
				s1[len1++] = a[j];
			ans += kmp(s1, b, len1, m);
		}
		printf("Case #%d: %lld\n", cas++, ans);
	}
	return 0;
}
