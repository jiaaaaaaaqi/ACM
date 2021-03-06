/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年04月01日 星期一 18时28分57秒
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

int pos;
ull Hash[maxn], nbase[maxn], seed = 131;
char s[maxn];

bool ok(int x, int mid, ull tmp) {
	for(int i=1; i<x; i++) {
		ull tmp2 = Hash[i+mid-1]-Hash[i-1]*nbase[mid];
		if(tmp2 == tmp)	{
			pos = i-1;
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d", &T);
	cas = 1;
	int mx = 1e5;
	nbase[0] = 1;
	for(int i=1; i<=mx; i++) {
		nbase[i] = nbase[i-1]*seed;
	}
	while(T--) {
		scanf("%s", s+1);
		int len = strlen(s+1);
		Hash[0] = 0;
		for(int i=1; i<=len; i++) {
			Hash[i] = Hash[i-1]*seed + (s[i]-'a');
		}
		printf("Case #%d:\n", cas++);
		printf("-1 %d\n", s[1]);
		for(int i=2; i<=len; ) {
			int l = 1, r = len-i+1, ans=0;
			pos = 0;
			while(l<=r) {
				int mid = (l+r)>>1;
				ull tmp = Hash[i+mid-1]-Hash[i-1]*nbase[mid];
				if(ok(i, mid, tmp))	l=mid+1, ans=mid;
				else	r=mid-1;
			}
			// printf("!!!pos = %d ans = %d\n", pos, ans);
			if(!ans) {
				printf("-1 %d\n", s[i]);
				i++;
			} else {
				printf("%d %d\n", ans, pos);
				i += ans;
			}
		}
	}
	return 0;
}

