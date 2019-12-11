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
#define lowbit(x) 	x & (-x)
#define fi			first
#define	se			second
#define INOPEM  	freopen("in.txt", "r", stdin)
#define OUTOPEN 	freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 100040;
const int    maxm = 1<<10;
const int    mod  = 1000000007;
const ll     INF  = 1e18+100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0*atan(1.0);
const double eps = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

char s[maxn];
char str[maxn << 1];
int p[maxn << 1];

void init() {
	memset(s, 0, sizeof s);
	memset(p, 0, sizeof p);
	memset(str, 0, sizeof str);
}

void handle() {
	str[0] = '$';
	str[1] = '#';
	int len = strlen(s);
	for(int i=0; i<len; i++) {
		str[2*i+2] = s[i];
		str[2*i+3] = '#';
	}
}

void manacher() {
	int len = strlen(str);
	int id = 0, mx = 0;
	for(int i=1; i<len; i++) {
		if(mx > i)	p[i] = min(p[2*id-i], mx-i);
		else	p[i] = 1;
		for(; str[i-p[i]] == str[i+p[i]]; p[i]++);
		if(p[i] + i > mx) {
			mx = p[i] + i;
			id = i;
		}
	}
}

int main() {
	init();
	while(~scanf("%s", s)) {
		handle();
		manacher();
		int left = inf;
		int len1 = strlen(s);
		int len2 = strlen(str);
		for(int i=1; i<len2; i++) {
			int l = i - p[i] + 1;
			l = (l-1) / 2;
			int r = l + (p[i]-1) - 1;
			if(r == len1 - 1) {
				left = min(left, l);
			}
//			printf("%d %d\n", l ,r);
		}
		printf("%s", s);
		for(int i=left-1; i>=0; i--)	printf("%c", s[i]);
		printf("\n");
	}
    return 0;
}
