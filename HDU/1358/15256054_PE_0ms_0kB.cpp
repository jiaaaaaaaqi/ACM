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
const int maxn = 1e6+10;
const int maxm = 1e11;
const int mod = 1e9+7;
using namespace std;

int n, m;
int T, tol;
char s[maxn];
int nex[maxn];

void init() {
	memset(s, 0, sizeof s);
}

void getnex() {
	memset(nex, 0, sizeof nex);
	nex[0] = -1;
	int i = 1;
	int j = 0;
	while(i < n) {
		if(j == -1 || s[i] == s[j]) {
			nex[++i] = ++j;
		} else {
			j = nex[j];
		}
	}
}

int main() {
	int cas = 1;
	while(scanf("%d", &n), n) {
		init();
		scanf("%s", s);
		printf("Test case #%d\n", cas++);
		getnex();
		//for(int i=0; i<n; i++)	printf("%d %c\n", nex[i], i==n-1 ? '\n' : ' ');
		for(int i=0; i<=n; i++) {
			if(nex[i] == 0 || nex[i] == -1)	continue;
			if(i%(i-nex[i]) == 0 && i/(i-nex[i]) != 1) {
				printf("%d %d\n", i, i/(i-nex[i]));
			}
		}
	}
	return 0;
}
