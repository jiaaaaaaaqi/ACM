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
const int maxn = 1000005;
const int maxm = 1e11;
const int mod = 10007;
using namespace std;

int n, m;
int T, tol;
char s[maxn];
int a[maxn];
int nex[maxn];

void init() {
	tol = 0;
	memset(a, 0, sizeof a);
	memset(nex, 0, sizeof nex);
}

void make_next_table() {
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
	scanf("%d", &T);
	while(T--) {
		init();		
		scanf("%s", s);
		n = strlen(s);
		make_next_table();
		//for(int i=0; i<=n; i++)	printf("%d%c", nex[i], i==n ? '\n' : ' ');
		for(int j=n; j; j=nex[j]) {
			a[++tol] = n - nex[j];
		}
		sort(a+1, a+1+tol);
		printf("Case #%d: %d\n", cas++, tol);
		for(int i=1; i<=tol; i++)	printf("%d%c", a[i], i==tol ? '\n' : ' ');
	}
    return 0;
}
