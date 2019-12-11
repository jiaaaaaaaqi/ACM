/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年05月22日 星期三 18时17分02秒
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

char s[maxn];
int a[maxn], sa[maxn], rk[maxn], tax[maxn], height[maxn], tp[maxn];

void rsort(int n, int m) {
	for(int i=0; i<=m; i++)	tax[i] = 0;
	for(int i=1; i<=n; i++)	tax[rk[tp[i]]]++;
	for(int i=1; i<=m; i++)	tax[i] += tax[i-1];
	for(int i=n; i>=1; i--)	sa[tax[rk[tp[i]]]--] = tp[i];
}

int cmp(int *f, int x, int y, int w) {
	return f[x]==f[y] && f[x+w]==f[y+w];
}

void SA(int *a, int n, int m) {
	for(int i=1; i<=n; i++)	rk[i] = a[i], tp[i] = i;
	rsort(n, m);
	for(int w=1, p=1, i; p<n; w<<=1, m=p) {
		for(p=0, i=n-w+1;i<=n; i++)	tp[++p] = i;
		for(i=1; i<=n; i++)	if(sa[i]>w)	tp[++p] = sa[i]-w;
		rsort(n, m), swap(tp, rk);
		rk[sa[1]] = p = 1;
		for(i=2; i<=n; i++)	rk[sa[i]] = cmp(tp, sa[i], sa[i-1], w) ? p : ++p;
	}
	int j, k=0;
	for(int i=1; i<=n; height[rk[i++]] = k)
		for(k=k ? k-1 : k, j=sa[rk[i]-1]; a[i+k]==a[j+k]; k++);
}

int main() {
	scanf("%s", s+1);
	n = strlen(s+1);
	for(int i=1; i<=n; i++) {
		a[i] = s[i];
	}
	SA(a, n, 260);
	// for(int i=1; i<=n; i++) {
	//     printf("sa[%d] = %d height[%d] = %d\n", i, sa[i], i, height[i]);
	// }
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &m);
		for(int i=1; i<=n; i++) {
			if(m > n-sa[i]+1-height[i]) {
				m -= (n-sa[i]+1-height[i]);
			} else {
				int last = sa[i] + height[i] - 1;
				last += m;
				// printf("%d %d\n", sa[i], last);
				for(int j=sa[i]; j<=last; j++) {
					printf("%c", s[j]);
				}
				printf("\n");
				break;
			}
		}
	}
	return 0;
}

