/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Wed 18 Sep 2019 05:28:14 PM CST
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

char a[maxn], b[maxn], c[maxn], d[maxn];
int A[maxn], B[maxn], C[maxn];

void jian(char *ans, char *a, char *b, int lena, int lenb, int &len) {
	for(int i=1; i<=lena; i++)	A[i] = a[lena-i+1]-'0';
	for(int i=1; i<=lenb; i++)	B[i] = b[lenb-i+1]-'0';
	// for(int i=1; i<=lena; i++)	printf("%d", A[i]);	puts("");
	// for(int i=1; i<=lenb; i++)	printf("%d", B[i]);	puts("");
	len = max(lena, lenb);
	for(int i=1; i<=len; i++)	C[i] = A[i]-B[i];
	for(int i=1; i<=len; i++)	C[i]<0 ? C[i]+=10, C[i+1]-- : C[i];
	while(len && C[len] == 0)	len--;
	for(int i=1; i<=len; i++)	ans[i] = C[len-i+1]+'0';
}

bool solve(char *a, char *b, char *c, int &ans, int lena, int lenb, int lenc) {
	mes(d, 0);
	if(lena == lenc) {
		for(int i=1; i<=lena; i++) {
			if(c[i] < a[i])	return false;
			if(c[i] > a[i])	break;
		}
	}
	int len = 0;
	jian(d, c, a, lenc, lena, len);
	if(len == 0)	return false;
	for(int i=1; i<=len; i++) {
		if(d[i] != b[i])	return false;
	}
	ans = lenb-len;
	return true;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		mes(a, 0), mes(b, 0), mes(c, 0);
		scanf("%s%s%s", a+1, b+1, c+1);
		int lena = strlen(a+1);
		int lenb = strlen(b+1);
		int lenc = strlen(c+1);
		int len  = max(max(lena, lenb), lenc);
		int ansa = len-lena;
		int ansb = len-lenb;
		int ansc = len-lenc;
		for(int i=lena+1; i<=len; i++)	a[i] = '0';
		for(int i=lenb+1; i<=len; i++)	b[i] = '0';
		for(int i=lenc+1; i<=len; i++)	c[i] = '0';
		lena = lenb = lenc = len;
		int ans = 0;
		if(solve(a, b, c, ans, lena, lenb, lenc)) {
			printf("%d %d %d\n", ansa+ans, ansb, ansc+ans);
			continue;
		} else if(solve(b, a, c, ans, lenb, lena, lenc)) {
			printf("%d %d %d\n", ansa, ansb+ans, ansc+ans);
			continue;
		}
		c[++lenc] = '0';
		ansc++;
		if(solve(a, b, c, ans, lena, lenb, lenc)) {
			printf("%d %d %d\n", ansa+ans, ansb, ansc+ans);
			continue;
		} else if(solve(b, a, c, ans, lenb, lena, lenc)) {
			printf("%d %d %d\n", ansa, ansb+ans, ansc+ans);
			continue;
		}
		printf("-1\n");
	}
	return 0;
}

