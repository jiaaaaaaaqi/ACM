/*************************************************************** 
	> File Name		: a.cpp
	> Author		: Jiaaaaaaaqi
	> Created Time	: Tue 12 Nov 2019 04:58:09 PM CST
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
#include <unordered_map>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pb         push_back
#define  pii        pair<int, int>

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 5e3 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int aa[maxn];
int a[maxn], b[maxn];
int vis[maxn], pre[maxn];
ull has[maxn][maxn], seed = 233;

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		for(int i=1; i<=n; i++)	scanf("%d", &aa[i]);
		int len1 = 0, len2 = 0;
		for(int i=1; i<=n; i++) {
			if(n==0 || aa[i]!=a[len1])	a[++len1] = aa[i];
		}
		for(int i=1; i<=n; i++)	vis[i] = pre[i] = 0;
		for(int i=1; i<=n; i++) {
			pre[i] = pre[i-1];
			if(vis[a[i]] == 0)	pre[i]++;
			vis[a[i]]++;
		}
		for(int i=n; i>=1; i--) {
			for(int j=1; j<=n; j++)	vis[j] = 0;
			int cnt = 0;has[i][0] = 0;
			for(int j=i; j>=1; j--) {
				if(vis[a[j]] == 0) {
					cnt++;
					has[i][cnt] = has[i][cnt-1] * seed + a[j];
				}
				vis[a[j]]++;
			}
		}
		while(m--) {
			scanf("%d", &len2);
			for(int i=1; i<=len2; i++)	scanf("%d", &b[i]);
			bool flag = 0;
			while(len2 && b[len2] == 0)	len2--, flag = 1;
			if(len2 == 0) {
				printf("Yes\n");
				continue;
			}
			ull ans = 0;for(int i=1; i<=len2; i++)	ans = ans*seed+b[i];
			int pos = 0;
			for(int i=1; i<=len1; i++) {
				if(has[i][len2] == ans) {
					pos = i;
					break;
				}
			}
			if(pos && (!flag || (flag && pre[pos]==len2)))	printf("Yes\n");
			else	printf("No\n");
		}
	}
	return 0;
}

