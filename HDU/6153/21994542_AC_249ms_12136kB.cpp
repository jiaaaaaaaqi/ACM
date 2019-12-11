/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Mon 30 Sep 2019 03:23:44 PM CST
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
const int    maxn = 1e6 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

/*
 * s 是原串 t 是匹配串 下标从 0 开始
 * 求解 s 的每一个后缀和 t 的前缀的最长公共部分
 * nex[i] 表示 t[0...tlen-1] 和 t[i...tlen-1] 的最长公共部分
 * extend[i] 表示 t[0...tlen-1] 和 s[i...slen-1] 的最长公共部分
 * */
char s[maxn], t[maxn];
int nex[maxn], extend[maxn];

void getnext(char *s) {
	int i=0, j, po, len = strlen(s);
	nex[0] = len;
	while(s[i]==s[i+1] && i+1<len)	i++;
	nex[1] = i;
	po = 1;
	for(i=2; i<len; i++) {
		if(nex[i-po]+i < nex[po]+po)	nex[i] = nex[i-po];
		else {
			j = max(0, nex[po]+po-i);
			while(i+j<len && s[j+i]==s[j]) j++;
			nex[i] = j;
			po = i;
		}
	}
}

void exkmp(char *s, char *t) {
	int i=0, j, po, len1 = strlen(s), len2 = strlen(t);
	getnext(t);
	while(s[i] == t[i] && i<len1 && i<len2)	i++;
	extend[0] = i;
	po = 0;
	for(i=1; i<len1; i++) {
		if(nex[i-po]+i < extend[po]+po)	extend[i] = nex[i-po];
		else {
			j = max(0, extend[po]+po-i);
			while(i+j<len1 && j<len2 && s[j+i]==t[j]) j++;
			extend[i] = j;
			po = i;
		}
	}
}

char ss[maxn];

int main() {
	scanf("%d", &T);
	while(T--) {
		{
			scanf("%s", ss);
			int len = strlen(ss);
			for(int i=0; i<len; i++) {
				s[len-i-1] = ss[i];
			}
			s[len] = '\0';
		}
		{
			scanf("%s", ss);
			int len = strlen(ss);
			for(int i=0; i<len; i++) {
				t[len-i-1] = ss[i];
			}
			t[len] = '\0';
		}
		exkmp(s, t);
		int len = strlen(s);
		ll ans = 0;
		for(int i=0; i<len; i++) {
			int x = extend[i], y = extend[i]+1;
			if(x%2==0)	x/=2;
			else	y/=2;
			ans = (ans + 1ll*x*y%mod)%mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
