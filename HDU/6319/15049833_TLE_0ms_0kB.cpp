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
const int maxn = 10000005;
const int maxm = 1000005;
using namespace std;

int T, tol;
int n, m;
ll a[maxn];
int que[maxn];

void init() {
	memset(a, 0, sizeof a);
}

int main() {
	scanf("%d", &T);
	while(T--) {
		int k;
		ll p, q, r, mod;
		scanf("%d %d %d %I64d %I64d %I64d %I64d", &n, &m, &k, &p, &q, &r, &mod);
		for(int i=1; i<=k; i++)	scanf("%lld", &a[i]);
		for(int i=k+1; i<=n; k++)	a[i] = (p*a[i-1] + q*i + r) % mod;
		int head, tail;
		head = tail = 0;
		for(int i=n; i>n-m+1; i--) {
			while(head != tail && a[i] >= a[que[tail-1]])	tail--;
			que[tail++] = i;
		}
		ll ans1 = 0;
		ll ans2 = 0;
		for(int i=n-m+1; i>=1; i--) {
			while(head != tail && a[i] >= a[que[tail-1]])	tail--;
			que[tail++] = i;
			while(i + m - 1 < que[head])	head++;
			/*
			for(int j=head; j<tail; j++)	printf("%d %d %lld\n", i, que[j], a[que[j]]);
			printf("\n");
			*/
			ans1 += (a[que[head]] ^ i);
			ans2 += ((tail - head) ^ i);
		}
		printf("%lld %lld\n", ans1, ans2);
	}
	return 0;
}

/*
3 2 2 1 5 7 6 8 2 9
7 7 8 8 9
3 3 4 4 4
*/

