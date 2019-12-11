#include<map>
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
const int maxn = 202000;
const int maxm = 205;
const int mod = 1000000007;
using namespace std;

int n, m, tol;
ll num[maxn];
ll pre[maxn];
ll suf[maxn];

int main() {
	scanf("%d", &n);
	memset(num, 0, sizeof num);
	memset(pre, 0, sizeof pre);
	memset(suf, 0, sizeof suf);
	for(int i=1; i<=n; i++)	scanf("%lld", &num[i]);
	for(int i=1; i<=n; i++)	pre[i] = pre[i-1] + num[i];
	for(int j=n; j>=1; j--)	suf[j] = suf[j+1] + num[j];
	int l = 1;
	int r = n;
	ll ans = 0;
	while(l < r) {
		if(pre[l] == suf[r]) {
			ans = max(ans, suf[r]);
			l++;
			r--;
		} else if(pre[l] > suf[r]) {
			r--;
		} else if(pre[l] < suf[r]) {
			l++;
		}
	}
	printf("%lld\n", ans);
}