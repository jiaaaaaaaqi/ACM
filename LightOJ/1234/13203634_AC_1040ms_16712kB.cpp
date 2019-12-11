#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const long long int maxn = 1e8;

double num[maxn/50+10];

void handle() {
	memset(num, 0, sizeof(num));
	num[0] = 0.0;
	int tol = 1;
	double pre;
	double ans = 0.0;
	for(int i=1; i<=maxn; i++) {
		pre = 1.0 / i;
		ans += pre;
		if(i%50 == 0)
			num[tol++] = ans;
	}
}

int main() {
	handle();
	int T;
	int cas = 1;
	scanf("%d", &T);
	while(T--) {
		long long int n;
		scanf("%lld", &n);
		int x = n / 50;
		double ans = 0;
		ans = num[x];
		for(int i=50*x+1; i<=n; i++) {
			double pre = 1.0/i;
			ans += pre;
		}
		printf("Case %d: %.10lf\n", cas++, ans);
	}
	return 0;
}