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
const int maxn = 100;
const int maxm = 200010;
const int mod = 998244353;
const double eps = 1e-8;
using namespace std;

ll n, m;
int T, tol;
ll ans;
int pri[maxn];
bool ispri[maxn];

void handle() {
    tol = 1;
    memset(ispri, true, sizeof ispri);
    memset(pri, 0, sizeof pri);
    for(int i=2; i<maxn; i++) {
        if(ispri[i]) {
            pri[tol++] = i;
            for(int j=2; i*j<maxn; j++) {
                ispri[i*j] = false;
            }
        }
    }
//	for(int i=1; i<tol; i++)	printf("%d%c", pri[i], i==tol-1 ? '\n' : ' ');
}

void dfs(int pos, int num, int cnt) {
	ll tmp = (ll)pow((double)n, 1.0/num+eps) - 1;
	if(!tmp)		return ;
	if(cnt & 1)		ans += tmp;
	else			ans -= tmp;
	if(cnt == 3)	return;
	for(int i=pos+1; i<=17; i++) {
		dfs(i, num * pri[i], cnt+1);
	}
}

int main() {
    handle();
    while(~scanf("%I64d", &n)) {
		ans = 0;
        for(int i=1; i<=17; i++) {
			dfs(i, pri[i], 1);
        }
		printf("%I64d\n", ans+1);
    }
    return 0;
}
