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
const int maxn = 2500000;
const int maxm = 1e11;
const int mod = 10007;
using namespace std;

int n, m;
int T, tol;
char s[maxn];
char str[maxn];
int p[maxn];

void init() {
	memset(s, 0, sizeof s);
	memset(str, 0, sizeof str);
	memset(p, 0, sizeof p);
}

void handle() {
	int len = strlen(s);
	str[0] = '$';
	str[1] = '#';
	for(int i=0; i<len; i++) {
		str[2*i+2] = s[i];
		str[2*i+3] = '#';
	}
	//printf("%s\n", str);
}

void manacher() {
	int id = 0, mx = 0;
	int len = strlen(str);
	for(int i=1; i<len; i++) {
		if(mx > i)	p[i] = min(mx-i, p[2*id-i]);
		else	p[i] = 1;
		for(; str[i-p[i]] == str[i+p[i]]; p[i]++);
		if(p[i] + i > mx) {
			mx = p[i] + i;
			id = i;
		}
	}	
}

int main() {
	int cas = 1;
	while(1) {
		init();
		scanf("%s", s);
		if(strcmp(s, "END") == 0)	break;
		handle();
		manacher();
		int ans = -1;
		int len = strlen(str);
		for(int i=0; i<len; i++)	ans = max(ans, p[i]-1);
		printf("Case %d: %d\n", cas++, ans);
	}
    return 0;
}
