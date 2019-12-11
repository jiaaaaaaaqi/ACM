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
const int maxn = 420000;
const int maxm = 1e11;
const int mod = 10007;
using namespace std;

int n, m;
int T, tol;
int p[maxn];
char s[maxn];
char str[maxn];

void init() {
	memset(s, 0, sizeof s);
	memset(p, 0, sizeof p);
	memset(str, 0, sizeof str);
}

void handle() {
	int len = strlen(s);
	str[0] = '$';
	str[1] = '#';
	for(int i=0; i<len; i++) {
		str[i*2+2] = s[i];
		str[i*2+3] = '#';
	}
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
	char ch[10];
	while(~scanf("%s", ch)) {
		init();
		int x = ch[0] - 'a';
		scanf("%s", s);
		int len = strlen(s);
		for(int i=0; i<len; i++) {
			s[i] = s[i] - x;
			if(s[i] < 'a')	s[i] += 26;	
			if(s[i] > 'z')	s[i] -= 26;
		}
		handle();
		manacher();
		int ans = -1;
		int pos = 0;
		len = strlen(str);
		for(int i=0; i<len; i++) {
			if(p[i] > ans) {
				ans = p[i];
				pos = i;
			}
		}
		ans--;
		//printf("%d %d\n", pos, ans);
		if(ans == 1) {
			printf("No solution!\n");
		} else {
			int st = pos - ans - 1;
			st = (st - 1) / 2;
			int ed = st + ans - 1;
			printf("%d %d\n", st, ed);
			for(int i=st; i<=ed; i++)	printf("%c", s[i]);
			printf("\n");
		}
	}
	return 0;
}
