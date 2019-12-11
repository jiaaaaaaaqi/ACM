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
#define first fi
#define second se
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 100005;
const int maxm = 100000;
const int mod = 998244353;
using namespace std;

int n, m, tol, T;
char str[maxn];

int main() {
	scanf("%d%d", &n, &m);
	scanf("%s", str+1);
	sort(str+1, str+1+n);
	int ans = str[1] - 'a' + 1;
	char ch = str[1];
	int cnt = 1;
	for(int i=2; i<=n; i++) {
	    if(cnt == m) break;
		if(str[i] > ch + 1) {
			ans += str[i] - 'a' + 1;
			ch = str[i];
			cnt++;
		}
		if(cnt == m)	break;
	}
	if(cnt < m)	printf("-1\n");
	else	printf("%d\n", ans);
	return 0;
}