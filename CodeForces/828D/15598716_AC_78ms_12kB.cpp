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
#define INOPEM freopen("in.txt", "r", stdin)
#define OUTOPEN freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 10005;
const int maxm = 250;
const int mod = 1e9+7;
using namespace std;

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	/*
	if ((n-1) % k == 0) printf("%d\n", 2*((n-1)/k);
	else if ((n-1) % k == 1) printf("%d\n",2*((n-1)/k+1)+1);
	else printf("%d\n", 2*((n-1)/k+1)+2);
	*/
	int tmp = (n-1) / k;
	int ans;
	if((n-1) % k == 0)
		ans = tmp * 2;
	else if((n-1) % k == 1) {
		ans = tmp+tmp+1;
	} else {
		tmp++;
		ans = tmp*2;
	}
	printf("%d\n", ans);
	for (int i = 1; i <= k; i++) {
		printf("%d %d\n", 1, i+1);
	}
	for (int i = k+2; i <= n; i++) {
		printf("%d %d\n", i-k, i);
	}
	return 0;
}