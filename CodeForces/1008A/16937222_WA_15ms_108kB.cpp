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
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

char s[maxn];

int ok(char c) {
	if(c == 'a')	return 1;
	if(c == 'e')	return 1;
	if(c == 'i')	return 1;
	if(c == 'o')	return 1;
	if(c == 'u')	return 1;
	if(c == 'n')	return 1;
	return 0;
}

int main() {
	scanf("%s", s+1);
	int len = strlen(s+1);
	if(!ok(s[len])) {
		printf("NO\n");
		return 0;
	}
	for(int i=1; i<len; i++) {
		if(!ok(s[i]) && !ok(s[i+1])) {
			printf("NO\n");
		}
	}
	printf("YES\n");
	return 0;
}