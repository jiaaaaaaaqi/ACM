#include<map>
#include<queue>
#include<string>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define inf 0x3f3f3f3f

typedef long long int ll;
using namespace std;

const int maxn = 4005;

ll a[maxn];
ll b[maxn];
ll c[maxn];
ll d[maxn]; 
ll ans1[maxn * maxn];
ll ans2[maxn * maxn];

int main() {
	int n;
	while(~scanf("%d", &n)) {
		for(int i=0; i<n; i++) {
			scanf("%lld%lld%lld%lld", &a[i], &b[i], &c[i], &d[i]);
		}
		int tol1 = 0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				ans1[tol1++] = a[i] + b[j];
			}
		}
		int tol2 = 0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				ans2[tol2++] = c[i] + d[j];
			}
		}
		sort(ans1, ans1+tol1);
		sort(ans2, ans2+tol2);
		/*
		for(int i=0; i<tol1; i++) {
			printf("!!%d\n", ans1[i]);
		}
		for(int i=0; i<tol2; i++) {
			printf("!!!!%d\n", ans2[i]);
		}
		*/
		ll res = 0;
		for(int i=0; i<tol1; i++) {
			ll ans = 0 - ans1[i];
			int k1 = lower_bound(ans2, ans2+tol2, ans) - ans2;
			int k2 = upper_bound(ans2, ans2+tol2, ans) - ans2;
				res += k2 - k1;
		}
		printf("%lld\n", res);
	}
	return 0;	
}