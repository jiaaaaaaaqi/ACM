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
const int mod = 10007;
using namespace std;

int n, m;
int T, tol;
char s[maxn];
int nex[maxn];

void make_next_table() {
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

int min_express(char *s) {
	int i = 0, j = 1, k = 0;
	while(i<n && j<n && k<n) {
		int t = s[(i+k)%n] - s[(j+k)%n];
		if(t == 0)	k++;
		else {
			if(t > 0)	i += k+1;
			if(t < 0)	j += k+1;
			if(i == j)	j++;
			k = 0;
		}
	}
	return min(i, j);
}

int max_express(char *s) {
	int i = 0, j = 1, k = 0;
	while(k<n) {
		int t = s[(i+k)%n] - s[(j+k)%n];
		if(t == 0)	k++;
		else {
			if(t > 0)	j += k+1;
			if(t < 0)	i += k+1;
			if(i == j)	j++;
			k = 0;
		}
	}
	return min(i, j);
}

int main() {
	while(~scanf("%s", s)) {
		n = strlen(s);
		make_next_table();
		//for(int i=0; i<=n; i++)	printf("%d%c", nex[i], i==n ? '\n' : ' ');
		int cnt = 1;
		if(n % (n-nex[n]) == 0)	cnt = n / (n-nex[n]);
		printf("%d %d %d %d\n", min_express(s)+1, cnt, max_express(s)+1, cnt);
	}
    return 0;
}
