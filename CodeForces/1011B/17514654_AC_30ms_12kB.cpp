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
const int maxn = 200;
const int maxm = 100000;
const int mod = 998244353;
using namespace std;

int n, m, tol, T;
int a[maxn] = {0};
int cnt[maxn] = {0};

int main() {
	scanf("%d%d", &m, &n);
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	if(m > n) {
		printf("0\n");
		return 0;
	}
	sort(a+1, a+1+n);
	int nn = unique(a+1, a+1+n) - (a+1);
//	for(int i=1; i<=nn; i++)	printf("%d%c", a[i], i==nn ? '\n' : ' ');
	int left = 1;
	int right = n / m;
	int res = 0;
	while(left <= right) {
		int mid = (left + right) >> 1;
		int ans = 0;
		for(int i=1; i<=nn; i++) {
			ans += cnt[a[i]] / mid;
			if(ans >= m)	break;
		}
		if(ans >= m){
			res = mid;
			left = mid + 1;
		}
		else	
			right = mid - 1;
	}
	printf("%d\n", res);
	return 0;
}