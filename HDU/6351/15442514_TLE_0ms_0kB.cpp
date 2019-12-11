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
const int maxn = 50;
const int maxm = 200010;
const int mod = 998244353;
const double eps = 1e-8;
using namespace std;

int n, m;
int T, tol;
int p[maxn];
char s[maxn];
bool vis[maxn];

void init() {
	memset(p, 0, sizeof p);
	memset(s, 0, sizeof s);
	memset(vis, 0, sizeof vis);
}

int count(int len) {
	int ans = 0;
	memset(vis, 0, sizeof vis);
	for(int i=0; i<len; i++) {
		if(vis[i])	continue;
		int tmp = 0;
		while(!vis[i]) {
			tmp++;
			vis[i] = true;
			i = p[i];
		}
		ans += tmp-1;
		if(ans > m)	return -1;
	}
	return ans;
}

int main() {
    scanf("%d", &T);
    while(T--) {
		init();
		scanf("%s%d", s, &m);
		int len = strlen(s);
		for(int i=0; i<len; i++)	p[i] = i;
		int mn = inf, mx = -1;
		do{
//			for(int i=0; i<len; i++)	printf("%d%c", p[i], i==len-1 ? '\n' : ' ');
			if(s[p[0]] == '0' || count(len) == -1)	continue;
			int tmp = 0;
			for(int i=0; i<len; i++)
				tmp = tmp * 10 + (s[p[i]] - '0');
			mn = min(mn, tmp);
			mx = max(mx, tmp);
		}while(next_permutation(p, p+len));
		printf("%d %d\n", mn, mx);
    }
    return 0;
}
