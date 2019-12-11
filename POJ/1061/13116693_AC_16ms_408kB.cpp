#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

long long int e_gcd(long long int a, long long int b, long long int &x, long long int &y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	} else {
		long long int ans=e_gcd(b, a%b, x, y);
		long long int temp;
		temp = x - a / b * y;
		x = y;
		y = temp;
		return ans;
	}
}

int main() {
	long long int a,b,m,n,l;
	while(scanf("%lld%lld%lld%lld%lld", &a, &b, &m, &n, &l) != EOF) {
		long long int x,y;
		long long int gcd=e_gcd(n-m, l, x, y);
		long long int r = l/gcd;
		if((a-b) % gcd) {
			printf("Impossible\n");
		}else {
			long long int ans = ((a-b)/ gcd * x %r + r)%r;
			printf("%lld\n", ans);
		}
	}
	return 0;
}