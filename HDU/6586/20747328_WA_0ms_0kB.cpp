/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年07月25日 星期四 09时41分20秒
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

char s[maxn], t[maxn];
int nex[maxn][27], sum[maxn][27];
int l[27], r[27], cnt[27];

bool ok(char *s, int p, int remain) {
	for(int i=1; i<=26; i++) {
		if(cnt[i] + sum[p][i] < l[i])	return false;
		if(remain + cnt[i] < l[i])	return false;
		if(cnt[i] > r[i])	return false;
	}
	return true;	
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%s%d", s+1, &m);
	n = strlen(s+1);
	for(int i=1; i<=26; i++) {
		scanf("%d%d", &l[i], &r[i]);
		nex[n][i] = -1;
		sum[n][i] = 0;
	}
	for(int i=n-1; i>=0; i--) {
		for(int j=1; j<=26; j++) {
			nex[i][j] = nex[i+1][j];
			sum[i][j] = sum[i+1][j];
		}
		nex[i][s[i+1]-'a'+1] = i+1;
		sum[i][s[i+1]-'a'+1]++;
	}
	int p = 0;
	for(int i=1; i<=m; i++) {
		// printf("before p = %d\n", p);
		bool flag = true;
		for(int j=1; j<=26; j++) {
			if(nex[p][j] == -1)	continue;
			t[i] = j+'a'-1;
			cnt[j]++;
			if(ok(t, nex[p][j], m-i)) {
				p = nex[p][j];
				flag = false;
				break;
			}
			cnt[j]--;
		}
		// printf("after p = %d\n", p);
		if(flag) {
			printf("-1\n");
			return 0;
		}
	}
	printf("%s\n", t+1);
	return 0;
}

